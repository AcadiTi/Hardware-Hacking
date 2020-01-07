#!/usr/bin/python

# Custom portal upload utility to be used with WiNX and WiNX Portable's custom deception firmware
# This reads HTML file passed to it and upload it to device file system over serial connection. 

# Store: http://www.HackerArsenal.com

# Attack-Defense Training:   http://www.PentesterAcademy.com

from __future__ import division
import serial
import time
import sys
import argparse

parser = argparse.ArgumentParser(description='WiNX/WiNX Portable Custom Deception Firmware Helper Utility')

parser.add_argument('-p' , action='store', dest= "serial_port_path", help='Serial Port Path e.g. /dev/ttyUSB0 (Linux), COM5 (Windows), /dev/cu.SLAB_USBtoUART (MACOS). Please ensure you have sufficient permissions to access the Serial port.') 

parser.add_argument('-f', action="store" , dest="file_name", help='Name of HTML file to upload to the device')


user_inputs = parser.parse_args()

if not (user_inputs.serial_port_path and user_inputs.file_name) :
	print "Invalid or Incomplete Argument List! exiting ..."
	print "\nFor command help: python WiNX-Deception-Helper.py -h\n\n"
	sys.exit(-1)

	
# Assigning arguments to variables
port_name=user_inputs.serial_port_path
login_page=user_inputs.file_name

# Reading from given HTML file
with open(login_page, 'r') as content_file:
    data = content_file.read()

# Changing from UTF-8 to ACII
udata=data.decode("utf-8")
asciidata=udata.encode("ascii","ignore")  
asciidata = asciidata.replace("\n","")


# Preparing command to send to serial
content="D1"+str(len(asciidata))+"#"+asciidata
#content="D1"+asciidata
length=len(asciidata)+2+len(str(len(asciidata)))+1
orig_length=length

# Checking payload length
# WARNING: 
print "Payload length: "+str(length)
if length > 153620:
    print "Page size above permissible limit of 150 KB."
    sys.exit(-1)

# Opening serial port    
ser = serial.Serial(port_name, 115200, timeout=0)
print "Opened port "+port_name
time.sleep(2)
begin=0
end=100
jump=end

# Iterating to write all content slowly
# The reason fo doing this slowly is the low speed support on serial 
while length > 0:
    if length < jump:
        end=end-jump+length
        ser.write(content[begin:end]+"\n")
    else:
        ser.write(content[begin:end])
    # print content[begin:end]
    begin+=jump
    end+=jump
    percent=(((orig_length - length) / orig_length) * 100)
    print "Uploaded "+ str(percent)[0:4] +" %"
    time.sleep(1)
    length-=jump
    
# Printing completion message
print "Upload complete"
# Closing serial port
ser.close()

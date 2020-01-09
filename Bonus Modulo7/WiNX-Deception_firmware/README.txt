Steps to Upload Firmware
########################

1. Connect the device to your laptop
2. Check the port on which the device is mapped using the hardware manager e.g. COM3, /dev/ttyUSB0 etc. depending on your Operating System
3. Open a command prompt and navigate to the firmware directory 
4. Run the command below based on your Operating System


[Windows]

python esptool.py --chip esp32 --port COM3 --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_freq 80m --flash_mode dio --flash_size 4MB 0x1000 bootloader.bin 0x8000 WiNX-Deception.ino.partitions.bin 0xe000 boot_WiNX-Deception.bin 0x10000 WiNX-Deception.ino.bin 


[Linux]

python esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_freq 80m --flash_mode dio --flash_size 4MB 0x1000 bootloader.bin 0x8000 WiNX-Deception.ino.partitions.bin 0xe000 boot_WiNX-Deception.bin 0x10000 WiNX-Deception.ino.bin 

[Mac OS]

python esptool.py --chip esp32 --port /dev/cu.SLAB_USBtoUART --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_freq 80m --flash_mode dio --flash_size 4MB 0x1000 bootloader.bin 0x8000 WiNX-Deception.ino.partitions.bin 0xe000 boot_WiNX-Deception.bin 0x10000 WiNX-Deception.ino.bin 


5. You should now refer to the User Manual of the firmware to understand how to work with the device

IMPORTANT:  Once you have flashed the device with this firmware, it is important to note that if you want to re-flash the device with the same firmware again, you will need to use 115200 as the baud rate in the above command. 
 
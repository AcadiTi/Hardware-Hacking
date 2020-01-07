Steps to upload custom page
############################

1. Install python 2.x on your machine (it not installed already). Instuctions and download links are mentioned on the following link:

	https://wiki.python.org/moin/BeginnersGuide/Download

Please remember to add python to environment variable PATH.

2. Now, we need to install pyserial python module. For that, please open a Command prompt or Powershell and fire following command.

	pip install pyserial

3. Edit the template page as per your requirements. Please keep in mind:
	a. The page size should not exceed 150KB.
	b. All images need to be converted into base64 format. There are many websites which can do that, e.g. https://www.base64-image.de/
		i) Upload the image filed on the website.
		ii) Copy the base64 code and paste it in place of image source (as shown in template_2.html).
	c. Only one page can be uploaded to the device at one time.
	
Please refer to the manual for more details.

4. Now, open Powershell or Command prompt or Shell and use the following command to upload the page.

	python upload_portal.py <Serial_Port> <File_name>

	Example: python upload_portal.py COM3 template_2.html
	
5. Once the upload finishes, reset the device.

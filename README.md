# CMSC471Project3
Image recognition program using opencv

https://www.youtube.com/watch?v=U49CVY8yOxw 

Make a directory called Proj3SiqiLin

1) Download CMake on https://cmake.org/download/
	- Select cmake-3.5.2-Darwin-x86_64.tar.gz
	- Extract cmake-3.5.2-Darwin-x86_64.tar.gz
2) Download opencv source code
	- Go to http://opencv.org/
	- Click OpenCV for Linux/Mac
	- Extract opencv-3.1.0.zip 
	- Move the extracted opencv-3.1.0 directory under the Proj3SiqiLin directory
	- Open the opencv-3.1.0 directory
	- Under the opencv-3.1.0 directory, Create a folder, name it "build"
3) Launch CMake
	- Under "where is the source code", enter the absolute path for where the opencv source code is located, which would be ……/Proj3SiqiLin/opencv-3.1.0
	- Under "Where to build the binaries", enter the path for the "build" directory we just created, my path is ……/Proj3SiqiLin/opencv-3.1.0/build
	- Click on the "Configure" button
	- After Configure is completed, click on the "Generate" button
	- Exit CMake after "Generate" is completed
4) Open Terminal
	- cd to the build directory under opencv-3.1.0
		cd ……/Proj3SiqiLin/opencv-3.1.0/build
	- enter the following command
		make
		sudo make install

5) Open the project in XCode
	- Click on the project
	- Click on the build settings
	- Type "Search paths"
	- Set "Always Search User Paths" to "Yes"
	- Set "Framework Search Paths" to "/usr/local/lib"
	- Set "Header Search Paths" to "/usr/local/include"
	- Set "Library Search Paths" to the /build/lib directory under the opencv-3.1.0 directory, which woul be something like
		……/Proj3SiqiLin/opencv-3.1.0/build/lib
	- Right click on the Project, select "Add Files to Project3"
	- Go to the build/lib directory under ……/Proj3SiqiLin/opencv-3.1.0/build/lib, add the following four dylib items
		1) libopencv_ml.3.1.0.dylib
		2) libopencv_imgcodecs.3.1.0.dylib
		3) libopencv_highgui.3.1.0.dylib
		4) libopencv_core.3.1.0.dylib

6) Set the command line arguments in XCode
	- On the menu bar, select Product>Scheme>Edit Scheme>
	- Enter the file path of the image you wish to test under "Arguments Passed on Launch"




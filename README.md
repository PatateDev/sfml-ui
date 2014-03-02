sfml-ui
=======

A simple UI library for SFML.
Works on GNU/Linux, Windows. Currently not tested on Mac OS X.

How to compile
--------------
_Make sure you have already compiled SFML and CMake is installed_

If you use a graphical version of CMake :

1. Open CMake
2. Enter the path of the source (the root folder of the project, not src folder)
3. Enter the path of the folder where you would like the library to be compiled
4. Click on the button configure and choose your generator
5. Set up the different settings (i.e change the path to your SFML libraries)
6. Click on generate button
7. If you choose 'Makefiles' as generator, open a terminal in your folder and type your system's make command, if you choose your IDE as generator, then open your IDE in your folder

Else, enter these command in your terminal :

+ `mkdir build && cd build`
+ `cmake .. -G "Unix Makefiles"` replace "Unix Makefiles" by your makefile generator
+ `make`

And to install : `sudo make install`

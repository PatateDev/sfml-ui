sfml-ui
=======

A simple UI library for SFML (2.2 at least). Works on GNU/Linux, Windows, Android. Currently not tested on Mac OS X and iOS.

Website (including documentation) : [patatedev.github.io/sfml-ui](http://patatedev.github.io/sfml-ui)

How to compile
--------------
_Make sure you have already compiled SFML and CMake is installed_

### Desktop OS (Win/Mac/Linux) ###
If you use a graphical version of CMake :

1. Open CMake
2. If SFML is not found, add a SFML_ROOT setting and set it to the folder where SFML is installed
4. Click on the button configure and choose your generator
5. Set up the different settings (i.e change the path to your SFML libraries)
6. Click on generate button
7. If you choose 'Makefiles' as generator, open a terminal in your folder and type your system's make command, if you choose your IDE as generator, then open your IDE in your folder

Else, enter these command in your terminal (Unix family OS) :

+ `mkdir build && cd build`
+ `cmake .. -G "Unix Makefiles"` replace "Unix Makefiles" by your makefile generator
+ `make`

Don't forget to have set SFML_ROOT setting if SFML is installed in a custom directory :

`export SFML_ROOT=<path/to/SFML>`

And to install : `sudo make install`

### Mobile OS - Android ###
Same as desktop os, except you have to specify this custom toolchain : cmake/toolchains/android.toolchain.cmake.
Once it is done, you can customize ANDROID_ABI setting for the target arch, and ANDROID_API for the Android target platform.

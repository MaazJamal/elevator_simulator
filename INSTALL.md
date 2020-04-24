# Installation

## Supported Platforms:

Unix, Cygwin and MacOS.

## Prerequisite

GCC Compiler, GNU make. mingw for windows.

## No Dependent External Libraries

## Build Project:

Running make will compile elevator and tests programs. The test program will provide options to test the program functions. In case of error please find solution at end of document.

```
make
```

If you just want the elevator program. run:

```
make elevator
```

If you just want the tests program. run:

```
make tests
```

Excutable binaries "elevator.exe" and "tests.exe"(in windows) files will be placed in root folder of the project. For cygwin/unix type. 
```
./elevator
```
or 
```
 ./tests
```
In some cases the compilation may fail with the error:
```
Undefined Reference to WinMain
```
or similar, in such cases, run `make` command again or compile just the binary you want `make elevator` or `make tests` This program will compile in second attempt. 

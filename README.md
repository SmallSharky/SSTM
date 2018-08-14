## How to build

### Create build directory

$ mkdir build

### Go to build directory

$ cd build

### Run cmake

$ cmake ..

### Run make

$ make

### List binary files

$ ls | grep .bin

### Flash any binary file

$ st-flash write program.bin 0x08000000

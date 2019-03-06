# Implementation of an HDF5 IO layer for PODIO
## Google Summer of Code 2019 Evaluation Test Response

Tasks :

-    [x] Create bash script `get_podio.sh` to automatically clone, compile and test [PODIO](https://github.com/AIDASoft/podio)
-    [x] Study `datalayout.yaml`, and data models on PODIO
-    [x] Create `write.cpp` to write an array of type `SimpleStruct` to file `SimpleStructFile.h5`
-    [x] Create `read.cpp` to read an array of type `SimpleStruct` from the file `SimpleStructFile.h5` and validate the data
-    [x] Create `makefile` to compile `write.cpp` and `read.cpp`

## Running instructions

For compiling, **h5c++** is used.

1. Make using the command `make`.  This will compile and create 2 executables - `write.cpp`, and `read.cpp`
2. Execute them using `make run`

If everything goes as expected, the following output is seen:

```bash
./write.out
Initialising data...
Creating file SimpleStructFile.h5...
Writing data...
SUCCESS
./read.out
Checking data....
SUCCESS
```
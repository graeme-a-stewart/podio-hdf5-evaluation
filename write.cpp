/***************************************************************************************
* Author : Amarnath Karthi
* read.cpp
* 
* Example of writing 100 SimpleStruct Objects to a file using `SimpleStructH5Wrapper.h`
****************************************************************************************/

#include <iostream>
#include <vector>
#include <array>

#include "SimpleStruct.h"
#include "SimpleStructH5Wrapper.h"

using namespace std;
using namespace H5;

const string FILE_NAME( "SimpleStructFile.h5" );
const string DATASET_NAME( "ArraySimpleStruct" );

const int num_elements = 100;

int main() {
    array<SimpleStruct, num_elements> data;

    /*
    *   Initialize data
    */
   cout<<"Initialising data..."<<endl;
    for(int i=0; i<num_elements; i++) {
        data[i].p[0] = i;
        data[i].p[1] = i;
        data[i].p[2] = i;
        data[i].p[3] = i;
        data[i].x = 10*i;
        data[i].y = 10*i + 1;
        data[i].z = 10*i + 2;
    }

    writeSimpleStructArray(data, FILE_NAME, DATASET_NAME);

    return 0; 
}

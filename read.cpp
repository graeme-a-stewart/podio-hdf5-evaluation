/***************************************************************************************
* Author : Amarnath Karthi
* read.cpp
* 
* Example of reading 100 SimpleStruct Objects from a file using `SimpleStructH5Wrapper.h`
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

template<std::size_t SIZE>
bool verify(array<SimpleStruct, SIZE> data) {
    for(int i=0; i<data.size(); i++) {
        for(int j=0; j<data[i].p.size(); j++) {
            if(data[i].p[j]!=i)
                return false;
        }
        if(data[i].x != i*10 || data[i].y != i*10+1 || data[i].z != i*10+2) {
            return false;
        }
    }
    return true;
}

int main() {
    array<SimpleStruct, num_elements> data;
    readSimpleStructArray(data, FILE_NAME, DATASET_NAME);

    cout<<"Checking data...."<<endl;
    if(verify(data))
        cout<<"SUCCESS"<<endl;
    else
        cout<<"FAILURE"<<endl;
}

/***************************************************************************************
* Author : Amarnath Karthi
* SimpleStructH5Wrapper.h
* 
* Contains utility function for reading and writing SimpleStruct Arrays to HDF5 files.
****************************************************************************************/

#ifndef SimpleStruct_H5_Wrapper_H //header guards
#define SimpleStruct_H5_Wrapper_H

#include <iostream>
#include <string>
#include <array>
#include <H5Cpp.h>
#include <hdf5.h>

#include "SimpleStruct.h"

using namespace H5;
using namespace std;

// Data members of the SimpleStruct Datatype
const string MEMBER_X = "x";
const string MEMBER_Y = "y";
const string MEMBER_Z = "z";
const string MEMBER_P = "p";

// HDF5 File specifications
const int RANK = 1;
const int ARRAY_RANK = 1;
const hsize_t asize = 4;

/*
* Create the memory datatype.
*/
CompType getSimpleStructType() {
    ArrayType array_type(PredType::NATIVE_INT, ARRAY_RANK,&asize);
    CompType mtype1( sizeof(SimpleStruct) );
    mtype1.insertMember( MEMBER_P, HOFFSET(SimpleStruct, p), array_type);
    mtype1.insertMember( MEMBER_X, HOFFSET(SimpleStruct, x), PredType::NATIVE_INT);
    mtype1.insertMember( MEMBER_Y, HOFFSET(SimpleStruct, y), PredType::NATIVE_INT);
    mtype1.insertMember( MEMBER_Z, HOFFSET(SimpleStruct, z), PredType::NATIVE_INT);
    return mtype1;
}

/*
* Utility function to write SimpleStruct array `data` to HDF5 file `file_name` under dataset `dataset_name`
* Returns void
*/
template<std::size_t SIZE>
void writeSimpleStructArray(array<SimpleStruct, SIZE> &data, string file_name, string dataset_name) {
    CompType mtype1 = getSimpleStructType();
    
    // Create the data space.
    hsize_t dim[] = { data.size() };
    DataSpace space(RANK, dim);

    // Create file
    H5File *file = new H5File(file_name, H5F_ACC_TRUNC);

    // Create dataset
    DataSet* dataset = new DataSet(file->createDataSet(dataset_name, mtype1, space));

    // Write `data` to `dataset`
    dataset->write( &data, mtype1 );

    // Free resources
    delete dataset;
    delete file;
}

/*
* Utility function to read into SimpleStruct array `data` from HDF5 file `file_name` under dataset `dataset_name`
* Returns void
*/
template<std::size_t SIZE>
void readSimpleStructArray(array<SimpleStruct, SIZE> &data, string file_name, string dataset_name) {

    CompType mtype1 = getSimpleStructType();

    // Create file and dataset objects
    H5File *file = new H5File(file_name, H5F_ACC_RDONLY);
    DataSet *dataset = new DataSet (file->openDataSet( dataset_name));

    // Read into `data` from `dataset`
    dataset->read( &data, mtype1 );
    
    // Free resources
    delete dataset;
    delete file;
}

#endif

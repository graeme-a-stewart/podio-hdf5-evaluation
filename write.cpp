#include <iostream>
#include <vector>
#include <H5Cpp.h>
#include <hdf5.h>

#include "SimpleStruct.h"

using namespace std;
using namespace H5;

const string FILE_NAME( "SimpleStructFile.h5" );
const string DATASET_NAME( "ArraySimpleStruct" );
const string MEMBER_X = "x";
const string MEMBER_Y = "y";
const string MEMBER_Z = "z";
const string MEMBER_P = "p";

const int num_elements = 100;
const int RANK = 1;
const int ARRAY_RANK = 1;
const hsize_t asize = 4;

int main() {
    int num_elements = 100;
    int RANK = 1;
    int ARRAY_RANK = 1;
    hsize_t asize = 4;

    SimpleStruct data[num_elements];

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

    /*
    * Create the data space.
    */
    hsize_t dim[] = {num_elements};
    DataSpace space(RANK, dim);

    /*
    * Create file
    */
    cout<<"Creating file "<<FILE_NAME<<"..."<<endl;
    H5File *file = new H5File(FILE_NAME, H5F_ACC_TRUNC);

    /*
    * Create the memory datatype.
    */
    ArrayType array_type(PredType::NATIVE_INT, ARRAY_RANK,&asize);
    CompType mtype1( sizeof(SimpleStruct) );
    mtype1.insertMember( MEMBER_P, HOFFSET(SimpleStruct, p), array_type);
    mtype1.insertMember( MEMBER_X, HOFFSET(SimpleStruct, x), PredType::NATIVE_INT);
    mtype1.insertMember( MEMBER_Y, HOFFSET(SimpleStruct, y), PredType::NATIVE_INT);
    mtype1.insertMember( MEMBER_Z, HOFFSET(SimpleStruct, z), PredType::NATIVE_INT);


    /*
    * Create the dataset.
    */
    DataSet* dataset;
    dataset = new DataSet(file->createDataSet(DATASET_NAME, mtype1, space));

    /*
    * Write data to the dataset;
    */
    cout<<"Writing data..."<<endl;
    dataset->write( data, mtype1 );

    cout<<"SUCCESS"<<endl;

    /*
    * Release resources
    */
    delete dataset;
    delete file;
    return 0; 
}
#include <iostream>
#include <vector>
#include "H5Cpp.h"

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


bool verify(SimpleStruct *data, int num) {
    for(int i=0; i<num; i++) {
        for(int j=0; j<4; j++) {
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
    
    SimpleStruct data[num_elements];

    H5File *file = new H5File(FILE_NAME, H5F_ACC_RDONLY);
    DataSet *dataset = new DataSet (file->openDataSet( DATASET_NAME ));

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
    * Load content
    */
    dataset->read( data, mtype1 );

    cout<<"Checking data...."<<endl;
    if(verify(data, num_elements))
        cout<<"SUCCESS"<<endl;
    else
        cout<<"FAILURE"<<endl;
    
    /*
    * Release resources
    */
    delete dataset;
    delete file;
    return 0; 
}
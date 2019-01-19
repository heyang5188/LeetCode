#include <iostream>
using namespace std;


int Getsize(int data[])
{
    return sizeof(data);
}

int main(int argc, char const *argv[])
{
    int data[] = {1,2,3,4,5};
    cout << "sizeof data[]" << sizeof(data)<<  endl;

    int * data2 = data;
    //pointer which allowed 4B 
    cout << "sizeof ===" << sizeof(data2) << endl;
    //when a pointer of an array 
    cout << "sizeof data " << Getsize(data) << endl;
    
    return 0;   
}

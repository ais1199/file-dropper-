#ifndef _FM_H_
#define _FM_H_
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
//#include <cstring>
//#include <cstdlib>
//#include <cassert>


using namespace std;
using std::cout;

class fm
{
public:
    fm();
    ~fm();
private:
    char* outBase;
    char* startFile;
    vector<int> numbers;
    vector<FILE*> files;
    void getdata();
    void start();
    FILE* data;
};
#endif // _FM_H_

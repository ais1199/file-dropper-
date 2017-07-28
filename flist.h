#ifndef _FLIST_H_
#define _FLIST_H_

#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct item
{
    int name;
    FILE* f;
};

class flist
{
public:
    flist(char*);
    bool addNewItem(int);
    const FILE* file(int);
    const char* getpath();
    int ln();
    ~flist();
private:
    vector<item*> ways;
    char* path;
};

#endif

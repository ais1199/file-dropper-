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
    char buf;
    int stage;
};

class flist
{
public:
    flist(char*);
    bool addNewItem(int);
    const FILE* file(int);
    const char* getpath();
    bool putbit(int,char);
    int ln();
    ~flist();
private:
    vector<item*> ways;
    char* path;
};

#endif

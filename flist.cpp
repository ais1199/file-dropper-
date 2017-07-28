#include "flist.h"
#include <string.h>

flist::flist(char*npath)
{
    ways.clear();
    path=(char*)malloc(sizeof(char)*(strlen(npath)+1));
    strcpy(path,npath);
}

bool flist::addNewItem(int newitem)
{
    if(newitem<0)return false;
    int s=ways.size();
    item* b;
    int i;
    for(i=0;i<s;i++)
    {
        b=ways[i];
        if (b->name==newitem) return false;
    }
    b=(item*)malloc(sizeof(item));
    b->name=newitem;
    char *s1=(char*)malloc(sizeof(char));
    (*s1)='\0';
    char *s2=(char*)malloc(sizeof(char)*(strlen(path)+1));
    strcpy(s2,path);
    char *s3=(char*)malloc(sizeof(char)*2);
    (*s3)='0';
    *(s3+1)='\0';
    i=newitem;
    while(i>0)
    {
        s3[0]='0'+(i % 10);
        strcat(s3,s1);
        s1=s3;
        i=i/10;
    }
    if(strlen(s1)==0)s1=s3;
    strcat(s2,s1);
    b->f=fopen(s2,"wb");
    if(b->f)
    {
        ways.push_back(b);
        return true;
    }
    printf("error opening %s \n",s1);
    fclose(b->f);
    exit(3);
}

const FILE* flist::file(int what)
{
    int s=ways.size();
    int i;
    item* b;
    for(i=0;i<s;i++)
    {
       b=ways[i];
       if(b->name==what) return b->f;
    }
    return NULL;
}
const char* flist::getpath()
{
    return path;
}

int flist::ln()
{
    return ways.size();
}

flist::~flist()
{
    free(path);
    int s=ways.size();
    int i;
    FILE*f;
    item*p;
    for(i=0;i<s;i++)
    {
        p=ways[i];
        f=p->f;
        fclose(f);
        free(p);
    }
}

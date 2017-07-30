#include "fm.h"
#include <string.h>

//#include <fstream>

fm::fm()
{
    numbers.clear();
    //files.clear();
    getdata();
    char a[]="./data";
    startFile=(char*)malloc(sizeof(char)*11);
    strcpy(startFile,a);
    start();
}

void fm::getdata()
{
    char buf[80];
    std::cin.getline(buf,80);
    int i;
    int j;
    int sign;
    for(i=0;i<80||buf[i]!='\0';i++)
    {
        sign=1;
        j=0;
        if(buf[i]=='-')
        {
            sign=-1;
            i++;
        }
        while(buf[i]>='0'&&buf[i]<='9')
        {
            j=j*10+buf[i]-'0';
            i++;
        }
        if(buf[i]==' '||buf[i]=='\0')
        {
            numbers.push_back(j*sign);
            if(buf[i]=='\0')break;
        }
        else{
            int s=numbers.size()+1;
            printf("Error! Please, restart from number %d\n",s);
            getdata();
            //return ;
        }
    }

}

void fm::start()
{
    FILE* f=fopen(startFile,"rb");
    int N=numbers.size();
    int i;
    char output[]="./out/";
    files = new flist(output);
    //flist*b;
    for(i=0;i<N;i++)
    {
        files->addNewItem(numbers[i]);
    }
    if(f)
    {
        printf("Start File is opened\n");
    }
    else{
            printf("File opening error!\n");
        exit(2);
    }
    char buf;
    char res=0x0;
    int s=numbers.size();
    i=0;
    int j;
    while(fread(&buf,1,1,f))
    {
        for(j=0;j<8;j++)
        {
            res=(buf>>j)&0x1;
            if(!files->putbit(numbers[i],res))
            {
                printf("Writing error, sorry((\n");
                exit(4);
            }
            i++;
            if(i>=s)i=0;
        }

    }
    fclose(f);
}

fm::~fm()
{
    delete files;
    free(startFile);
}

#include "fm.h"
#include <string.h>

//#include <fstream>

fm::fm()
{
    numbers.clear();
    files.clear();
    //getdata();
    char a[]="./data.txt";
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
    if(f)
    {
        printf("Start File is opened\n");
    }
    else{
            printf("File opening error!\n");
        exit(2);
    }
    fclose(f);
}

fm::~fm()
{
    free(outBase);
    free(startFile);
    int s=files.size();
    int i;
    FILE*f;
    for(i=0;i<s;i++)
    {
        f=files[i];
        fclose(f);
    }
}

#include "fm.h"
#include <fstream>

fm::fm()
{
    numbers.clear();
    files.clear();
    startFile.clear();
    getdata();
    start();
}

void fm::getdata()
{
    /*numbers.push_back(4);
    numbers.push_back(5);
    numbers.push_back(4);
    numbers.push_back(-2);
    numbers.push_back(9);*/
    char buf[80];
    //string d;
    std::cin.getline(buf,80);
    //std::cout<<buf<<std::endl;
    //d=string(buf);
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
        //int s=numbers.size();
        if(buf[i]==' '||buf[i]=='\0')
        {
            numbers.push_back(j*sign);

            //printf("%d\n",numbers[s]);
            if(buf[i]=='\0')break;
        }
        else{
            int s=numbers.size()+1;
            printf("Error! Please, restart from number %d\n",s);
            getdata();
            return ;
        }
    }
    //std::cin>>d;
    //std::cout<<d<<std::endl;
    //startFile=(char*)malloc(sizeof(char)*80);
    char a[]="./data.txt";
    startFile=string(a);
    //std::cout<<startFile<<std::endl;
}

void fm::start()
{

}

fm::~fm()
{
    free(outBase);
    startFile.clear();
    int s=files.size();
    int i;
    FILE*f;
    for(i=0;i<s;i++)
    {
        f=files[i];
        fclose(f);
    }
}

#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>


int countc(char *file) //�����ļ����ַ��� 
{   FILE *f;
    f = fopen(file, "r");
    int cchar=0;
    char a;
    if(NULL==(f=fopen(file,"r")))
    {
        printf("file is NULL");
    }
    else
    while (!feof(f))
    {
        a=fgetc(f);
        if(a==' '||a=='\t'||a=='\n') 
        cchar++;
        else
        cchar++;
    }
    fclose(f);printf("Charnum:%d ",cchar-2);
}

int countw(char *file)//�����ļ��ʵ���Ŀ 
{   FILE *f;
    int aword=0,cword=1; 
    f=fopen(file,"r");
    char ch;
    if(NULL==(f=fopen(file,"r")))
    {
     printf("file is NULL");
    }
    else
    while(!feof(f))
    {
        ch=fgetc(f);
       if(ch == ' '||(ch==','))
    
        	aword++;   
		
    else if (aword>1)
    {
                cword++;
                aword=0;
    }
    }
    fclose(f); printf("Wordnum:%d ",cword);
}


int main(int argc, char* argv[])             
{
    FILE *fp;
    while(1)
    {
        if((fp=fopen(argv[2],"r"))==NULL)
        {  
        printf("FileNull\n\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
        continue;
        }
        else if(!strcmp(argv[1],"-w")) 
        countw(argv[2]);                
        else if(!strcmp(argv[1],"-c"))  
        countc(argv[2]);                
       
        else
            printf("NullPoint\n");
        printf("\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
    }
    return 0;
}





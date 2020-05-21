#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

/*int count(char *path)//计算字符数 
{
	int count=0;
	char n;
	FILE *fp ;
	if (!(fp= fopen("path","r+"))){ 
	printf("打开失败，请检查您输入的路径！\n"); 
	exit(0);
	} 
	else{
	
	while (n = fgetc(fp) != EOF)  //读取字符直到结束 
	count++;
	 
	fclose(fp); 
	return count;
    }

 } */
 
 int CodeCount(char *Path) {    //计算字符个数
    
    FILE *file = fopen(Path, "r");
    assert(file != NULL);    //若文件不存在则报错

    char code;
    int count = 0;

    while ((code = fgetc(file)) != EOF)     //读取字符直到结束
            count+= ((code != ' ') && (code != '\n') && (code != '\t'));    //判断是否是字符    

    fclose(file);

    return count;
}

int WordCount(char *Path) {    //计算单词个数

    FILE *file = fopen(Path, "r");
    assert(file != NULL);

    char word;
    int is_word = 0;    //用于记录字符是否处于单词中
    int count = 0;

    while ((word = fgetc(file)) != EOF) {
        if ((word >= 'a' && word <= 'z') || (word >= 'A' && word <= 'Z')) {    //判断是否是字母            
            count += (is_word == 0);
            is_word = 1;    //记录单词状态
        }
        else 
            is_word = 0;    //记录不处于单词状态
    }
    fclose(file);

    return count;
}

 
 /*int count2(char *path)//计算单词数 
{
	
	FILE *fp = fopen("path","r+");
	if (fp==NULL){ 
	printf("打开失败，请检查您输入的路径！\n"); 
	exit(0); 
	} 
	int count=0,n,m;
	char *p;
	p = (char*)malloc(m*(sizeof(char)));
	for(m=0;n = fgetc(fp) != EOF;m++)//将字符存入动态数组 
	{
		p[m]=n;
	}
	
	for(int i=1;i<=m;i++)
	{
		if((p[i-1]!=' '&&p[i]==' ')||(p[i-1]!=' '&&p[i]==','))
	
			count++;
	
	}	

	fclose(fp); 
	return count;

 } */ 
 
int main(int argc,char* argv[])
{
	if(!strcmp(argv[1],"-c"))
	CodeCount(argv[2]);
	else if(!strcmp(argv[1],"-w"))
	WordCount(argv[2]);
	else 
	{
		printf("%s不是一个可执行命令",&argv[1]);
		scanf("%s%s%s",argv[0],argv[1],argv[2]);
	}
	
	
} 

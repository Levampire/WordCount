#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

/*int count(char *path)//�����ַ��� 
{
	int count=0;
	char n;
	FILE *fp ;
	if (!(fp= fopen("path","r+"))){ 
	printf("��ʧ�ܣ������������·����\n"); 
	exit(0);
	} 
	else{
	
	while (n = fgetc(fp) != EOF)  //��ȡ�ַ�ֱ������ 
	count++;
	 
	fclose(fp); 
	return count;
    }

 } */
 
 int CodeCount(char *Path) {    //�����ַ�����
    
    FILE *file = fopen(Path, "r");
    assert(file != NULL);    //���ļ��������򱨴�

    char code;
    int count = 0;

    while ((code = fgetc(file)) != EOF)     //��ȡ�ַ�ֱ������
            count+= ((code != ' ') && (code != '\n') && (code != '\t'));    //�ж��Ƿ����ַ�    

    fclose(file);

    return count;
}

int WordCount(char *Path) {    //���㵥�ʸ���

    FILE *file = fopen(Path, "r");
    assert(file != NULL);

    char word;
    int is_word = 0;    //���ڼ�¼�ַ��Ƿ��ڵ�����
    int count = 0;

    while ((word = fgetc(file)) != EOF) {
        if ((word >= 'a' && word <= 'z') || (word >= 'A' && word <= 'Z')) {    //�ж��Ƿ�����ĸ            
            count += (is_word == 0);
            is_word = 1;    //��¼����״̬
        }
        else 
            is_word = 0;    //��¼�����ڵ���״̬
    }
    fclose(file);

    return count;
}

 
 /*int count2(char *path)//���㵥���� 
{
	
	FILE *fp = fopen("path","r+");
	if (fp==NULL){ 
	printf("��ʧ�ܣ������������·����\n"); 
	exit(0); 
	} 
	int count=0,n,m;
	char *p;
	p = (char*)malloc(m*(sizeof(char)));
	for(m=0;n = fgetc(fp) != EOF;m++)//���ַ����붯̬���� 
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
		printf("%s����һ����ִ������",&argv[1]);
		scanf("%s%s%s",argv[0],argv[1],argv[2]);
	}
	
	
} 

// �����书��  ���ض˴������� ��������  �����㷨�ݶ�MD5  
// �汾 1.0 cmd���� �°汾����
// ���� ���麭
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  SIZE 30
struct box_type//�ṹ������������������
{
   char name[15];//�ʺ�����ĵ�λ
   char mun[15];//�û���
   char power[15];//����
};
struct box_type munber[SIZE];
FILE *fp;
char munstr[20];//��������
int n=0;
void menu();//
void function1();//�½�
void function2();//���
void function3();//����
void function4();//�޸�
void function5();//ɾ��
void function6();//�˳�
void function0();//����
void main()
{
    system("color  0A");
	menu();
}
void menu()//�˵�����
{
    char choice;//ѡ��
	printf("\n        -------------------------------------------------------------\n");
	printf("\n            *************   �����棬�ܾ���Ϣй©   **************\n");
	printf("\n            ***1.�½�һ�������¼***    ***2.���һ�������¼***     \n");
	printf("\n            ***3.����һ�������¼***    ***4.����һ�������¼***      \n");
	printf("\n            ***5.ɾ��һ�������¼***    ***6.�˳����������*****       \n");
	printf("\n                               *****0.����*****                       \n");
	printf("\n            *************֧�����ġ�Ӣ���ַ��벻Ҫ����15λ************    \n");
	printf("\n      ------------------------------------------------------------------\n");
	choice=getchar();getchar();//��ȡѡ�� �������ڶ�ȡ�س�
	switch(choice)//ѡ������Ӻ���
	{
	   case'1':function1();break;
	   case'2':function2();break;
	   case'3':function3();break;
	   case'4':function4();break;
	   case'5':function5();break;
	   case'6':exit(0);
	   case'0':function0();break; 
	}
	menu();
}
void function1()
{
  char ch;
  n=0;
  if((fp=fopen("powerbox.txt","wb"))==NULL)
  {
    printf("�޷���powerbox.txt�ļ�\n");
	exit(0);
  }
  printf("���½�: ");
	  for (n=0;n<=SIZE;)
	  {
		  printf("\n ���ǵ�%d�������¼:\n ���뵥λ: ",n+1);
		  gets(munber[n].name);
		  printf("\n �������û���: ");
		  gets(munber[n].mun);
		  printf("\n ����������:   ");
		  gets(munber[n].power);
		  n++;
		  printf("�Ƿ������¼����: (Y/N)\n");
		  ch=getchar();getchar();
		  if (ch=='Y')
	      break;
	  }
          fwrite(munber,sizeof(munber[0]),n,fp);
		  fclose(fp);
	 
}


void function2()
{
  n=0;
  if ((fp=fopen("powerbox.txt","rb"))==NULL)
  {
	  printf("�޷���powerbox.txt�ļ�\n");
	  exit(0);
  }
  printf("-          ��λ           �û���           ����-\n");
  while(fread(&munber[n],sizeof(munber[n]),1,fp)==1)
  {
      printf("%15s%18s%18s\n",munber[n].name,munber[n].mun,munber[n].power);
	  n++;
  }
  fclose(fp);
}
void function3()
{
   int a=0;char ch;n=0;
   if((fp=fopen("powerbox.txt","rb"))==NULL)
   {
       printf("�޷���powerbox.txt�ļ�\n");
	   exit(0);
   }
   while(fread(&munber[n],sizeof(munber[n]),1,fp)==1)
   n++;
   a=n;
   printf("��ѡ����ҷ�ʽ��\n");
   printf("***1.��λ***2.�û���***\n");
   ch=getchar();getchar();
   switch(ch)
   {
   case'1':
	   printf("��������Ҫ�����ĵ�λ���ƣ�\n");
	   gets(munstr);
	   for (n=0;n<a;)
	   {
		   if (!strcmp(munstr,munber[n].name))
		   
			   break;
			   n++;
		   
	   }
	     break;
   
   case'2':
	   printf("��������Ҫ�������û����� \n");
	   gets(munstr);
	   for (n=0;n<a;)
	   {
		   if(!strcmp(munstr,munber[n].mun))
			   break;
		       n++;
	   }
	   break;
   }
printf("-          ��λ            �û���          ����-\n");
printf("%15s%18s%18s%\n",munber[n].name,munber[n].mun,munber[n].power);
fclose(fp);
}
void function4()
{
    char ch;int i;
	printf("��Ҫ�޸�������¼?\n");
	function3();
	i=0;
	if ((fp=fopen("powerbox.txt","rb+"))==NULL)
	{
		printf("�޷���powerbox.txt\n");
		exit(0);
	}
	while(fread(&munber[i],sizeof(munber[i]),1,fp)==1)
	i++;
	printf("�����޸���һ��λ�ã�\n");
	printf("***1.��λ***2.�û���***3.����***");
	ch=getchar();getchar();
	switch(ch)
	{
	   case'1':printf("�������µĵ�λ��\n");
	   gets(munber[n].name);
	   printf("%s\n",munber[n].name);
	   break;
	   case'2':printf("�������µ��û�����\n");
	   gets(munber[n].mun);
	   printf("%s\n",munber[n].mun);
	   break;
	   case'3':printf("�������µ����룺\n");
	   gets(munber[n].power);
	   printf("%s\n",munber[n].power);
	   break;
	}
    printf("%-6s%10s%10s\n",munber[n].mun,munber[n].name,munber[n].power);
    rewind(fp);
	fwrite(munber,sizeof(munber[0]),i,fp);
	fclose(fp);
}


    void function5()
	{
	    int  i=0;int a=0;
		printf("�����Ҫɾ����¼�����Ȳ�����Ҫɾ��������\n");
		function3();
		if ((fp=fopen("powerbox.txt","rb+"))==NULL)
		{
			printf("�޷���powerbox.txt�ļ�\n");
			exit(0);
		}
		while(fread(&munber[n],sizeof(munber[0]),1,fp)==1)
		i++;
		a=i;
		for (i=n;i<a;i++)
		munber[i]=munber[i+1];
        fp=fopen("powerbox.txt","wb");
		fwrite(munber,sizeof(munber[0]),a-1,fp);
		fclose(fp);
	}
   
	void function0()
	{
		printf("\n       --------------------���� ɽ�� �Ͳ� ���麭---------------------\n");
		printf("\n       ---------------------�����޼ۣ����������----------------------\n");
		printf("\n                V1.0�汾 ��̰汾����ϵ 749916276@qq.com             \n");
	    menu();
	}
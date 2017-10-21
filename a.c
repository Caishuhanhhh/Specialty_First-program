// 密码箱功能  本地端储存密码 查找密码  
// 版本 1.0 
// 制作 蔡
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  SIZE 30
struct box_type//结构体用来储存所有数据
{
   char name[15];//帐号密码的单位
   char mun[15];//用户名
   char power[15];//密码
};
struct box_type munber[SIZE];
FILE *fp;
char munstr[20];//缓冲数组
int n=0;
void menu();//
void function1();//新建
void function2();//输出
void function3();//查找
void function4();//修改
void function5();//删除
void function6();//退出
void function0();//关于
void main()
{
    system("color  0A");
	menu();
}
void menu()//菜单函数
{
    char choice;//选项
	printf("\n        -------------------------------------------------------------\n");
	printf("\n            *************   单机版，拒绝信息泄漏   **************\n");
	printf("\n            ***1.新建一个密码记录***    ***2.输出一个密码记录***     \n");
	printf("\n            ***3.查找一个密码记录***    ***4.更新一个密码记录***      \n");
	printf("\n            ***5.删除一个密码记录***    ***6.退出密码箱程序*****       \n");
	printf("\n                               *****0.关于*****                       \n");
	printf("\n            *************支持中文、英文字符请不要超出15位************    \n");
	printf("\n      ------------------------------------------------------------------\n");
	choice=getchar();getchar();//获取选项 后者用于读取回车
	switch(choice)//选项调用子函数
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
    printf("无法打开powerbox.txt文件\n");
	exit(0);
  }
  printf("请新建: ");
	  for (n=0;n<=SIZE;)
	  {
		  printf("\n 这是第%d条密码记录:\n 键入单位: ",n+1);
		  gets(munber[n].name);
		  printf("\n 请输入用户名: ");
		  gets(munber[n].mun);
		  printf("\n 请输入密码:   ");
		  gets(munber[n].power);
		  n++;
		  printf("是否结束记录输入: (Y/N)\n");
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
	  printf("无法打开powerbox.txt文件\n");
	  exit(0);
  }
  printf("-          单位           用户名           密码-\n");
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
       printf("无法打开powerbox.txt文件\n");
	   exit(0);
   }
   while(fread(&munber[n],sizeof(munber[n]),1,fp)==1)
   n++;
   a=n;
   printf("请选择查找方式：\n");
   printf("***1.单位***2.用户名***\n");
   ch=getchar();getchar();
   switch(ch)
   {
   case'1':
	   printf("请输入你要搜索的单位名称：\n");
	   gets(munstr);
	   for (n=0;n<a;)
	   {
		   if (!strcmp(munstr,munber[n].name))
		   
			   break;
			   n++;
		   
	   }
	     break;
   
   case'2':
	   printf("请输入你要搜索的用户名： \n");
	   gets(munstr);
	   for (n=0;n<a;)
	   {
		   if(!strcmp(munstr,munber[n].mun))
			   break;
		       n++;
	   }
	   break;
   }
printf("-          单位            用户名          密码-\n");
printf("%15s%18s%18s%\n",munber[n].name,munber[n].mun,munber[n].power);
fclose(fp);
}
void function4()
{
    char ch;int i;
	printf("您要修改哪条记录?\n");
	function3();
	i=0;
	if ((fp=fopen("powerbox.txt","rb+"))==NULL)
	{
		printf("无法打开powerbox.txt\n");
		exit(0);
	}
	while(fread(&munber[i],sizeof(munber[i]),1,fp)==1)
	i++;
	printf("您想修改哪一个位置？\n");
	printf("***1.单位***2.用户名***3.密码***");
	ch=getchar();getchar();
	switch(ch)
	{
	   case'1':printf("请输入新的单位：\n");
	   gets(munber[n].name);
	   printf("%s\n",munber[n].name);
	   break;
	   case'2':printf("请输入新的用户名：\n");
	   gets(munber[n].mun);
	   printf("%s\n",munber[n].mun);
	   break;
	   case'3':printf("请输入新的密码：\n");
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
		printf("如果您要删除记录，请先查找所要删除的内容\n");
		function3();
		if ((fp=fopen("powerbox.txt","rb+"))==NULL)
		{
			printf("无法打开powerbox.txt文件\n");
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
		printf("\n       --------------------制作 山东 xx xxxxxx---------------------\n");
		printf("\n       ---------------------密码无价，请谨慎保存----------------------\n");
		printf("\n                V1.0版本 后继版本请联系 ***********@qq.com             \n");
	    menu();
	}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getch.h>
#include <string.h>

static char count = 0;	// 已添加的联系人数量
static char name[50][20];
static char sex[50];
static char tel[50][12];

//	按任意键继续
void anykey_continue(void)
{
	puts("按任意键继续...");
	//	清理输入缓冲区
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	getch();
}

//	打印提示信息
void msg_show(const char* msg,float sec)
{
	printf("%s",msg);
	fflush(stdout);
	usleep(sec*1000000);
}

//	添加
void add_mail(void)
{
	//printf("%s\n",__func__);	
	if(50 <= count)
	{
		printf("系统正在升级,稍后再试\n");
		return;
	}

	int i = 0;
	while(sex[i]) i++;

	printf("请输入姓名、性别、电话:");
	scanf("%s %c %s",name[i],sex+i,tel[i]);
	count++;

	msg_show("成功添加联系人",1.5);
	return;
}

//	删除
void del_mail(void)
{
	char key[20] = {};
	printf("请输入要删除的联系人姓名:");
	scanf("%s",key);
	for(int i=0; i<50; i++)
	{
		if(sex[i])
		{
			if(0 == strcmp(key,name[i]))
			{
				sex[i] = 0;
				count--;
				msg_show("删除联系人成功!\n",1.5);
				return;
			}
		}
	}
	msg_show("查无此人!\n",1.5);
}

//	修改
void mod_mail(void)
{
	char key[20] = {};
	printf("请输入要修改的联系人姓名:");
	scanf("%s",key);
	for(int i=0; i<50; i++)
	{
		if(sex[i] && 0 == strcmp(key,name[i]))
		{
			printf("请重新输入联系人信息:");
			scanf("%s %c %s",name[i],sex+i,tel[i]);
			msg_show("修改联系人成功!\n",1.5);
			return;
		}
	}
	msg_show("查无此人!\n",1.5);
}

//	查询
void find_mail(void)
{
	char key[20] = {};
	printf("请输入要查询的关键字:");
	scanf("%s",key);

	for(int i=0; i<50; i++)
	{
		if(sex[i] && (strstr(name[i],key) || strstr(tel[i],key)))	
		{
			printf("%s %s %s\n",
				name[i],'w'==sex[i]?"女":"男",tel[i]);	
		}
	}
	anykey_continue();
}

//	显示
void show_mail(void)
{
	for(int i=0; i<50; i++)
	{
		if(sex[i])	
		{
			printf("%s %s %s\n",
				name[i],'w'==sex[i]?"女":"男",tel[i]);	
		}
	}
	anykey_continue();
}

int main(int argc,const char* argv[])
{
	for(;;)
	{
		system("clear"); // system("cls");
		puts("1、添加联系人");	
		puts("2、删除联系人");	
		puts("3、修改联系人");	
		puts("4、查询联系人");	
		puts("5、显示所有联系人");	
		puts("6、退出系统");	
		printf("请输入指令:");
		int cmd = getch();
		printf("%c\n",cmd);//为了显示输入
		switch(cmd)
		{
			case '1':	add_mail();	break;	
			case '2':	del_mail();	break;	
			case '3':	mod_mail();	break;	
			case '4':	find_mail();	break;	
			case '5':	show_mail();	break;	
			case '6':	return 0;	
		}
	}
}

#include <stdio.h>
#include <string.h>
#include "tools.h"
#include "phone.h"

static char count = 0;	// 已添加的联系人数量

//static Contact con[COUNT_MAX];

Contact* con;

//	添加
void add_mail(void)
{
	//printf("%s\n",__func__);
	if(COUNT_MAX <= count)
	{
		printf("系统正在升级,稍后再试\n");
		return;
	}

	int i = 0;
	while(con[i].sex) i++;

	printf("请输入姓名、性别、电话:");
	scanf("%s %c %s",con[i].name,&con[i].sex,con[i].tel);
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
	for(int i=0; i<COUNT_MAX; i++)
	{
		if(con[i].sex)
		{
			if(0 == strcmp(key,con[i].name))
			{
				con[i].sex = 0;
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
		if(con[i].sex && 0 == strcmp(key,con[i].name))
		{
			printf("请重新输入联系人信息:");
			scanf("%s %c %s",con[i].name,&con[i].sex,con[i].tel);
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
		if(con[i].sex && (strstr(con[i].name,key) || strstr(con[i].tel,key)))	
		{
			printf("%s %s %s\n",
				con[i].name,'w'==con[i].sex?"女":"男",con[i].tel);	
		}
	}
	anykey_continue();
}

//	显示
void show_mail(void)
{
	for(int i=0; i<COUNT_MAX; i++)
	{
		if(con[i].sex)	
		{
			printf("%s %s %s\n",
				con[i].name,'w'==con[i].sex?"女":"男",con[i].tel);	
		}
	}
	anykey_continue();
}

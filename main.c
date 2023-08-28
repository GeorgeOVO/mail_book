#include <stdio.h>
#include <stdlib.h>
#include <getch.h>
#include "phone.h"

int main(int argc,const char* argv[])
{	
	con=calloc(sizeof(Contact),COUNT_MAX);
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
			case '6':	free(con);	return 0;	
		}
	}
}

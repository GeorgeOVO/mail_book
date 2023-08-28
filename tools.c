#include <stdio.h>
#include <getch.h>
#include <unistd.h>
#include "tools.h"

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

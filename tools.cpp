#include "tools.h"
#include "getch.h"
#include "emis.h"

// 清理缓冲区
void clear_stdin(void)
{
	stdin->_IO_read_ptr = stdin->_IO_read_end;
}

// 获取指令
char get_cmd(char start,char end)
{
	clear_stdin();
	printf("------------------\n");
	printf("请输入指令：");

	while(true)
	{
		char cmd = getch();
		if(start <= cmd && cmd <= end)
		{
			printf("%c\n",cmd);
			return cmd;
		}
	}
}

// 获取指定长度的字符串
char* get_str(char* str,size_t len)
{
	clear_stdin();
	fgets(str,len,stdin);
	if('\n' == str[strlen(str)-1])
	{
		str[strlen(str)-1] = '\0';
	}
	else
	{
		clear_stdin();
	}
	return str;
}

// 获取指定长度的密码
char* get_pwd(char* pass,size_t len,bool isecho)
{
	size_t index = 0;
	while(index < len)
	{
		char val = getch();
		if('\n' == val)
		{
			printf("\n");
			break;
		}
		if(127 == val)
		{
			if(index > 0)
			{
				index--;
				if(isecho)
				{
					printf("\b \b");
				}
			}
			continue;
		}
		pass[index++] = val;
		if(isecho)
		{
			printf("*");
		}
	}
	pass[index] = '\0';
	return pass;
}

// 任意键退出
void anykey_continue(void)
{
	clear_stdin();
	printf("按任意键继续...\n");
	getch();
}

// 初始化.dat文件
void init_id(void)
{
	FILE* fp = fopen(DATA_ID_PATH,"r");
	if(fp != NULL) return;
		
	int ids[3] = {1000,2000,3000};
	fp = fopen(DATA_ID_PATH,"w");
	fwrite(ids,sizeof(ids),1,fp);
	fclose(fp);
}

// 生成唯一的管理员ID号
int get_mgrid(void)
{
	FILE* fp = fopen(DATA_ID_PATH,"r+");
	if(NULL == fp)
	{
		printf("未调用inid_id函数！\n");
		return -1;
	}
	
	int id = 0;
	fseek(fp,0,SEEK_SET);
	fread(&id,4,1,fp);
	id++;
	fseek(fp,-4,SEEK_CUR);
	fwrite(&id,4,1,fp);
	fclose(fp);
	return id;
}

// 生成唯一的部门ID号
int get_deptid(void)
{
	FILE* fp = fopen(DATA_ID_PATH,"r+");
	if(NULL == fp)
	{
		printf("未调用inid_id函数！\n");
		return -1;
	}
	
	int id = 0;
	fseek(fp,4,SEEK_SET);
	fread(&id,4,1,fp);
	id++;
	fseek(fp,-4,SEEK_CUR);
	fwrite(&id,4,1,fp);
	fclose(fp);
	return id;
}

// 生成唯一的员工ID号
int get_empid(void)
{
	FILE* fp = fopen(DATA_ID_PATH,"r+");
	if(NULL == fp)
	{
		printf("未调用inid_id函数！\n");
		return -1;
	}
	
	int id = 0;
	fseek(fp,8,SEEK_SET);
	fread(&id,4,1,fp);
	id++;
	fseek(fp,-4,SEEK_CUR);
	fwrite(&id,4,1,fp);
	fclose(fp);
	return id;
}

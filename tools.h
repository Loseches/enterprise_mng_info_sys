#ifndef TOOLS_H
#define TOOLS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// 清理缓冲区
void clear_stdin(void);

// 获取指令
char get_cmd(char start='0',char end='9');

// 获取指定长度的字符串
char* get_str(char* str,size_t len);

// 获取指定长度的密码
char* get_pwd(char* pass,size_t len,bool isecho=false);

// 任意键退出
void anykey_continue(void);

// 初始化id.dat文件
void init_id(void);

// 生成唯一的管理员ID号
int get_mgrid(void); 

// 生成唯一的部门ID号
int get_deptid(void);

// 生成唯一的员工ID号
int get_empid(void);

#endif//TOOLS_H

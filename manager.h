#ifndef MANGER_H
#define MANGER_H
#include "tools.h"

// 管理子系统逻辑对象
class Manager
{
	int m_iId;
	char m_strName[20];
	char m_strPwd[20];
public:
	Manager(const char* name="",const char* pwd="");
	int getId(void)const;
	const char* getName(void) const;
	const char* getPwd(void) const;
	void setId(int id);
	void setName(const char* name);
	void setPwd(const char* pwd);
   /*第一个ostream&，返回的是ostream类对象的引用，为了进行连续的运算，如cout<<a<<b;
	 第二个ostream& os, os是随便取的名字，就是ostream类的对象，与cout用法一样， 通过<<将数据传到out里，所以输出时用cout<<a，
	 这时就调用 operator<<(cout,a)， 把cout作为参数传入
	 引用类型能改变实参，为防止产生临时对象、提高程序效率，所以设将第三个参数设置为const。如果不用&，将会复制一个参数，
	 而不是将原来的对象直接传入，就会调用拷贝构造函数（如果没写的话编译器自动提供），浪费时间，有时还会产生错误，比如数据成员里有指针时，
	 编译器提供的拷贝构造函数将会自动复制 一个指针，与原来的指针指向同一个地址，这样改变一个另一个也会改变，这是我们不想要的，我们需要拷贝时指针指向
	 不同的地址，两个对象互不干扰，只是指针所指变量的值相等就行，这就需要自己写拷贝构造函数，自己new等。所以一般用&，加const防止意外修改。
	 友元函数是为了方便对对象内部数据的操作，设置为friend友元函数
	 重载后<<、>>可输出类类型(参数1：输出流对象、参数2：要输出的对象)*/
	friend ostream& operator<<(ostream& os,const Manager& mgr);	
	friend istream& operator>>(istream& is,Manager& mgr);       
};
#endif//MANGER_H



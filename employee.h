#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "tools.h"

class Employee
{
	int m_iId;
	char m_cSex;
	char m_strName[20];
public:
	Employee(const char* name="",char sex='m');
	void setId(int id);
	void setSex(char sex);
	void setName(const char* name);
	int getId(void);
	char getSex(void);
	const char* getName(void);
	friend ostream& operator<<(ostream& os,const Employee& emp);
	friend istream& operator>>(istream& is,Employee& emp);
};
#endif//EMPLOYEE_H

#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "employee.h"

class Department
{
	int m_iId;
	char m_strName[20];
public:
	vector<Employee> empArr;
	Department(const char* name="");
	void setId(int id);
	void setName(const char* name);
	int getId(void) const;
	const char* getName(void) const;
	friend ostream& operator<<(ostream& os,const Department& dept);
	friend istream& operator>>(istream& is,Department& dept);
};

#endif//DEPARTMENT_H

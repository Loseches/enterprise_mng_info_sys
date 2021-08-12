#include "employee.h"

Employee::Employee(const char* name,char sex)
{
	strcpy(m_strName,name);
	m_cSex = sex;
}

void Employee::setId(int id)
{
	m_iId = id;
}

void Employee::setSex(char sex)
{
	m_cSex = sex;
}

void Employee::setName(const char* name)
{
	strcpy(m_strName,name);
}

int Employee::getId(void)
{
	return m_iId;
}

char Employee::getSex(void)
{
	return m_cSex;
}

const char* Employee::getName(void)
{
	return m_strName;
}

ostream& operator<<(ostream& os,const Employee& emp)
{
	return os << emp.m_iId << " " << emp.m_strName << " " << emp.m_cSex;
}

istream& operator>>(istream& is,Employee& emp)
{
	return is >> emp.m_iId >> emp.m_strName >> emp.m_cSex;
}

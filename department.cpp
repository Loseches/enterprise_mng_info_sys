#include "department.h"

Department::Department(const char* name)
{
	strcpy(m_strName,name);
}

void Department::setId(int id)
{
	m_iId = id;
}

void Department::setName(const char* name)
{
	strcpy(m_strName,name);
}

int Department::getId(void)const
{
	return m_iId;
}

const char* Department::getName(void)const
{
	return m_strName;
}

ostream& operator<<(ostream& os,const Department& dept)
{
	os << dept.m_iId << " " << dept.m_strName << " " << dept.empArr.size() << endl;
	for(unsigned int i=0; i<dept.empArr.size(); i++)
	{
		os << dept.empArr[i] << endl;
	}
	return os;
}

istream& operator>>(istream& is,Department& dept)
{
	unsigned int empCnt = 0;
	is >> dept.m_iId >> dept.m_strName >> empCnt;
	for(unsigned int i=0; i<empCnt; i++)
	{
		Employee emp;
		is >> emp;
		dept.empArr.push_back(emp);
	}
	return is;
}

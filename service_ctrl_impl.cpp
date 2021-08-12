#include "service_ctrl_impl.h"

ServiceCtrlImpl::ServiceCtrlImpl(void)
{
	srcMode = new ServiceModeImpl;
	srcMode->load(deptArr);
}

ServiceCtrlImpl::~ServiceCtrlImpl(void)
{
	srcMode->save(deptArr);
	delete srcMode;
}

bool ServiceCtrlImpl::addDept(Department& dept)
{
	for(unsigned int i=0; i<deptArr.size(); i++)
	{
		if(!strcmp(dept.getName(),deptArr[i].getName()))
		{
			return false;
		}
	}
	
	dept.setId(get_deptid());
	deptArr.push_back(dept);
	return true;
}

int ServiceCtrlImpl::delDept(int id)
{
	vector<Department>::iterator it;
	for(it=deptArr.begin(); it!=deptArr.end(); it++)
	{
		if(id ==it->getId())
		{
			if(it->empArr.size())
			{
				return 1;
			}
			else
			{
				deptArr.erase(it);
				return 0;
			}
		}
	}
	return 2;
}

vector<Department>& ServiceCtrlImpl::listDept(void)
{
	return deptArr;
}

bool ServiceCtrlImpl::addEmp(int id,Employee& emp)
{
	for(unsigned int i=0; i<deptArr.size(); i++)
	{
		if(id == deptArr[i].getId())
		{
			emp.setId(get_empid());
			deptArr[i].empArr.push_back(emp);
			return true;
		}
	}
	
	return false;
}

bool ServiceCtrlImpl::delEmp(int id)
{
	for(unsigned int i=0; i<deptArr.size(); i++)
	{
		vector<Employee>::iterator it;
		for(it=deptArr[i].empArr.begin(); it!=deptArr[i].empArr.end(); it++)
		{
			if(id == it->getId())
			{
				deptArr[i].empArr.erase(it);
				return true;
			}
		}
	}
	
	return false;
}

bool ServiceCtrlImpl::modEmp(int id,Employee& emp)
{
	for(unsigned int i=0; i<deptArr.size(); i++)
	{
		vector<Employee>::iterator it;
		for(it=deptArr[i].empArr.begin(); it!=deptArr[i].empArr.end(); it++)
		{
			if(id == it->getId())
			{
				emp.setId(id);
				deptArr[i].empArr.erase(it);
				deptArr[i].empArr.push_back(emp);
				return true;
			}
		}
	}
	return false;
}

vector<Department>& ServiceCtrlImpl::listAllEmp(void)
{
	return deptArr;
}

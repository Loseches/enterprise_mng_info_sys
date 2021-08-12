#include "service_view_impl.h"
#include "tools.h"

ServiceViewImpl::ServiceViewImpl(void)
{
	srcCtrl = new ServiceCtrlImpl;
}

ServiceViewImpl::~ServiceViewImpl(void)
{
	delete srcCtrl;
}

void ServiceViewImpl::menuSrc(void)
{
	while(true)
	{
		system("clear");
		cout << "1、添加部门" << endl;
		cout << "2、删除部门" << endl;
		cout << "3、列出所有部门" << endl;
		cout << "4、添加员工" << endl;
		cout << "5、删除员工" << endl;
		cout << "6、修改员工信息" << endl;
		cout << "7、列出部门所有员工" << endl;
		cout << "8、列出所有员工" << endl;
		cout << "9、退出运营子系统" << endl;
		switch(get_cmd())
		{
		case '1': addDept(); break;
		case '2': delDept(); break;
		case '3': listDept(); break;
		case '4': addEmp(); break;
		case '5': delEmp(); break;
		case '6': modEmp(); break;
		case '7': listDeptEmp(); break;
		case '8': listAllEmp(); break;
		case '9': return;
		}
 	}
}

void ServiceViewImpl::addDept(void)
{
	char name[20] = {};
	cout << "请输入部门名：";
	get_str(name,20);
	Department dept(name);
	if(srcCtrl->addDept(dept))
		cout << "添加部门成功！" << endl;
	else
		cout << "部门名重复，添加失败！" << endl;
	sleep(1);
}

void ServiceViewImpl::delDept(void)
{
	int id = 0;
	cout << "请输入要删除的部门ID：";
	cin >> id;
	switch(srcCtrl->delDept(id))
	{
	case 0: cout << "删除部门成功！" << endl; break;
	case 1: cout << "该部门中还有员工，删除失败！" << endl; break;
	case 2: cout << "输入的部门ID有误，删除失败！" << endl; break;
	}
	sleep(1);
}

void ServiceViewImpl::listDept(void)
{
	vector<Department> deptArr = srcCtrl->listDept();
	for(unsigned int i=0; i<deptArr.size(); i++)
	{
		cout << deptArr[i].getId() << " " << deptArr[i].getName() << endl;
	}
	anykey_continue();
}

void ServiceViewImpl::addEmp(void)
{
	int id = 0;
	cout << "请输入要加入的部门ID：";
	cin >> id;
	
	char name[20] = {} , sex = 0;
	cout << "请输入员工的姓名：";
	get_str(name,20);
	cout << "请输入员工的性别(m/w)：";
	cin >> sex;
	Employee emp(name,sex);
	if(srcCtrl->addEmp(id,emp))
		cout << "添加员工成功！" << endl;
	else
		cout << "输入的部门ID有误，添加员工失败！" << endl;
	sleep(1);
}

void ServiceViewImpl::delEmp(void)
{
	int id = 0;
	cout << "请输入要删除的员工ID：";
	cin >> id;
	if(srcCtrl->delEmp(id))
		cout << "删除员工成功！" << endl;
	else
		cout << "输入的员工ID有误，删除员工失败！" << endl;
	sleep(1);
}

void ServiceViewImpl::modEmp(void)
{
	int id;
	cout << "请输入要修改的员工ID：";
	cin >> id;
	char name[20] = {} , sex = 0;
	cout << "请输入员工新的姓名：";
	get_str(name,20);
	cout << "请输入员工新的性别(m/w)：";
	cin >> sex;
	Employee emp(name,sex);
	if(srcCtrl->modEmp(id,emp))
		cout << "修改员工信息成功！" << endl;
	else
		cout << "输入的员工ID有误，修改员工信息失败！" << endl;
	sleep(1);
}

void ServiceViewImpl::listDeptEmp(void)
{
	int id = 0;
	cout << "请输入要显示的部门ID：";
	cin >> id;
	
	vector<Department>& deptArr = srcCtrl->listAllEmp();
	for(unsigned int i=0; i<deptArr.size(); i++)
	{
		if(id == deptArr[i].getId())
		{
			cout << deptArr[i];
			anykey_continue();
			return;
		}
	}
	
	cout << "输入的部门ID有误！" << endl;
	sleep(1);
}

void ServiceViewImpl::listAllEmp(void)
{
	vector<Department>& deptArr = srcCtrl->listAllEmp();
	for(unsigned int i=0; i<deptArr.size(); i++)
	{
		cout << deptArr[i];
	}
	anykey_continue();
}

#include "manager_view_impl.h"
#include "tools.h"
//#include <windows.h>

ManagerViewImpl::ManagerViewImpl(void)
{
	mgrCtrl = new ManagerCtrlImpl;
	srcView = new ServiceViewImpl;
}

ManagerViewImpl::~ManagerViewImpl(void)
{
	delete srcView;
	delete mgrCtrl;
}

// 登录管理子系统
void ManagerViewImpl::loginManager(void)
{
	char id[10] = {} , pwd[10] = {};
	cout << "请输入用户ID：";
	get_str(id,10);
	cout << "请输入密码：";
	get_pwd(pwd,10);
	
	if(!strcmp("super",id) && !strcmp("1234",pwd))
	{
		menuMgr();
		return;
	}
	else
	{
		cout << "用户名或密码错误，登录失败！" << endl;
		sleep(1);
	}
}

// 登录运营子系统
void ManagerViewImpl::loginService(void)
{
	char id[10] = {} , pwd[10] = {};
	cout << "请输入用户ID：";
	get_str(id,10);
	cout << "请输入密码：";
	get_pwd(pwd,10);
	
	vector<Manager>& mgrArr = mgrCtrl->listMgr();
	for(unsigned int i=0; i<mgrArr.size(); i++)
	{
		if(atoi(id)==mgrArr[i].getId() && !strcmp(pwd,mgrArr[i].getPwd()))
		{
			srcView->menuSrc();
			return;
		}
	}
	
	cout << "用户名或密码错误，登录失败！" << endl;
	sleep(1);
}

// 管理子系统功能菜单
void ManagerViewImpl::menuMgr(void)
{
	while(true)
	{
		system("clear");
		cout << "1、添加管理员" << endl;
		cout << "2、删除管理员" << endl;
		cout << "3、列出所有管理员" << endl;
		cout << "4、退出管理子系统" << endl;
		
		switch(get_cmd('1','4'))
		{
		case '1': addMgr(); break;
		case '2': delMgr(); break;
		case '3': listMgr(); break;
		case '4': return;
		}
	}
}

// 添加管理
void ManagerViewImpl::addMgr(void)
{
	char name[20] = {} , pwd[20] = {} , repwd[20] = {};
	cout << "请输入管理员的姓名：";
	get_str(name,20);
	cout << "请输入管理员的密码：";
	get_pwd(pwd,20);
	cout << "请输入管理员的密码：";
	get_pwd(repwd,20);
	cout << pwd << " " << repwd << endl;
	if(strcmp(pwd,repwd))
	{
		cout << "两人次输入密码不符，添加失败!" << endl;
		sleep(1);
		return;
	}
	
	Manager mgr(name,pwd);
	if(mgrCtrl->addMgr(mgr))
		cout << "添加管理成功！" << endl;
	else
		cout << "用户名重复，添加管理失败！" << endl;
	sleep(1);
}

void ManagerViewImpl::delMgr(void)
{
	int id = 0;
	cout << "请输入要删除的管理ID：";
	cin >> id;
	if(mgrCtrl->delMgr(id))
		cout << "删除管理员成功！" << endl;
	else
		cout << "输入的ID有误，删除管理员失败！" << endl;
	sleep(1);
}

void ManagerViewImpl::listMgr(void)
{
	vector<Manager>& mgrArr = mgrCtrl->listMgr();
	for(unsigned int i=0; i<mgrArr.size(); i++)
	{
		cout << mgrArr[i] << endl; // 对应manager.h里的friend友元函数对运算符<<、>>重载
	}
	anykey_continue();
}

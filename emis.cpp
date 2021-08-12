#include "emis.h"
#include "tools.h"

EMIS EMIS::emis;

EMIS::EMIS(void)
{
	init_id();
	mgrView = new ManagerViewImpl;
}

EMIS::~EMIS(void)
{
	delete mgrView;
}

EMIS& EMIS::singleEMIS(void)
{
	return emis;
}

void EMIS::login(void)
{
	while(true)
	{
		system("clear");
		cout << "***企业管理系统***" << endl;
		cout << "1、登录管理子系统" << endl;
		cout << "2、登录业务子系统" << endl;
		cout << "3、退出系统" << endl;
		switch(get_cmd('1','3'))
		{
		case '1': mgrView->loginManager(); break;
		case '2': mgrView->loginService(); break;
		case '3': return;
		}
	}
}

#ifndef MANAGER_MODE_IMPL_H
#define MANAGER_MODE_IMPL_H
#include "manager_mode.h"
//#include "tools.h"

// 管理子系统模型实现类
class ManagerModeImpl:public ManagerMode
{
public:
	// 从文件加载数据
	void load(vector<Manager>& mgrArr);
	// 向文件保存数据
	void save(vector<Manager>& mgrArr);
};

#endif//MANAGER_MODE_IMPL_H

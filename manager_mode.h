#ifndef MANAGER_MODE_H
#define MANAGER_MODE_H
#include "manager.h"
///#include "tools.h"

// 管理子系统模型接口类
class ManagerMode
{
public:
    // 从文件加载数据
	virtual void load(vector<Manager>& mgrArr) = 0;
	// 向文件保存数据
	virtual void save(vector<Manager>& mgrArr) = 0;
};
#endif//MANAGER_MODE_H

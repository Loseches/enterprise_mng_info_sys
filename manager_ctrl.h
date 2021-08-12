#ifndef MANAGER_CTRL_H
#define MANAGER_CTRL_H
#include "manager.h"

class ManagerCtrl
{
public:
	virtual ~ManagerCtrl(void) {}
	// 添加管理员
	virtual bool addMgr(Manager& mgr) = 0;
	// 删除管理员
	virtual bool delMgr(int id) = 0;
	// 列出所有管理员
	virtual vector<Manager>& listMgr(void) = 0;
};

#endif//MANAGER_CTRL_H

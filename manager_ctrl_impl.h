#ifndef MANAGER_CTRL_IMPL_H
#define MANAGER_CTRL_IMPL_H
#include "manager_ctrl.h"
#include "manager_mode_impl.h"

class ManagerCtrlImpl:public ManagerCtrl
{
	vector<Manager> mgrArr;
	ManagerMode* mgrMode;
public:
	ManagerCtrlImpl(void);
	~ManagerCtrlImpl(void);
	// 添加管理员
	bool addMgr(Manager& mgr);
	// 删除管理员
	bool delMgr(int id);
	// 列出所有管理员
	vector<Manager>& listMgr(void);
};

#endif//MANAGER_CTRL_IMPL_H

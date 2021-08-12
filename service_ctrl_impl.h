#ifndef SERVICE_CTRL_IMPL_H
#define SERVICE_CTRL_IMPL_H
#include "service_ctrl.h"
#include "service_mode_impl.h"

class ServiceCtrlImpl:public ServiceCtrl
{
	ServiceMode* srcMode;
	vector<Department> deptArr;
public:
	ServiceCtrlImpl(void);
	~ServiceCtrlImpl(void);
	bool addDept(Department& dept);
	int delDept(int id);
	vector<Department>& listDept(void);
	bool addEmp(int id,Employee& emp);
	bool delEmp(int id);
	bool modEmp(int id,Employee& emp);
	vector<Department>& listAllEmp(void);
};
#endif//SERVICE_CTRL_IMPL_H

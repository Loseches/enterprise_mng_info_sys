#ifndef SERVICE_MODE_H
#define SERVICE_MODE_H
#include "department.h"
#include "employee.h"

class ServiceMode
{
public:
	virtual void load(vector<Department>& deptArr) = 0;
	virtual void save(vector<Department>& deptArr) = 0;
};
#endif//SERVICE_MODE_H

#include "service_mode_impl.h"
#include "emis.h"

void ServiceModeImpl::load(vector<Department>& deptArr)
{
	ifstream ifs(DATA_DEPT_PATH);
	if(!ifs.is_open())
	{
		return;
	}
	
	while(true)
	{
		Department dept;
		ifs >> dept;
		if(!ifs.good())
		{
			break;
		}
		deptArr.push_back(dept);
	}
	
	ifs.close();
}

void ServiceModeImpl::save(vector<Department>& deptArr)
{
	ofstream ofs(DATA_DEPT_PATH);
	if(!ofs.is_open())
	{
		return;
	}
	
	for(unsigned int i=0; i<deptArr.size(); i++)
	{
		ofs << deptArr[i];
	}
	ofs.close();
}

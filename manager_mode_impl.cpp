#include "manager_mode_impl.h"
#include "emis.h"

// 从文件加载数据
void ManagerModeImpl::load(vector<Manager>& mgrArr)
{
	ifstream ifs(DATA_USER_PATH);
	if(!ifs.is_open())//文件流对象与文件绑定，返回 true ,否则 false 
	{
		return;
	}
	
	while(true)
	{
		Manager mgr;
		ifs >> mgr;//析取器(>>)　　从流中输入数据
		if(!ifs.good())//good().用来判断当前流的状态（读写正常（即符合读取和写入的类型)，没有文件末尾）
		{
			break;
		}
		mgrArr.push_back(mgr);
	}
	
	ifs.close();
}

// 向文件保存数据
void ManagerModeImpl::save(vector<Manager>& mgrArr)
{
	ofstream ofs(DATA_USER_PATH);
	if(!ofs.is_open())
	{
		return;
	}
	
	for(unsigned int i=0; i<mgrArr.size(); i++)
	{
		ofs << mgrArr[i] << endl;//析取器(>>)　　从流中输入数据
	}
	
	ofs.close();
}

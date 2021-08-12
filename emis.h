#ifndef EMIS_H
#define EMIS_H

#include "manager_view_impl.h"
#define DATA_ID_PATH 	"./data/id.dat"
#define DATA_USER_PATH 	"./data/user.dat"
#define DATA_DEPT_PATH	"./data/dept.dat"

class EMIS
{
	ManagerView* mgrView;
	static EMIS emis;
	EMIS(void);
	EMIS(const EMIS& that) {}
public:
	~EMIS(void);
	static EMIS& singleEMIS(void);
	void login(void);
};

#endif//EMIS_H


// 单例模式：保证一个类仅有一个实例，并提供一个访问它的全局访问点，该实例被所有程序模块共享
// 定义一个单例类：
// 1、私有化它的构造函数，以防止外界创建单例类的对象
// 2、使用类私有静态指针变量指向类的唯一实例
// 3、使用一个公有的静态方法获取该实例
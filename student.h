#pragma once
#include <iostream>
#include <vector>
#include "identity.h"
#include "computerRoom.h"
#include "orderFile.h"

class Student : public Identity {
public:
	int student_id;

	// 默认构造
	Student();

	// 有参构造 学号、姓名、密码
	Student(int student_id, std::string name, std::string pwd);

	// 菜单界面
	virtual void openMenu();

	// 申请预约
	void applyOrder();

	// 查看自身预约
	void showMyOrder();

	// 查看所有预约
	void showAllOrder();

	// 取消预约
	void cancelOrder();

	// 机房容器
	std::vector<computerRoom> vCom;
};
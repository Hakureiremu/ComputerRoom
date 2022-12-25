#pragma once
#include <iostream>
#include "identity.h"

class Teacher : public Identity {
public:
	int teacher_id;

	// 默认构造
	Teacher();

	// 有参构造 工号、姓名、密码
	Teacher(int teacher_id, std::string name, std::string pwd);

	// 菜单界面
	virtual void openMenu();

	// 查看所有预约
	void showAllOrder();

	// 审核预约
	void validOrder();
};
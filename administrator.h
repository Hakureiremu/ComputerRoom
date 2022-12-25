#pragma once
#include <iostream>
#include <fstream>
#include "identity.h"
#include "globalFile.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
#include <algorithm>

void printStudent(Student& s);
void printTeacher(Teacher& t);

class Administrator : public Identity {
public:
	// 默认构造
	Administrator();

	// 有参构造 账号、密码
	Administrator(std::string name, std::string pwd);

	// 菜单界面
	virtual void openMenu();

	// 添加账号
	void addAccount();

	// 查看账号
	void showAccount();

	// 查看机房
	void showRoom();

	// 清空预约
	void clearOrder();

	// 初始化容器
	void initVector();

	// 检测重复，参数1是学号/工号，参数2是检测类型
	bool checkRepeat(int id, int type);

	// 学生容器
	std::vector<Student> vStu;

	// 老师容器
	std::vector<Teacher> vTea;

	// 机房容器
	std::vector<computerRoom> vCom;
};
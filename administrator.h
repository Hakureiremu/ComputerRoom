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
	// Ĭ�Ϲ���
	Administrator();

	// �вι��� �˺š�����
	Administrator(std::string name, std::string pwd);

	// �˵�����
	virtual void openMenu();

	// ����˺�
	void addAccount();

	// �鿴�˺�
	void showAccount();

	// �鿴����
	void showRoom();

	// ���ԤԼ
	void clearOrder();

	// ��ʼ������
	void initVector();

	// ����ظ�������1��ѧ��/���ţ�����2�Ǽ������
	bool checkRepeat(int id, int type);

	// ѧ������
	std::vector<Student> vStu;

	// ��ʦ����
	std::vector<Teacher> vTea;

	// ��������
	std::vector<computerRoom> vCom;
};
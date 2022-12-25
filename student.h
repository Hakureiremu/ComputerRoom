#pragma once
#include <iostream>
#include <vector>
#include "identity.h"
#include "computerRoom.h"
#include "orderFile.h"

class Student : public Identity {
public:
	int student_id;

	// Ĭ�Ϲ���
	Student();

	// �вι��� ѧ�š�����������
	Student(int student_id, std::string name, std::string pwd);

	// �˵�����
	virtual void openMenu();

	// ����ԤԼ
	void applyOrder();

	// �鿴����ԤԼ
	void showMyOrder();

	// �鿴����ԤԼ
	void showAllOrder();

	// ȡ��ԤԼ
	void cancelOrder();

	// ��������
	std::vector<computerRoom> vCom;
};
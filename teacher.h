#pragma once
#include <iostream>
#include "identity.h"

class Teacher : public Identity {
public:
	int teacher_id;

	// Ĭ�Ϲ���
	Teacher();

	// �вι��� ���š�����������
	Teacher(int teacher_id, std::string name, std::string pwd);

	// �˵�����
	virtual void openMenu();

	// �鿴����ԤԼ
	void showAllOrder();

	// ���ԤԼ
	void validOrder();
};
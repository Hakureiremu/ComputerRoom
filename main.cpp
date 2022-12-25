#include <iostream>
#include <fstream>
#include <string>
#include "identity.h"
#include "globalFile.h"
#include "administrator.h"
#include "student.h"
#include "teacher.h"
using namespace std;


// ����Ա��ݵ�¼
void adminMenu(Identity*& admin) {
	while (true) {
		// ����ָ��������๲ͬ�ӿ�
		admin->openMenu();
		// ������ָ��תΪ����ָ�룬�������������ӿ�
		Administrator* ad = (Administrator*)admin; 
		int select = 0; 
		cin >> select;
		// ����˺�
		if (select == 1)  {
			cout << "add account " << endl;
			ad->addAccount();
		}
		// �鿴�˺�
		else if (select == 2) {
			cout << "show account " << endl;
			ad->showAccount();
		}
		// �鿴����
		else if (select == 3) {
			cout << "show room " << endl;
			ad->showRoom();
		}
		// ���ԤԼ
		else if (select == 4) {
			cout << "clear order " << endl;
			ad->clearOrder();
		}
		// ע����¼
		else {
			cout << "log out" << endl;
			return; 
			//delete admin;
		}

	}
}

// ѧ����ݵ�¼
void studentMenu(Identity*& student) {
	while (true) {
		// ����ָ��������๲ͬ�ӿ�
		student->openMenu();
		// ������ָ��תΪ����ָ�룬�������������ӿ�
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		// ����ԤԼ
		if (select == 1) {
			cout << "add order " << endl;
			stu->applyOrder();
		}
		// �鿴����ԤԼ
		else if (select == 2) {
			cout << "show order " << endl;
			stu->showMyOrder();
		}
		// �鿴����ԤԼ
		else if (select == 3) {
			cout << "show all orders " << endl;
			stu->showAllOrder();
		}
		// ȡ��ԤԼ
		else if (select == 4) {
			cout << "clear order " << endl;
			stu->cancelOrder();
		}
		// ע����¼
		else {
			cout << "log out" << endl;
			return;
			//delete admin;
		}

	}
}

// ��ʦ��ݵ�¼
void teacherMenu(Identity*& teacher) {
	while (true) {
		// ����ָ��������๲ͬ�ӿ�
		teacher->openMenu();
		// ������ָ��תΪ����ָ�룬�������������ӿ�
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		// �鿴����ԤԼ
		if (select == 1) {
			cout << "show all orders " << endl;
			tea->showAllOrder();
		}
		// ���ԤԼ
		else if (select == 2) {
			cout << "show order " << endl;
			tea->validOrder();
		}
		// ע����¼
		else {
			cout << "log out" << endl;
			return;
			//delete admin;
		}

	}
}

// ��¼����
void LogIn(string fileName, int type) {

	// ����ָ�룬����ָ���������
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open()) {
		cout << "No File!" << endl;
		ifs.close();
		return; 
	}

	// ��ʼ��id�����ֺ�����
	int id = 0;
	string name;
	string pwd;

	// ����ж�
	if (type == 1) {
		cout << "Please enter student_ID: " << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "Please enter staff_ID: " << endl;
		cin >> id;
	}
	
	cout << "Please enter your name: " << endl;
	cin >> name;

	cout << "Please enter your password: " << endl;
	cin >> pwd;
	
	if (type == 1) {
		// ѧ�������֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
		/*	cout << fId << endl; 
			cout << fName << endl;
			cout << fPwd << endl; */
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "student log in successfully!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person); 
				return; 
			}
		}
	}

	else if (type == 2) {
		// ��ʦ�����֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "teacher log in successfully!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
		}
	}
	else {
		// ����Ա�����֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd){
			if (fName == name && fPwd == pwd) {
				cout << "admin log in successfully!" << endl;
				system("pause");
				system("cls");
				// ��������Ա����
				person = new Administrator(name, pwd);
				adminMenu(person);
				return;
			}
		}
	}
	cout << "Login Fail!" << endl;
	system("pause");
	system("cls");
	ifs.close();
}

int main() {
	while (true)
	{
		int select = 0;
		cout << "================== Welcome to Computer Room Reserving System ==================" << endl;
		cout << endl << "Please Enter Your Identity" << endl; 
		cout << "\t\t ----------------------------------------------\n";
		cout << "\t\t|                                             |\n";
		cout << "\t\t|                 1. Student                  |\n";
		cout << "\t\t|                                             |\n";
		cout << "\t\t|                                             |\n";
		cout << "\t\t|                 2. Teacher                  |\n";
		cout << "\t\t|                                             |\n";
		cout << "\t\t|                                             |\n";
		cout << "\t\t|               3. Administrator              |\n";
		cout << "\t\t|                                             |\n";
		cout << "\t\t|                                             |\n";
		cout << "\t\t|                  0. Quit                    |\n";
		cout << "\t\t|                                             |\n";
		cout << "\t\t|                                             |\n";
		cout << "\t\t ----------------------------------------------\n";
		cout << "Please enter: ";
		cin >> select; 
		switch (select) {
		case 1:
			LogIn(STUDENT_FILE, 1);
			break;
		case 2:
			LogIn(TEACHER_FILE, 2);
			break;
		case 3:
			LogIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "Thanks! Bye" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "Wrong input! Please re-enter !" << endl; 
			system("cls");
			break;
		}
		
	}
	system("pause");
	return 0; 
}
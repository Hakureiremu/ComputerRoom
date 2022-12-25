#include <iostream>
#include <fstream>
#include <string>
#include "identity.h"
#include "globalFile.h"
#include "administrator.h"
#include "student.h"
#include "teacher.h"
using namespace std;


// 管理员身份登录
void adminMenu(Identity*& admin) {
	while (true) {
		// 父类指针调用子类共同接口
		admin->openMenu();
		// 将父类指针转为子类指针，调用子类其他接口
		Administrator* ad = (Administrator*)admin; 
		int select = 0; 
		cin >> select;
		// 添加账号
		if (select == 1)  {
			cout << "add account " << endl;
			ad->addAccount();
		}
		// 查看账号
		else if (select == 2) {
			cout << "show account " << endl;
			ad->showAccount();
		}
		// 查看机房
		else if (select == 3) {
			cout << "show room " << endl;
			ad->showRoom();
		}
		// 清空预约
		else if (select == 4) {
			cout << "clear order " << endl;
			ad->clearOrder();
		}
		// 注销登录
		else {
			cout << "log out" << endl;
			return; 
			//delete admin;
		}

	}
}

// 学生身份登录
void studentMenu(Identity*& student) {
	while (true) {
		// 父类指针调用子类共同接口
		student->openMenu();
		// 将父类指针转为子类指针，调用子类其他接口
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		// 申请预约
		if (select == 1) {
			cout << "add order " << endl;
			stu->applyOrder();
		}
		// 查看自身预约
		else if (select == 2) {
			cout << "show order " << endl;
			stu->showMyOrder();
		}
		// 查看所有预约
		else if (select == 3) {
			cout << "show all orders " << endl;
			stu->showAllOrder();
		}
		// 取消预约
		else if (select == 4) {
			cout << "clear order " << endl;
			stu->cancelOrder();
		}
		// 注销登录
		else {
			cout << "log out" << endl;
			return;
			//delete admin;
		}

	}
}

// 老师身份登录
void teacherMenu(Identity*& teacher) {
	while (true) {
		// 父类指针调用子类共同接口
		teacher->openMenu();
		// 将父类指针转为子类指针，调用子类其他接口
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		// 查看所有预约
		if (select == 1) {
			cout << "show all orders " << endl;
			tea->showAllOrder();
		}
		// 审核预约
		else if (select == 2) {
			cout << "show order " << endl;
			tea->validOrder();
		}
		// 注销登录
		else {
			cout << "log out" << endl;
			return;
			//delete admin;
		}

	}
}

// 登录功能
void LogIn(string fileName, int type) {

	// 父类指针，用于指向子类对象
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open()) {
		cout << "No File!" << endl;
		ifs.close();
		return; 
	}

	// 初始化id、名字和密码
	int id = 0;
	string name;
	string pwd;

	// 身份判断
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
		// 学生身份验证
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
		// 教师身份验证
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
		// 管理员身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd){
			if (fName == name && fPwd == pwd) {
				cout << "admin log in successfully!" << endl;
				system("pause");
				system("cls");
				// 创建管理员对象
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
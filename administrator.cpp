#include "administrator.h"
#include <iostream>
using namespace std;
// 默认构造
Administrator::Administrator() {

}

// 有参构造 账号、姓名、密码
Administrator::Administrator(string name, string pwd) {
	this->m_name = name;
	this->m_password = pwd;
	
	//初始化容器， 获取文件中所有学生和老师的账号信息
	this->initVector();

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "fail to open " << endl;
		return; 
	}
	computerRoom com; 
	while (ifs >> com.m_ID && ifs >> com.m_Volume) {
		vCom.push_back(com); 
	}
	ifs.close();
	// cout << "Room num: " << vCom.size() << endl;
}

// 菜单界面
void Administrator::openMenu() {
	cout << "================== Welcome Administrator==================" << endl;
	cout << "\t\t ----------------------------------------------\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|               1. Add Acounts                |\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|               2. Show Accounts              |\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|                3. Show Room                 |\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|               4. Clear Order                |\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|               Other. Log Out                |\n";
	cout << "\t\t ----------------------------------------------\n";
	cout << "Please enter: ";
}

// 添加账号
void Administrator::addAccount() {
	cout << "Please enter the type of account you want to add:" << endl;
	cout << "1. student" << endl;
	cout << "2. teacher" << endl;
	string fileName; // 操作文件名
	string tip; // 协助显示信息
	ofstream ofs; 
	int select = 0;
	cin >> select; 
	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "Please enter student_id: ";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "Please enter staff_id: "; 
	}

	ofs.open(fileName, ios::out | ios::app);
	int id; //学号/工号
	string name; // 姓名
	string pwd; // 密码
	
	while(true){
		cout << tip << endl;
		cin >> id;
		bool is_repeat = checkRepeat(id, select);
		if (is_repeat) {
			cout << "repeat id input, please re-enter! " << endl;
		}
		else {
			break; 
		}
	}
	
	cout << "Please enter your name: " << endl;
	cin >> name;
	 
	cout << "Please enter your password: " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl; 
	cout << "Add Successfully! " << endl;
	system("pause");
	system("cls");
	ofs.close();
	// 添加完毕后重新初始化维持重复检测状态
	this->initVector();
}

// 查看账号
void Administrator::showAccount() {
	cout << "Please choose what to show: " << endl;
	cout << "1. show all students " << endl;
	cout << "2. show all teachers" << endl; 
	int select = 0;
	cin >> select;
	if (select == 1) {
		cout << "message of all students is below: " << endl; 
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else {
		cout << "message of all teachers is below:" << endl; 
		for_each(vTea.begin(), vTea.end(), printTeacher); 
	}
	system("pause");
	system("cls");
}

// 查看机房
void Administrator::showRoom() {
	cout << "The message of computer room is below: " << endl;
	for (vector<computerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << "Room number: " << it->m_ID << "Room volume: " << it->m_Volume << endl;
	}
	system("pause");
	system("cls");
}

// 清空预约
void Administrator::clearOrder() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "Clear successfully! " << endl; 
	system("pause");
	system("cls"); 
}

// 初始化操作
void Administrator::initVector() {
	vStu.clear();
	vTea.clear();
	ifstream ifs;

	// 读取学生信息和老师信息存入容器，用于去重操作
	// 读取学生
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "read file fail! " << endl;
		return; 
	}
	Student s;
	while (ifs >> s.student_id && ifs >> s.m_name && ifs >> s.m_password) {
		vStu.push_back(s);
	}
	cout << "The amount of students is: " << vStu.size() << endl;
	ifs.close();

	// 读取老师
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "read file fail! " << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.teacher_id && ifs >> t.m_name && ifs >> t.m_password) {
		vTea.push_back(t);
	}
	cout << "The amount of teachers is: " << vTea.size() << endl;
	ifs.close();
}

// 检测重复
bool Administrator::checkRepeat(int id, int type) {
	// 检测学生
	if (type == 1) {
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (id == it->student_id) {
				return true;
			}
		}
	}
	// 检测老师
	else {
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (id == it->teacher_id) {
				return true;
			}
		}
	}
	return false; 
}

// 打印账号信息
void printStudent(Student &s) {
	cout << "student_id: " << s.student_id << " student_name: " << s.m_name << endl;
}

void printTeacher(Teacher &t) {
	cout << "teacher_id: " << t.teacher_id << " teacher_name: " << t.m_name << endl;
}
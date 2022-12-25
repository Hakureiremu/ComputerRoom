#include "teacher.h"
#include "student.h"
#include "orderFile.h"
#include <vector>
using namespace std; 
// 将数字转换为星期
string daylist[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

// 默认构造
Teacher::Teacher() {

}

// 有参构造 学号、姓名、密码
Teacher::Teacher(int id, std::string name, std::string pwd) {
	this->teacher_id = id;
	this->m_name = name;
	this->m_password = pwd; 

}

// 菜单界面
void Teacher::openMenu() {
	cout << "\t\t================= Welcome " << this->m_name << "! ==================" << endl;
	cout << "\t\t ----------------------------------------------\n";
	cout << "\t\t|              1. Show All Orders             |\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|               2. Valid Order                |\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|               Other. Log Out                |\n";
	cout << "\t\t ----------------------------------------------\n";
	cout << "Please enter: ";
}

// 查看所有预约
void Teacher::showAllOrder() {
	orderFile od; 
	if (od.m_Size == 0) {
		cout << "no order record!" << endl;
		std::system("pause");
		std::system("cls");
		return;
	}

	for (int i = 0; i < od.m_Size; i++) {
		cout << i + 1 << ">> ";
		cout << "stuID: " << od.m_Data[i]["stuID"];
		cout << " name: " << od.m_Data[i]["stuName"];
		cout << " date: " << daylist[(stoi(od.m_Data[i]["date"]) - 1)];
		cout << " interval: " << (od.m_Data[i]["interval"] == "1" ? "morning" : "afternoon");
		cout << " roomID: " << od.m_Data[i]["roomID"];
		string status = " status: ";
		if (od.m_Data[i]["status"] == "1") {
			status += "under validation";
		}
		else if (od.m_Data[i]["status"] == "2") {
			status += "order success";
		}
		else if (od.m_Data[i]["status"] == "-1") {
			status += "order fail";
		}
		else {
			status += "order cancel";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

// 审核预约
void Teacher::validOrder() {
	orderFile od;
	if (od.m_Size == 0) {
		cout << "no order record!" << endl;
		std::system("pause");
		std::system("cls");
		return;
	}
	
	cout << "Here are orders to be valided: " << endl; 
	vector<int> v; 
	int j = 0; 
	for (int i = 0; i < od.m_Size; i++) {
		if (od.m_Data[i]["status"] == "1") {
			v.push_back(i);
			j++;
			cout << j << ">> ";
			cout << "stuID: " << od.m_Data[i]["stuID"];
			cout << " name: " << od.m_Data[i]["stuName"];
			cout << " date: " << daylist[(stoi(od.m_Data[i]["date"]) - 1)];
			cout << " interval: " << (od.m_Data[i]["interval"] == "1" ? "morning" : "afternoon");
			cout << " roomID: " << od.m_Data[i]["roomID"];
			cout << " under validation" << endl; 
		}
	}
	cout << "Please enter the num of the order you want to do validation, 0 to back" << endl;
	int select = 0;
	int ret = 0; 
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "Please enter the result of validation " << endl;
				cout << "1. pass " << endl;
				cout << "2. no pass " << endl;
				cin >> ret; 
				if (ret == 1) {
					od.m_Data[v[select - 1]]["status"] = "2";
				}
				else {
					od.m_Data[v[select - 1]]["status"] = "-1";
				}
				od.updateOrder();
				break; 
			}
		}
		cout << "wrong input, please re-enter" << endl;
	}
	system("pause");
	system("cls");
}


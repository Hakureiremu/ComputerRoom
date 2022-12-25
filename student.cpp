#include <iostream>
#include <fstream>
#include <vector>
#include "student.h"
#include "globalFile.h"
#include "computerRoom.h"
using namespace std;
// 将数字转换为星期
string day[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

// 默认构造
Student::Student() {
}

// 有参构造 学号、姓名、密码
Student::Student(int student_id, std::string name, std::string pwd) {
	this->student_id = student_id;
	this->m_name = name;
	this->m_password = pwd; 

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
void Student::openMenu() {
	cout << "\t\t================== Welcome " << this->m_name << "==================" <<endl;
	cout << "\t\t ----------------------------------------------\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|               1. Add Orders                 |\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|               2. Show Orders                |\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|              3. Show All Orders             |\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|               4. Cancel Order               |\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|               Other. Log Out                |\n";
	cout << "\t\t ----------------------------------------------\n";
	cout << "Please enter: ";
}

// 申请预约
void Student::applyOrder() {
	cout << "The open time of the computer room is from Monday to Friday" << endl; 
	cout << "Please enter the time of your order: " << endl; 
	cout << "1. Monday " << endl; 
	cout << "2. Tuesday " << endl;
	cout << "3. Wednesday " << endl;
	cout << "4. Thursday " << endl;
	cout << "5. Friday " << endl;

	int date = 0; // 日期
	int interval = 0; // 时间段
	int room = 0; // 机房编号

	while (true) {
		cin >> date; 
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "date out of range, please re-enter" << endl; 
	}
	cout << "please enter the period of the order： " << endl; 
	cout << "1. morning " << endl; 
	cout << "2. afternoon " << endl; 
	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "interval out of range, please re-enter" << endl;
	}
	
	cout << "please choose the room: " << endl;
	// 改进点：机房剩余容量的计算
	while(true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break; 
		}
		cout << "wrong enter, please re-enter: " << endl; 
	}
	
	cout << "order successfully! under the validation...." << endl; 

	ofstream ofs; 
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuID:" << this->student_id << " ";
	ofs << "stuName:" << this->m_name << " "; 
	ofs << "roomID:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	std::system("pause");
	std::system("cls");
}

// 查看自身预约
void Student::showMyOrder() {
	// cout << "********************************" << endl; 
	orderFile od; 
	if (od.m_Size == 0) {
		cout << "no order record!" << endl;
		std::system("pause");
		std::system("cls");
		return;
	}

	//cout << od.m_Data[0]["stuID"] << endl; 
	//cout << od.m_Data[0]["date"] << endl;
	//cout << od.m_Data[0]["interval"] << endl;
	//cout << od.m_Data[0]["roomID"] << endl;
	for (int i = 0; i < od.m_Size; i++) {
		// string to int 
		// string -> .c_str() -> const char*  -> atoi -> int
		if (this->student_id == atoi(od.m_Data[i]["stuID"].c_str())) {
			cout << "date: " << day[(stoi(od.m_Data[i]["date"])-1)];
			cout << " time: " << (od.m_Data[i]["interval"] == "1" ? "morning" : "afternoon");
			cout << " roomID: " << od.m_Data[i]["roomID"];
			// 1. under validation 2. success -1. fail 0. cancel 
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
	}
	std::system("pause");
	std::system("cls");
}

// 查看所有预约
void Student::showAllOrder() {
	orderFile od; 
	if (od.m_Size == 0) {
		cout << "No order recently " << endl; 
		std::system("pause");
		std::system("cls"); 
		return;
	}

	for (int i = 0; i < od.m_Size; i++) {
		cout << i + 1 << ">> ";
		cout << "stuID: " << od.m_Data[i]["stuID"];
		cout << " name: " << od.m_Data[i]["stuName"];
		cout << " date: " << day[(stoi(od.m_Data[i]["date"]) - 1)];
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
	std::system("pause");
	std::system("cls");
}

// 取消预约
void Student::cancelOrder() {
	orderFile od;
	// 取消的预约，其状态需为审核中或预约成功
	if (od.m_Size == 0) {
		cout << "No order recently " << endl;
		std::system("pause");
		std::system("cls");
		return;
	}
	cout << "Your can cancel your orders finished or under validation, please choose: " << endl; 
	
	vector<int> v; 
	int index = 1;
	int j = 0; 
	for (int i = 0; i < od.m_Size; i++) {
		// 先判断自身学号
		if (this->student_id == stoi(od.m_Data[i]["stuID"])) {
			// 筛选状态
			if (od.m_Data[i]["status"] == "1" || od.m_Data[i]["status"] == "2") {
				v.push_back(i);	
				j++; 
				cout << j << ">> ";
				cout << "stuID: " << od.m_Data[i]["stuID"];
				cout << " name: " << od.m_Data[i]["stuName"];
				cout << " date: " << day[(stoi(od.m_Data[i]["date"]) - 1)];
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
		}
	}

	// 
	cout << "Please enter the No. of order you want to cancel, 0 to back " << endl;
	int select = 0; 
	while (true) {
		cin >> select; 
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				od.m_Data[v[select - 1]]["status"] = "0"; 
				od.updateOrder();
				cout << "cancel successfully " << endl;
				break; 
			}
		}
		cout << "wrong input, please re-enter" << endl;
	}
	std::system("pause");
	std::system("cls");
}


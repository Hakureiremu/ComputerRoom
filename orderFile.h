#pragma once
#include <iostream>
using namespace std; 
#include "globalFile.h"
#include <fstream>
#include <string>
#include <map>

class orderFile {
public:
	orderFile();
	
	// 预约数量
	int m_Size;

	// 预约记录，使用嵌套map存储
	map<int, map<string, string>> m_Data; 

	// 更新预约记录
	void updateOrder();
};
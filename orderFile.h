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
	
	// ԤԼ����
	int m_Size;

	// ԤԼ��¼��ʹ��Ƕ��map�洢
	map<int, map<string, string>> m_Data; 

	// ����ԤԼ��¼
	void updateOrder();
};
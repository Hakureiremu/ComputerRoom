#include "orderFile.h"

orderFile::orderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	string date; // ����
	string interval; // ʱ���
	string stuID; // ѧ��
	string stuName; // ѧ������
	string roomID; // ��������
	string status;  // ���״̬

	this->m_Size = 0;
	while (ifs >> date && ifs >> interval && ifs >> stuID && ifs >> stuName && ifs >> roomID && ifs >> status ){
	/*	cout << date << endl; 
		cout << interval << endl;
		cout << stuID << endl;
		cout << stuName << endl;
		cout << roomID << endl;
		cout << status << endl;
		cout << endl;*/

		string key;
		string value; 
		map<string, string> m;

		// ��ȡ����
		int pos = date.find(":");
		if (pos != -1) {
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size()- pos -1);
			m.insert(make_pair(key, value));
			//cout << value << endl; 
			//switch(stoi(value)){
			//	case 1:
			//		m.insert(make_pair(key, "Monday"));
			//		break; 
			//	case 2:
			//		m.insert(make_pair(key, "Tuesday"));
			//		break;
			//	case 3:
			//		m.insert(make_pair(key, "Wednesday"));
			//		break;
			//	case 4:
			//		m.insert(make_pair(key, "Thursday"));
			//		break;
			//	case 5:
			//		m.insert(make_pair(key, "Friday"));
			//		break; 
			//	default:
			//		break;
			//}
		}

		// ��ȡʱ���
		pos = interval.find(":");
		// cout << "interval " << interval << endl;
		if (pos != -1) {
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		// ��ȡѧ��
		// cout << "stuID " << stuID << endl;
		pos = stuID.find(":");
		if (pos != -1) {
			key = stuID.substr(0, pos);
			value = stuID.substr(pos + 1, stuID.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		// ��ȡ����
		pos = stuName.find(":");
		if (pos != -1) {
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		// ��ȡ������
		pos = roomID.find(":");
		if (pos != -1) {
			key = roomID.substr(0, pos);
			value = roomID.substr(pos + 1, roomID.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		// ��ȡ���״̬
		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		// ��Сmap�����ŵ���map������
		this->m_Data.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();
	
	// test 
	/*for (map<int, map<string, string>>::iterator it = m_Data.begin(); it != m_Data.end(); it++) {
		cout << "No." << it->first << " value: " << endl; 
		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++) {
			cout << "key = " << mit->first << " value = " << mit->second << " "; 
		}
		cout << endl; 
	}*/
}

void orderFile::updateOrder() {
	if (this->m_Size == 0) {
		return; // ��ԤԼ��¼ֱ�ӷ���
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc); // ɾ��������д��
	for (int i = 0; i < this->m_Size; i++) {
		ofs << "date:" << this->m_Data[i]["date"] << " ";
		ofs << "interval:" << this->m_Data[i]["interval"] << " ";
		ofs << "stuID:" << this->m_Data[i]["stuID"] << " ";
		ofs << "stuName:" << this->m_Data[i]["stuName"] << " ";
		ofs << "roomID:" << this->m_Data[i]["roomID"] << " ";
		ofs << "status:" << this->m_Data[i]["status"] << " ";
	}
	ofs.close();
}



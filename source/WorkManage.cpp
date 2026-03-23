#include "WorkerManage.hpp"
#include <cstdlib>

// 构造函数
WorkerManage::WorkerManage()
{
	cout << "构造函数" << endl;
	fstream fs(FILENAME, ios::in);
	if (!fs.is_open())
	{
		cout << "文件不存在" << endl;
		this->worker_num = 0;
		this->worker_p_array = NULL;
		this->file_empty = true;
		fs.close();
		return;
	}

	if (fs.peek() == EOF)
	{
		cout << "文件存在，但记录为空" << endl;
		this->worker_num = 0;
		this->worker_p_array = NULL;
		this->file_empty = true;
		fs.close();
		return;
	}

	int wid;
	string name;
	int did;
	int num = 0;
	while (fs >> wid && fs >> name && fs >> did)
	{
		num++;
	}
	this->worker_num = num;
	this->worker_p_array = new Worker *[this->worker_num];
	int index = 0;
	fs.clear();
	fs.seekg(0, ios::beg);
	while (fs >> wid && fs >> name && fs >> did)
	{
		Worker *worker = NULL;
		if (did == 1)
		{
			worker = new Boss(wid, name, did);
		}
		if (did == 2)
		{
			worker = new Manager(wid, name, did);
		}
		if (did == 3)
		{
			worker = new Employee(wid, name, did);
		}
		this->worker_p_array[index] = worker;
		index++;
	}
	this->file_empty = false;
	fs.close();
}

void WorkerManage::show_menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManage::exit_system()
{
	cout << "欢迎下次使用，按回车键退出..." << endl;
	cin.ignore();
	cin.get();
	exit(0);
}

void WorkerManage::add_worker()
{
	cout << "请输入要添加的员工数量" << endl;
	int add_num = 0;
	cin >> add_num;
	if (add_num < 1)
		return;
	Worker **worker_p_array_temp = new Worker *[add_num + this->worker_num];
	for (int i = 0; i < this->worker_num; i++)
	{
		worker_p_array_temp[i] = this->worker_p_array[i];
	}
	for (int i = this->worker_num; i < add_num + this->worker_num; i++)
	{
		int id;
		string name;
		int did;
		cout << "请输入第" << i - this->worker_num + 1 << "个添加员工编号" << endl;
		cin >> id;
		cout << "请输入第" << i - this->worker_num + 1 << "个添加员工姓名" << endl;
		cin >> name;
		cout << "请输入第" << i - this->worker_num + 1 << "个添加员工职位编号" << endl;
		cin >> did;
		Worker *worker = NULL;
		switch (did)
		{
		case 1:
			worker = new Boss(id, name, did);
			break;
		case 2:
			worker = new Manager(id, name, did);
			break;
		case 3:
			worker = new Employee(id, name, did);
			break;
		}
		worker_p_array_temp[i] = worker;
	}
	delete[] this->worker_p_array; // 释放指针数组
	this->worker_p_array = worker_p_array_temp;
	worker_p_array_temp = NULL;
	this->worker_num = add_num + this->worker_num;
	this->save();
	this->file_empty = false;
	cout << "添加完成，按回车键继续" << endl;
	cin.ignore();
	cin.get();
	system("clear");
}

void WorkerManage::show_workers()
{
	if (this->worker_num == 0)
	{
		cout << "当前没有员工信息，按回车键继续" << endl;
		cin.ignore();
		cin.get();
		system("clear");
		return;
	}
	for (int i = 0; i < this->worker_num; i++)
	{
		this->worker_p_array[i]->show_info();
	}
	cout << "按回车键继续" << endl;
	cin.ignore();
	cin.get();
	system("clear");
}

int WorkerManage::find_worker(int id)
{
	for (int i = 0; i < this->worker_num; i++)
	{
		if (this->worker_p_array[i]->m_wID == id)
			return i;
	}
	return -1;
}

void WorkerManage::delete_worker()
{
	cout << "请输入要删除员工的编号" << endl;
	int delete_id;
	cin >> delete_id;
	int index = this->find_worker(delete_id);
	if (index == -1)
	{
		cout << "查无此人，按回车键继续" << endl;
		cin.ignore();
		cin.get();
		system("clear");
		return;
	}
	delete this->worker_p_array[index];
	for (int i = index; i < this->worker_num - 1; i++)
	{
		this->worker_p_array[i] = this->worker_p_array[i + 1];
	}
	this->worker_num--;
	this->save();
	cout << "删除员工成功, 按回车键继续" << endl;
	cin.ignore();
	cin.get();
	system("clear");
	return;
}

void WorkerManage::save()
{
	fstream fs(FILENAME, ios::out);
	for (int i = 0; i < this->worker_num; i++)
	{
		fs << this->worker_p_array[i]->m_wID << "\t"
		   << this->worker_p_array[i]->m_Name << "\t"
		   << this->worker_p_array[i]->m_dID << endl;
	}
	fs.close();
}

void WorkerManage::modify()
{
	cout << "请输入要修改人员编号" << endl;
	int wid;
	cin >> wid;
	int index = this->find_worker(wid);
	if (index == -1)
	{
		cout << "要修改的员工不存在" << endl;
		return;
	}
	cout << "请输入新编号" << endl;
	int id;
	cin >> id;
	cout << "请输入新姓名" << endl;
	string name;
	cin >> name;
	cout << "请输入新部门编号" << endl;
	int did;
	cin >> did;
	this->worker_p_array[index]->m_wID = id;
	this->worker_p_array[index]->m_Name = name;
	this->worker_p_array[index]->m_dID = did;
	cout << "修改成功，按回车返回" << endl;
	this->save();
	cin.ignore();
	cin.get();
	system("clear");
}

void WorkerManage::look()
{
	cout << "请输入编号或者姓名" << endl;
	string input;
	cin >> input;
	bool allnumber = true;
	for (unsigned char c : input)
	{
		if (!isdigit(c))
		{
			allnumber = false;
		}
	}
	if (allnumber)
	{
		// 按编号查找
		int index = this->find_worker(stoi(input));
		this->worker_p_array[index]->show_info();
	}
	else
	{
		// 按姓名查找
		for (int i = 0; i < this->worker_num; i++)
		{
			if (this->worker_p_array[i]->m_Name == input)
			{
				this->worker_p_array[i]->show_info();
			}
		}
	}
	cin.ignore();
	cin.get();
	system("clear");
}

void WorkerManage::sort()
{
	int sort_flag = 0;
	cout << "升序输入1, 降序输入0" << endl;
	cin >> sort_flag;
	if (sort_flag == 1)
	{
		// 冒泡排序实现升序
		for (int i = 0; i < this->worker_num - 1; i++)
		{
			for (int j = 0; j < this->worker_num - i - j; j++)
			{
				if (this->worker_p_array[j]->m_wID > this->worker_p_array[j + 1]->m_wID)
				{
					Worker *temp = this->worker_p_array[j];
					this->worker_p_array[j] = this->worker_p_array[j + 1];
					this->worker_p_array[j + 1] = temp;
					temp = NULL;
				}
			}
		}
	}
	else
	{
		// 选择排序实现降序
		for (int i = 0; i < this->worker_num - 1; i++)
		{
			int max_index = i;
			for (int j = i + 1; j < this->worker_num; j++)
			{
				if (this->worker_p_array[j]->m_wID > this->worker_p_array[i]->m_wID)
				{
					max_index = j;
				}
			}
			Worker *temp = this->worker_p_array[i];
			this->worker_p_array[i] = this->worker_p_array[max_index];
			this->worker_p_array[max_index] = temp;
			temp = NULL;
		}
	}
	this->save();
	cout << "排序完成，回车继续" << endl;
	cin.ignore();
	cin.get();
	system("clear");
}

void WorkerManage::clean()
{
	cout << "确认吗 1-确认，0-取消" << endl;
	int select = 0;
	cin >> select;
	if (select == 0)
	{
		return;
	}
	else
	{
		fstream fs(FILENAME, ios::out | ios::trunc); // 删除文件
		fs.close();
		if (this->worker_p_array != NULL)
		{
			for (int i = 0; i < this->worker_num; i++)
			{
				delete this->worker_p_array[i];
			}
			delete[] this->worker_p_array;
			this->worker_p_array = NULL;
		}
		this->worker_num = 0;
		this->file_empty = true;
	}
	cout << "文件已清空成功,按回车继续" << endl;
	cin.ignore();
	cin.get();
	system("clear");
}

WorkerManage::~WorkerManage()
{
	if (this->worker_p_array != NULL)
	{
		for (int i = 0; i < this->worker_num; i++)
		{
			delete this->worker_p_array[i];
			this->worker_p_array[i] = NULL;
		}
		delete[] this->worker_p_array;
		this->worker_p_array = NULL;
	}
}
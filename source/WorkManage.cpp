#include "WorkerManage.hpp"
#include <cstdlib>

// 构造函数
WorkerManage::WorkerManage()
{
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
	cout << "删除员工成功, 按回车键继续" << endl;
	cin.ignore();
	cin.get();
	system("clear");
	return;
}

WorkerManage::~WorkerManage()
{
}
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void test01(){
    fstream fs;
    fs.open("test.txt", ios::out);
    fs<<"哈哈哈哈"<<endl;
    fs.close();
}
void test02(){
    fstream fs;
    fs.open("test.txt", ios::in);
    if(!fs.is_open()){
        cout<<"文件打开失败"<<endl;
    }

    // 打开方式1
    string buf3;
    while(getline(fs,buf3)){
        cout<<buf3<<endl;
    }
    fs.clear();
    fs.seekg(0);

    // 打开方式2
    char buf1[1024] = {0};
    while(fs>>buf1){
        cout<<buf1<<endl;
    }
    fs.clear();
    fs.seekg(0);

    // 打开方式3
    char buf2[1024] = {0};
    while (fs.getline(buf2, sizeof(buf2))){
        cout<<buf2<<endl;
    }
    fs.close();

}
class Person{
    public:
        int m_age;
        char m_name[64];
};

void test03(){
    Person p = { 78, "张三"};
    fstream fs("test2.txt", ios::out | ios::binary);
    fs.write((const char*)&p,sizeof(p));
    fs.close();
    fstream fs2("test2.txt", ios::in | ios::binary);
    if(!fs2.is_open()){
        cout<<"打开失败"<<endl;
        return;
    }
    Person p2;
    fs2.read((char*)&p2, sizeof(p2));
    fs2.close();
    cout<<p2.m_name<<p2.m_age<<endl;
}


int main(){
    //test01();
    //test02();
    test03();
    return 0;
}
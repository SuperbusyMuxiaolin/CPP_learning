#include<iostream>
using namespace std;

// 抽象的三个零件类

class AbstractCPU{
    public:
    virtual void calculate()=0;
    ~AbstractCPU(){}
};

class AbstractGPU{
    public:
    virtual void display()=0;
    ~AbstractGPU(){}
};

class AbstractMemory{
    public:
    virtual void store()=0;
    ~AbstractMemory(){}
};

// 具体厂商的三个零件
class intelCPU : public AbstractCPU{
    void calculate(){
        cout<<"intel CPU 开始计算"<<endl;
    }
};
class intelGPU : public AbstractGPU{
    void display(){
        cout<<"intel GPU 开始显示"<<endl;
    }
};
class intelMemory : public AbstractMemory{
    void store(){
        cout<<"intel Memory 开始存储"<<endl;
    }
};

class AMDCPU : public AbstractCPU{
    void calculate(){
        cout<<"AMD CPU 开始计算"<<endl;
    }
};
class AMDGPU : public AbstractGPU{
    void display(){
        cout<<"AMD GPU 开始显示"<<endl;
    }
};
class AMDMemory : public AbstractMemory{
    void store(){
        cout<<"AMD Memory 开始存储"<<endl;
    }
};

//电脑类
class Computer{
    public:
    Computer(AbstractCPU* cpu, AbstractGPU* gpu, AbstractMemory* m){
        m_cpu = cpu;
        m_gpu = gpu;
        m_memory = m;
    }
    void work(){
        m_cpu->calculate();
        m_gpu->display();
        m_memory->store();
    }
    ~Computer(){
        if(m_cpu != NULL){
            delete m_cpu;
            m_cpu = NULL;
        }
        if(m_gpu != NULL){
            delete m_gpu;
            m_gpu = NULL;
        }
        if(m_memory != NULL){
            delete m_memory;
            m_memory = NULL;
        }
    }
    private:
    AbstractCPU* m_cpu;
    AbstractGPU* m_gpu;
    AbstractMemory* m_memory;

};

void test01(){
    Computer co(new intelCPU, new intelGPU, new intelMemory);
    co.work();
}


int main(){
    test01();
    return 0;
}
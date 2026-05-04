#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

struct BankAccount
{
    BankAccount(size_t account_id, std::string name, double balance)
        : account_id(account_id), name(name), balance(balance)
    {
    }
    void printBalance()
    {
        std::cout << name << "账户余额为:" << balance << std::endl;
    }
    size_t account_id;
    std::string name;
    double balance;
    std::mutex mtx; // 每一个账户都有一个锁，每一个转账操作涉及两个锁
};

void bank_transfer(BankAccount &from, BankAccount &to, double amount)
{
    std::this_thread::sleep_for(std::chrono::seconds(1)); // 模拟等待
    // from.mtx.lock();
    // to.mtx.lock();
    std::lock(from.mtx, to.mtx); // 直接同时加锁，一个加锁失败，就全部释放
    if (from.balance >= amount)
    {
        from.balance -= amount;
        to.balance += amount;
        std::cout << "从" << from.name << "转账到" << to.name << "共计" << amount << "元!" << std::endl;
    }
    else
    {
        std::cout << from.name << "账户余额不足!" << std::endl;
    }
    to.mtx.unlock();
    from.mtx.unlock();
}
void test()
{
    BankAccount accountA(1001, "张三", 1000);
    BankAccount accountB(1002, "李四", 5000);
    std::thread t1(bank_transfer, std::ref(accountA), std::ref(accountB), 200);
    std::thread t2(bank_transfer, std::ref(accountB), std::ref(accountA), 100);
    t1.join();
    t2.join();
    accountA.printBalance();
    accountB.printBalance();
}

int main()
{
    test();
}
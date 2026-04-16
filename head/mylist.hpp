#include <iostream>
using namespace std;
#include <vector>

class Node
{
public:
    Node(int val)
    {
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
    int val;
    Node *prev;
    Node *next;
};

class MyLinkedList
{
public:
    MyLinkedList()
    {
        v_head = new Node(-1);
        v_tail = new Node(-2);
        v_head->next = v_tail;
        v_tail->prev = v_head;
        this->size = 0;
    }

    MyLinkedList(std::vector<int> &v)
    {
        v_head = new Node(-1);
        v_tail = new Node(-2);
        v_head->next = v_tail;
        v_tail->prev = v_head;
        this->size = 0;
        Node *p = v_tail->prev;
        // p<->v_tail
        for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
        {
            Node *newnode = new Node(*it);
            p->next = newnode;
            newnode->prev = p;
            newnode->next = v_tail;
            v_tail->prev = newnode;
            // p<->newnode<->v_tail
            p = p->next;
            this->size++;
        }
    }

    int get(int index)
    {
        if (index > size - 1 || index < 0)
        {
            return -1;
        }
        Node *p = v_head;
        for (int i = -1; i < index; i++)
        {
            p = p->next;
        }
        return p->val;
    }

    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }
    void addAtTail(int val)
    {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index > size || index < 0)
        {
            cout << "索引越界" << endl;
            return;
        }
        Node *p = v_head;
        for (int i = -1; i < index - 1; i++)
        {
            p = p->next;
        }
        Node *newnode = new Node(val);
        newnode->next = p->next;
        newnode->prev = p;

        p->next->prev = newnode;
        p->next = newnode;
        this->size++;
    }

    void deleteAtIndex(int index)
    {
        if (index > size - 1 || index < 0)
        {
            cout << "索引越界" << endl;
            return;
        }
        Node *p = v_head;
        for (int i = -1; i < index - 1; i++)
        {
            p = p->next;
        }
        Node *deletenode = p->next;
        p->next = deletenode->next;
        deletenode->next->prev = p;

        deletenode->next = nullptr;
        deletenode->prev = nullptr;
        delete deletenode;
        this->size--;
    }
    void showall()
    {
        Node *p = v_head->next;
        while (p != v_tail)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
    ~MyLinkedList()
    {
        Node *p = v_head;
        while (p != nullptr)
        {
            Node *deletenode = p;
            p = p->next;
            delete deletenode;
        }
    }

private:
    Node *v_head;
    Node *v_tail;
    int size;
};

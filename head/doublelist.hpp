#include <iostream>
#include <string>
#include <stdexcept>

// 在处理删除和添加时，最好先赋值前驱和后驱节点，再删除或添加节点，这样就不需要考虑赋值顺序
template <typename E>
class MyLinkedList
{
    // 虚拟头尾节点
    struct Node
    {
        E val;
        Node *next;
        Node *prev;

        Node(E value) : val(value), next(nullptr), prev(nullptr) {}
    };

    Node *head;
    Node *tail;
    int size;

public:
    // 构造函数初始化虚拟头尾节点
    MyLinkedList()
    {
        head = new Node(E());
        tail = new Node(E());
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    ~MyLinkedList()
    {
        while (size > 0)
        {
            removeFirst();
        }
        delete head;
        delete tail;
    }

    // ***** 增 *****

    void addLast(E e)
    {
        Node *x = new Node(e);
        Node *temp = tail->prev;
        // temp <-> tail

        temp->next = x;
        x->prev = temp;
        // temp <-> x

        x->next = tail;
        tail->prev = x;
        // temp <-> x <-> tail
        size++;
    }

    void addFirst(E e)
    {
        Node *x = new Node(e);
        Node *temp = head->next;
        // head <-> temp
        temp->prev = x;
        x->next = temp;

        head->next = x;
        x->prev = head;
        // head <-> x <-> temp
        size++;
    }

    void add(int index, E element)
    {
        checkPositionIndex(index);
        if (index == size)
        {
            addLast(element);
            return;
        }

        // 找到 index 对应的 Node
        Node *p = getNode(index);
        Node *temp = p->prev;
        // temp <-> p

        // 新要插入的 Node
        Node *x = new Node(element);

        p->prev = x;
        temp->next = x;

        x->prev = temp;
        x->next = p;

        // temp <-> x <-> p

        size++;
    }

    // ***** 删 *****

    E removeFirst()
    {
        if (size < 1)
        {
            throw out_of_range("No elements to remove");
        }
        // 虚拟节点的存在使得我们不用考虑空指针的问题
        Node *x = head->next;
        Node *temp = x->next;
        // head <-> x <-> temp
        head->next = temp;
        temp->prev = head;

        E val = x->val;
        delete x;
        // head <-> temp

        size--;
        return val;
    }

    E removeLast()
    {
        if (size < 1)
        {
            throw out_of_range("No elements to remove");
        }
        Node *x = tail->prev;
        Node *temp = tail->prev->prev;
        // temp <-> x <-> tail

        tail->prev = temp;
        temp->next = tail;

        E val = x->val;
        x->prev = nullptr;
        x->next = nullptr;
        delete x;
        // temp <-> tail

        size--;
        return val;
    }

    E remove(int index)
    {
        checkElementIndex(index);
        // 找到 index 对应的 Node
        Node *x = getNode(index);
        Node *prev = x->prev;
        Node *next = x->next;
        // prev <-> x <-> next
        prev->next = next;
        next->prev = prev;

        E val = x->val;
        x->prev = nullptr;
        x->next = nullptr;
        delete x;
        // prev <-> next

        size--;
        return val;
    }

    // ***** 查 *****

    E get(int index)
    {
        checkElementIndex(index);
        // 找到 index 对应的 Node
        Node *p = getNode(index);

        return p->val;
    }

    E getFirst()
    {
        if (size < 1)
        {
            throw out_of_range("No elements in the list");
        }

        return head->next->val;
    }

    E getLast()
    {
        if (size < 1)
        {
            throw out_of_range("No elements in the list");
        }

        return tail->prev->val;
    }

    // ***** 改 *****

    E set(int index, E val)
    {
        checkElementIndex(index);
        // 找到 index 对应的 Node
        Node *p = getNode(index);

        E oldVal = p->val;
        p->val = val;

        return oldVal;
    }

    // ***** 其他工具函数 *****

    int getSize() const
    {
        return size;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    void display()
    {
        cout << "size = " << size << endl;
        for (Node *p = head->next; p != tail; p = p->next)
        {
            cout << p->val << " <-> ";
        }
        cout << "nullptr" << endl;
        cout << endl;
    }

private:
    Node *getNode(int index)
    {
        checkElementIndex(index);
        Node *p = head->next;
        if (index < size / 2)
        {
            p = head->next;
            for (int i = 0; i < index; i++)
            {
                p = p->next;
            }
        }
        else
        {
            p = tail->prev;
            for (int i = size - 1; i > index; i--)
            {
                p = p->prev;
            }
        }
        return p;
    }

    bool isElementIndex(int index) const
    {
        return index >= 0 && index < size;
    }

    bool isPositionIndex(int index) const
    {
        return index >= 0 && index <= size;
    }

    // 检查 index 索引位置是否可以存在元素
    void checkElementIndex(int index) const
    {
        if (!isElementIndex(index))
            throw out_of_range("Index: " + to_string(index) + ", Size: " + to_string(size));
    }

    // 检查 index 索引位置是否可以添加元素
    void checkPositionIndex(int index) const
    {
        if (!isPositionIndex(index))
            throw out_of_range("Index: " + to_string(index) + ", Size: " + to_string(size));
    }
};

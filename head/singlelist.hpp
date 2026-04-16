template <typename E>
class MyLinkedList2
{
private:
    // 节点结构
    struct Node
    {
        E val;
        Node *next;

        Node(E value) : val(value), next(nullptr) {}
    };
    // 虚拟头节点
    Node *head;
    // 实际的尾部节点引用
    Node *tail;
    int size_;

public:
    MyLinkedList2()
    {
        head = new Node(E());
        tail = head;
        size_ = 0;
    }

    ~MyLinkedList2()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    void addFirst(E e)
    {
        Node *newNode = new Node(e);
        newNode->next = head->next;
        head->next = newNode;
        if (size_ == 0)
        {
            tail = newNode;
        }
        size_++;
    }

    void addLast(E e)
    {
        Node *newNode = new Node(e);
        tail->next = newNode;
        tail = newNode;
        size_++;
    }

    void add(int index, E element)
    {
        checkPositionIndex(index);

        if (index == size_)
        {
            addLast(element);
            return;
        }

        Node *p = head->next;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        Node *temp = p->next;
        // p <-> temp,temp 是 index 位置的节点
        Node *newNode = new Node(element);
        p->next = newNode;
        newNode->next = temp;
        // p <-> newNode <-> temp
        size_++;
    }

    E removeFirst()
    {
        if (isEmpty())
        {
            throw out_of_range("No elements to remove");
        }
        Node *first = head->next;
        // head <-> first <-> second
        head->next = first->next;
        if (size_ == 1)
        {
            tail = head;
        }
        size_--;
        E val = first->val;
        delete first;
        return val;
    }

    E removeLast()
    {
        if (isEmpty())
        {
            throw out_of_range("No elements to remove");
        }

        Node *prev = head;
        while (prev->next != tail)
        {
            prev = prev->next;
        }
        E val = tail->val;
        delete tail;
        prev->next = nullptr;
        tail = prev;
        size_--;
        return val;
    }

    E remove(int index)
    {
        checkElementIndex(index);
        if (index == size_ - 1)
        {
            return removeLast();
        }

        Node *p = head->next;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        // p<->nodeToRemove
        Node *nodeToRemove = p->next;
        p->next = nodeToRemove->next;
        size_--;
        E val = nodeToRemove->val;
        delete nodeToRemove;
        return val;
    }

    // ***** 查 *****

    E getFirst()
    {
        if (isEmpty())
        {
            throw out_of_range("No elements in the list");
        }
        return head->next->val;
    }

    E getLast()
    {
        if (isEmpty())
        {
            throw out_of_range("No elements in the list");
        }
        return tail->val;
    }

    E get(int index)
    {
        checkElementIndex(index);
        Node *p = getNode(index);
        return p->val;
    }

    // ***** 改 *****

    E set(int index, E element)
    {
        checkElementIndex(index);
        Node *p = getNode(index);

        E oldVal = p->val;
        p->val = element;

        return oldVal;
    }

    // ***** 其他工具函数 *****
    int size()
    {
        return size_;
    }

    bool isEmpty()
    {
        return size_ == 0;
    }

private:
    bool isElementIndex(int index)
    {
        return index >= 0 && index < size_;
    }

    bool isPositionIndex(int index)
    {
        return index >= 0 && index <= size_;
    }

    // 检查 index 索引位置是否可以存在元素
    void checkElementIndex(int index)
    {
        if (!isElementIndex(index))
        {
            throw out_of_range("Index: " + to_string(index) + ", size_: " + to_string(size_));
        }
    }

    // 检查 index 索引位置是否可以添加元素
    void checkPositionIndex(int index)
    {
        if (!isPositionIndex(index))
        {
            throw out_of_range("Index: " + to_string(index) + ", size_: " + to_string(size_));
        }
    }

    // 返回 index 对应的 Node
    // 注意：请保证传入的 index 是合法的
    Node *getNode(int index)
    {
        Node *p = head->next;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
        }
        return p;
    }
};
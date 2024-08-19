#ifndef QUEUE_TEMPLATE_H
#define QUEUE_TEMPLATE_H
#include <iostream>
#define SUCCESS 1
#define FAILURE -1
using namespace std;

template <typename T>
class queueNode
{
public:
    T value;
    queueNode<T> *next;
    queueNode<T> *pre;
};

template <typename T>
class queue
{
public:
    queue() : _size{0}, head{nullptr}, tail{nullptr} {};
    ~queue()
    {
        cout << "cleanup queue" << endl;
        clear();
    };

    int size();        // 返回队列长度
    bool isEmpty();    // 判断队列是否为空
    void push(T elem); // 入队
    T pop();           // 出队
    T front();         // 获取队头元素
    void clear();      // 清空队列
private:
    queueNode<T> *head;
    queueNode<T> *tail;
    int _size;

    int Size() const;
    bool IsEmpty() const;
    void Push(T elem);
    T Pop();
    T Front();
    void Clear();
};
/**
 * 获取当前队列长度
 */
template <typename T>
int queue<T>::size()
{
    return Size();
}
template <typename T>
int queue<T>::Size() const
{
    return _size;
}

/**
 * 判断队列是否为空
 */
template <typename T>
bool queue<T>::isEmpty()
{
    return IsEmpty();
}
template <typename T>
bool queue<T>::IsEmpty() const
{
    return _size == 0;
}

/**
 * 入队
 * 加到尾部
 */
template <typename T>
void queue<T>::push(T elem)
{
    Push(elem);
}
template <typename T>
void queue<T>::Push(T elem)
{
    if (IsEmpty())
    {
        head = new queueNode<T>;
        tail = head;
        head = tail;
        tail->value = elem;
    }
    else
    {
        queueNode<T> *dummyNode = new queueNode<T>;
        dummyNode->value = elem;
        tail->next = dummyNode;
        dummyNode->pre = tail;
        tail = dummyNode;
    }
    _size++;
}

/**
 * 出队
 * 弹出第一个元素
 */
template <typename T>
T queue<T>::pop()
{
    if (IsEmpty())
        throw runtime_error("queue is empty.");
    return Pop();
}
template <typename T>
T queue<T>::Pop()
{
    T val = head->value;
    if (head == tail)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        queueNode<T> *dummyNode = head->next;
        delete head;
        head = dummyNode;
    }
    _size--;
    return val;
}

/**
 * 取队首元素
 */
template <typename T>
T queue<T>::front()
{
    return Front();
}
template <typename T>
T queue<T>::Front()
{
    if (IsEmpty())
    {
        return FAILURE;
    }
    else
    {
        return head->value;
    }
}
/**
 * 清空队列
 */
template <typename T>
void queue<T>::clear()
{
    Clear();
}
template <typename T>
void queue<T>::Clear()
{
    while (!IsEmpty())
    {
        Pop();
    }
    head = nullptr;
    tail = nullptr;
}

#endif
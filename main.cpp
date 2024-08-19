#include "./head/queue_template.h"
#include <iostream>
#include <cassert>
using namespace std;
void testQueue()
{
    // 创建一个整数类型的队列
    queue<int> q;
    // 测试队列是否为空
    assert(q.isEmpty() == true);

    // 入队操作
    q.push(1);
    q.push(2);
    q.push(3);

    // 检查队列长度
    assert(q.size() == 3);

    // 检查队头元素
    assert(q.front() == 1);

    // 出队操作
    assert(q.pop() == 1);
    assert(q.size() == 2);

    // 再次检查队头元素
    assert(q.front() == 2);

    // 出队最后一个元素
    assert(q.pop() == 2);
    assert(q.size() == 1);

    // 检查队头元素
    assert(q.front() == 3);
    assert(q.pop() == 3);
    assert(q.size() == 0);

    // 清空队列
    q.clear();

    // 检查队列是否为空
    assert(q.isEmpty() == true);

    std::cout << "pass all testing!" << std::endl;
}

int main()
{
    testQueue();
    return 0;
}
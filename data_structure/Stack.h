//
// Created by shinoship on 2025/9/29.
//

#ifndef ALGORITHMS_STACK_H
#define ALGORITHMS_STACK_H
#include <stdexcept>
#include <vector>
using namespace std;
#define MAX_SIZE 100

class Stack {
    public:
    int data[MAX_SIZE];// 存储元素的数组
    int top;// 栈顶指针，-1 表示空栈

    // 构造函数：初始化栈为空
    Stack() : top(-1) {}

    bool isEmpty() const {
        return top == -1;
    }

    void push(int x) {
        data[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            throw underflow_error("Stack is empty!");
        }
        int value = data[top--];
        return value;
    }
};

#endif //ALGORITHMS_STACK_H
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
};

//初始化
void InitStack(Stack &s) {
    s.top = -1;
}

//判断栈空
bool isEmptyStack(Stack s) {
    if (s.top == -1) return true;
    else return false;
}

//进栈
bool Push(Stack &s, int x) {
    if (s.top == MAX_SIZE - 1) return false;//栈满
    s.data[++s.top] = x;
    return true;
}

//出栈
bool Pop(Stack &s) {
    if (s.top == -1) return false;//栈空
    x =s.data[top--];
    return true;
}

//读栈顶元素
bool getTop(Stack s, int &x) {
    if (s.top == -1) return false;//栈空
    x = s.data[s.top];
    return true;
}

#endif //ALGORITHMS_STACK_H
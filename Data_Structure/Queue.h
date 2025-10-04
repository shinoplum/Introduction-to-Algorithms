//
// Created by shinoship on 2025/9/29.
//

#ifndef ALGORITHMS_QUEUE_H
#define ALGORITHMS_QUEUE_H
#define MAX_SIZE 100
using namespace std;

class Queue {
    public:
    int data[MAX_SIZE];
    int front;
    int rear;
};

//初始化
void InitQueue(Queue &Q) {
    Q.rear = Q.front = 0;
}

//判队空
bool isEmptyQueue(Queue Q) {
    if (Q.rear == Q.front) {//队空条件
        return true;
    }
    return false;
}

//入队
bool EnQueue(Queue &Q, int x) {
    if ((Q.rear + 1) % MAX_SIZE == Q.front) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MAX_SIZE;
    return true;
}

//出队
bool DeQueue(Queue &Q, int &x) {
    if (Q.rear == Q.front) return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAX_SIZE;
    return true;
}

#endif //ALGORITHMS_QUEUE_H
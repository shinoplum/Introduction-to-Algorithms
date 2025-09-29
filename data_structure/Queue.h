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

//
void InitQueue(Queue &Q) {
    Q.rear = Q.front = 0;//
}

//
bool isEmptyQueue(Queue Q) {
    if (Q.rear == Q.front) {
        return true;
    }
    return false;
}

#endif //ALGORITHMS_QUEUE_H
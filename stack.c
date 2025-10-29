#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;
Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(sizeof(int) * capacity);
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = capacity;
    return q;
}
void enqueue(Queue* q, int x) {
    if (q->size == q->capacity) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = x;
    q->size++;
}
int dequeue(Queue* q) {
    if (q->size == 0) return -1;
    int val = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return val;
}
int front(Queue* q) {
    if (q->size == 0) return -1;
    return q->data[q->front];
}
bool isEmptyQueue(Queue* q) {
    return q->size == 0;
}
typedef struct {
    Queue* q1;
    Queue* q2;
} MyStack;
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1 = createQueue(100);
    stack->q2 = createQueue(100);
    return stack;
}
void myStackPush(MyStack* obj, int x) {
    enqueue(obj->q2, x);
    while (!isEmptyQueue(obj->q1)) {
        enqueue(obj->q2, dequeue(obj->q1));
    }
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}
int myStackPop(MyStack* obj) {
    return dequeue(obj->q1);
}
int myStackTop(MyStack* obj) {
    return front(obj->q1);
}
bool myStackEmpty(MyStack* obj) {
    return isEmptyQueue(obj->q1);
}
void myStackFree(MyStack* obj) {
    free(obj->q1->data);
    free(obj->q2->data);
    free(obj->q1);
    free(obj->q2);
    free(obj);
}

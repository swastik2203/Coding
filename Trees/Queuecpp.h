// Queuecpp Header File
#include <stdio.h>

template <class T>
class Node
{
public:
    Node<T> *lchild;
    T  data;
    Node<T> *rchild;
};


template <class T>
class Queue
{
private:
    int size;
    int front;
    int rear;
    Node<T> **Q; // double pointer

public:
    Queue()
    {
        size = 10;
        front = rear = -1;
        Q = new Node<T> *[size];
    };
    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        Q = new Node<T> *[this->size];
    };
    void enqueue(Node<T> *x);
    Node<T> *dequeue();
    int isEmpty();
};

template <class T>
void Queue<T>::enqueue(Node<T> *x)
{
    if ((rear + 1) % size == front)
        printf("Queue is Full");
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

template <class T>
Node<T> *Queue<T>::dequeue()
{
    Node<T> *x = NULL;

    if (front == rear)
        printf("Queue is Empty\n");
    else
    {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

template <class T>
int Queue<T>::isEmpty()
{
    return front == rear;
}
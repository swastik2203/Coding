// Queue using CPP

#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:
    int front;
    int rear;
    int size;
    T *Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new T[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this -> size = size;
        Q = new T[this->size];
    }

    void enqueue(T x);
    T dequeue();
    void Display();
};

template <class T>
void Queue<T>::enqueue(T x)
{
    if (rear == size - 1)
        printf("Queue Full\n");
    else
    {
        rear++;
        Q[rear] = x;
    }
}

template <class T>
T Queue<T>::dequeue()
{
    int x = -1;
    if (front == rear)
        printf("Queue is Empty\n");
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}

template <class T>
void Queue<T>::Display()
{
    for (int i = front + 1; i <= rear; i++)
        cout<<Q[i]<<' ';

    printf("\n");
}


int main()
{
    Queue<char> q(5);

    q.enqueue(48);
    q.enqueue(49);
    q.enqueue(50);

    q.Display();
    return 0;
}
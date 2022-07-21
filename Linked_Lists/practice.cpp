// practising linked list

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void Display(struct Node **p)  //(call by address) receiving node pointer adddress using double pointer
{
    while (p != NULL)
    {
        cout<<(**p).data<<endl;
        *p = (**p).next;   // changing p pointer will also change first pointer
        cout<<first<<" ";  // checking value of first pointer after every change
    }
}

int main()
{
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);

    cout<<first<<endl;   //printing first pointer before passing by address i.e it will get change

    Display(&first); //passing node pointer address (pass by address)
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *Next;
};
struct Node *first = NULL;
struct Node *second = NULL;
struct Node *third = NULL;

void Create(int A[], int n)
{
    struct Node *temp, *last;
    first = new Node;
    cout << first << endl;
    first->data = A[0];
    first->Next = NULL;
    last = first;

    int i;
    for (i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->Next = NULL;

        last->Next = temp; // setting last Node link to the current Node
        last = temp;       // keeping track of current element
    }
}

void Display(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->Next;
    }
}

void RDisplay(struct Node *p)
{
    if (p != NULL)
    {
        RDisplay(p->Next);
        printf("%d ", p->data); // it will print while returning time so linklist will be printed in reverse
    }
}

int count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->Next;
    }
    return l;
}
int Rcount(struct Node *p)
{
    if (p != NULL)
        return Rcount(p->Next) + 1;
    else
        return 0;
}

int Max(struct Node *p)
{
    int max = INT32_MIN;

    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->Next;
    }
    return max;
}
int RMax(struct Node *p)
{
    int x = 0;

    if (p == 0)
        return INT32_MIN;

    x = RMax(p->Next);
    return x > p->data ? x : p->data;
}

struct Node *LSearch(struct Node *p, int key)
{
    struct Node *q;

    while (p != NULL)
    {
        if (key == p->data)
        {
            q->Next = p->Next; // improving linear search (move to head method)
            p->Next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->Next;
    }
    return NULL;
}
struct Node *RSearch(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return RSearch(p->Next, key);
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if (index < 0 || index > count(p))
        return;

    t = new Node;
    t->data = x;

    if (index == 0) // if the number to be inserted before first node
    {
        t->Next = first;
        first = t;
    }
    else
    {
        for (i = 1; i < index; i++)
            p = p->Next;

        t->Next = p->Next;
        p->Next = t;
    }
}

void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->Next = NULL;

    if (first == NULL) // if the linked list is null
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->Next;
        }
        if (p == first) // if the number to be inserted before first node
        {
            t->Next = first;
            first = t;
        }
        else
        {
            t->Next = q->Next;
            q->Next = t;
        }
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1, i;

    if (index < 1 || index > count(p))
        return -1;
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->Next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->Next;
        }
        q->Next = p->Next;
        x = p->data;
        free(p);
        return x;
    }
}

int isSorted(struct Node *p)
{
    int x = -65536;

    while (p != NULL)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->Next;
    }
    return 1;
}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->Next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->Next;
        }
        else
        {
            p->Next = q->Next;
            free(q);
            q = p->Next;
        }
    }
}

void Reverse1(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = p;

    A = (int *)malloc(sizeof(int) * count(p));

    while (q != NULL)
    {
        A[i] = q->data;
        q = q->Next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->Next;
        i--;
    }
}
void Reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->Next;
        q->Next = r;
    }
    first = q;
}
void Reverse3(struct Node *q, struct Node *p)
{
    if (p)
    {
        Reverse3(p, p->Next);
        p->Next = q;
    }
    else
        first = q;
}

void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->Next = NULL;
    last = second;
    cout << second << endl;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->Next = NULL;
        last->Next = t;
        last = t;
    }
}
void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->Next;
        third->Next = NULL;
    }
    else
    {
        third = last = q;
        q = q->Next;
        third->Next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->Next = p;
            last = p;
            p = p->Next;
            last->Next = NULL;
        }
        else
        {
            last->Next = q;
            last = q;
            q = q->Next;
            last->Next = NULL;
        }
    }
    while (p)
    {
        last->Next = p;
        last = p;
        p = p->Next;
        last->Next = NULL;
    }

    while (q)
    {
        last->Next = q;
        last = q;
        q = q->Next;
        last->Next = NULL;
    }
}

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;

    do
    {
        p = p->Next;
        q = q->Next;
        q = q ? q->Next : q;
    } while (p && q && p != q);

    if (p == q)
        return 1;
    else
        return 0;
}

int main()
{
    int A[] = {2, 4, 5, 7, 8};
    Create(A, 5);
    // cout << first;

    // int B[] = {3, 5, 6};
    // create2(B, 3);

    // SortedInsert(first, 1);
    // cout << Delete(first, 1) << endl;

    // if (isSorted(first))
    // {
    //     cout<<"LIST IS SORTED";
    // }
    // else
    //     cout<<"LIST IS NOT SORTED";

    // RemoveDuplicate(first);

    // Display(first);
    // cout<<endl;
    // Display(second);
    // cout<<endl;
    // Merge(first,second);     for mergin two linked lists
    // Display(third);
    // cout<<endl;
    // cout <<endl<<first<<endl<<second<<endl<<third;


    // struct Node *t1,*t2;
    // t1 = first->Next->Next;
    // t2 = first->Next->Next->Next->Next;
    // t2->Next = t1;
    // cout<<isLoop(first);

    

    return 0;
}

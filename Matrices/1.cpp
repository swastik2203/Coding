//C PROGRAM OF DIAGONAL MATRIX
#include <bits/stdc++.h>
using namespace std;

struct Matrix
{
    int A[10];
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if(i==j)
       m->A[i-1] = x;
}

int Get(struct Matrix m, int i, int j)
{
    if(i==j)
       return m.A[i-1];

    else
       return 0;   
}

void Display(struct Matrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if(i==j)
              cout<<m.A[i-1]<<" ";
            else 
              cout<<"0 ";  
        } 
        cout<<"\n"; 
    }
}



int main()
{
    struct Matrix m;
    m.n = 4;

    Set(&m, 1, 1, 4);
    Set(&m, 2, 2, 4);
    Set(&m, 3, 3, 4);
    Set(&m, 4, 4, 4);
    
    Display(m);

    return 0;
}
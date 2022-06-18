//FACTORIAL OF N 

#include <bits/stdc++.h>
using namespace std;

int fact(int n)   //RECURSIVE METHOD
{
 if(n==0)
 return 1;
 return fact(n-1)*n;
}
int Ifact(int n)  //ITERATIVE METHOD
{
 int f=1,i;
 for(i=1;i<=n;i++)
 f=f*i;

 return f;
}
int main()
{
 int r=Ifact(5);
 printf("%d ",r);
 return 0;
}
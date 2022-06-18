//SUM OF N NUMBERS

#include <bits/stdc++.h>
using namespace std;

int sum(int n)  //RECURSIVE METHOD 
{
 if(n==0)
 return 0;
 return sum(n-1)+n;
}
int Isum(int n)  // ITERATIVE METHOD
{
 int s=0,i;
 for(i=1;i<=n;i++)
 s=s+i;

 return s;
}
int main()
{
 int r=sum(5);
 cout<<r;
 return 0;
}
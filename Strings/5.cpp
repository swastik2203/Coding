//REVERSING A STRING

#include <bits/stdc++.h>
using namespace std;


//METHOD 1 using 2 array
// int main()
// {
//     char A[] ="python";
//     char B[7];           //using another array
//     int i,j;

//     for ( i = 0; A[i] != '\0'; i++)
//     {}
//     i = i-1;

//     for ( j = 0; i>=0 ; j++)
//     {
//         B[j] = A[i];
//         i--;
//     }
//     B[j] = '\0';

//     cout<<A;
    
//     return 0;
// }

//METHOD 2  using single array only
int main()
{
    char A[] ="python";
    int i,j;

    for ( i = 0; A[i] != '\0'; i++)
    {}
    i = i-1;

    for ( j = 0; j<i ; j++)
    {
        int t = A[i];
        A[i] = A[j];
        A[j] = t;
        i--;
    }

    cout<<A;
    
    return 0;
}
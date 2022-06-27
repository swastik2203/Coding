//COMPARING STRINGS AND CHECKING PALLINDROME

#include <bits/stdc++.h>
using namespace std;
void Comparestring(char A[], char B[])
{
    int i,j;

    for (i = 0,j = 0; A[i] != '\0' && B[j] != '\0'; i++,j++)  //for loop of two variables
    {
        if (A[i] >= 65 && A[i] <= 90)   //converting every char to small
            A[i] += 32;

        if (B[j] >= 65 && B[j] <= 90)
            B[j] += 32;
        
        if (A[i] != B[j])
           break;
    }
    if (A[i] == B[j])
       cout<<"equal";
    else if(A[i] < B[j])
       cout<<" A is smaller";
    else  
       cout<<"A is greater";      

}


int Pallindrome(char A[])
{
    int i,j = 0;

    for (i = 0; A[i] != '\0'; i++)
    {
        if (A[i] >=65 && A[i] <= 90)   //converting every char to smaller
        {
            A[i] +=32;
        }
        
    }
    i = i-1;

    for (i ,j; j < i; j++,i--)
    {
        if (A[i] != A[j])
          return 0;  
    }
    return 1;
}

int main()
{
    // char A[] = "Painter";
    // char B[] = "painting";
    // Comparestring(A,B);

    char A[] = "MAm";
    cout<<Pallindrome(A);



    

}


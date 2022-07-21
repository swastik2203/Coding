//punlicis sapient
#include <bits/stdc++.h>
using namespace std;

int count = 0;

void Permutation(char Perm[], char S[] , int k)
{
    static int A[10] = {0};//to keep track of of index of array S and if the index already in used or not
    int i;                  // if A[i] = 0  then i index is available of array S and viceversa

    static char Res[10];  // to store the characters to print at last and 'k' is the varible to keep track of index of Res array
    
    if (Perm[k] == '\0')
    {
        Res[k] = '\0';
        int l = 0;
        while (Res[l] != '\0' && S[l] != '\0')
        {
            if (S[l] == '-' && Res[l] > Res[l+1])
            {
                l++;
            }
            else if(S[l] == '+' && Res[l] < Res[l+1])
            {
                l++;
            }
            else
              break;
        }
        if (Res[l] == '\0' || S[l] == '\0')
        {
            ::count++;
        }
        
        
        
        // cout<<Res<<endl;
    }
    else
    {
        for (i = 0; Perm[i] != '\0'; i++)
        {
            if(A[i] == 0)     // to check that index is available
            {
                Res[k] = Perm[i]; //storing the char in Res array
                A[i] = 1;     // as the character in use setting it as unavailable

                Permutation(Perm, S, k+1);   //Recursive call

                A[i] = 0; // making the index available while going to next iteration

            }
        }
    }

    
}

int main()
{
    int n;    //size
    cin>>n;
    char S[n+1];
    cin>>S;

    char Perm[n+2];
    int i;
    for (i = 0; i < n+1; i++)
    {
        Perm[i] = 48 + i;
        // cout<<Perm[i]<<" ";
    }
    Perm[i] = '\0';
    
    // for (int i = 0; S[i] != '\0'; i++)
    // {
    //     cout<<S[i];
    // }
    // cout<<endl;
    // for (int i = 0; Perm[i] != '\0'; i++)
    // {
    //     cout<<Perm[i];
    // }
    // cout<<endl;



    Permutation(Perm, S, 0);

    cout<<::count;






    
    return 0;
}
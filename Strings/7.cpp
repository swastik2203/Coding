//PERMUTATIONS OF STRINGS

#include <bits/stdc++.h>
using namespace std;

void Permutation(char S[], int k)
{
    static int A[10] = {0};//to keep track of of index of array S and if the index already in used or not
    int i;                  // if A[i] = 0  then i index is available of array S and viceversa

    static char Res[10];  // to store the characters to print at last and 'k' is the varible to keep track of index of Res array
    
    if (S[k] == '\0')
    {
        Res[k] = '\0';
        cout<<Res<<endl;
    }
    else
    {
        for (i = 0; S[i] != '\0'; i++)
        {
            if(A[i] == 0)     // to check that index is available
            {
                Res[k] = S[i]; //storing the char in Res array
                A[i] = 1;     // as the character in use setting it as unavailable

                Permutation(S, k+1);   //Recursive call

                A[i] = 0; // making the index available while going to next iteration

            }
        }
    }
}


int main()
{
    char S[] = "ABC";

    Permutation(S, 0);


    return 0;
}
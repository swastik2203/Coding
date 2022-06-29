//SPARSE MATRIX CODE USING C 

#include <bits/stdc++.h>
using namespace std;

struct Element
{
    int i;
    int j;
    int x;
};
struct Sparse
{
    int m;//total no. of rows
    int n;//total no. of cols
    int num;//total no. of non-zero elements
    struct Element *e;
};
void Create(struct Sparse *s)
{
    cout<<"Enter the dimension(m*n): ";
    cin>> s->m >> s->n;
    cout<<"Enter the total number of elements in the matrix: ";
    cin>> s->num;

    int i,j;

    s->e = new Element[s->num];   //creating array of struct elements in heap

    cout<<"Enter the non-zero elements: ";
    for (i = 0; i < s->num; i++)  //storing all elements 
    {
        cin>> s->e[i].i >>s->e[i].j >> s->e[i].x;      // while entering we must follow that matrix start row and col is 0
    }
}
struct Sparse * add(struct Sparse *s1, struct Sparse *s2)
{
    if(s1->m != s2->m || s1->n != s2->n)     //checking if two matrix dimension matches
        return 0;

    struct Sparse * sum;       //struct sparse type pointer that points sum sparse
    sum = new Sparse;          // creating sparse in heap memory that sum pointer points
    sum->e = new Element[s1->num + s2->num];   // creating array of struct Element type

    sum->m = s1->m;      // storing dimensions
    sum->n = s1->n;

    int i = 0, j = 0, k = 0;     // i to scan 1st matrix and j to scan 2nd matrix 
                                // k to scan 

    while (i < s1->num && j < s2->num)
    {
        if (s1->e[i].i < s2->e[j].i)      //if row of 1st matrix is less than row of 2nd matrix
           sum->e[k++] = s1->e[i++];      // copy elements of 1st matrix and increment k and i(to scan 1st matrix)

        else if(s2->e[j].i < s1->e[i].i)  //if row of 2nd matrix is less than row of 1st matrix
           sum->e[k++] = s2->e[j++];      // copy elements of 2nd matrix  and increment k and j(to scan 2nd matrix)

        else              // come to check columnn
        {
            if (s1->e[i].j < s2->e[j].j)      //if col of 1st matrix is less than row of col matrix
            sum->e[k++] = s1->e[i++];        // copy elements of 1st matrix and increment k and i(to scan 1st matrix)

            else if(s2->e[j].j < s1->e[i].j)  //if row of 2nd matrix is less than row of 1st matrix
            sum->e[k++] = s2->e[j++];      // copy elements of 2nd matrix  and increment k and j(to scan 2nd matrix)


            else            // in this case both rows and cols would be equal so add the elements and increament i , j and k
            {
                sum->e[k] = s1->e[i];
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;   // adding and incrementing
            }
        }   
    }
    for(; i<s1->num;i++)    // to copy all the remaining elements from 1st matrix if any left
        sum->e[k++] = s1->e[i];

    for(; j<s2->num;j++)   // to copy all the remaining elements from 2nd matrix if any left
        sum->e[k++] = s2->e[j];    
    

    sum->num = k;     //storing total number of elements

    return sum;
}

void Display(struct Sparse s)
{
    int i, j, k=0;

    for (i = 0; i < s.m; i++)  // assuming rows of the matrix starts with 0
    {
        for (j = 0; j < s.n;j++) //assuming cols of the matrix starts with 0
        {
            if (i == s.e[k].i && j == s.e[k].j)  //checking for if position match
            {
                cout<<s.e[k].x<<" ";
                k++;
            }  
            else 
                cout<<"0 ";    
        }
        cout<<endl; 
    }
    
}


int main()
{
    struct Sparse s1, s2, *s3;
    
    Create(&s1);
    Create(&s2);
    
    s3 = add(&s1, &s2);

    cout<<"1st sparse matrix: "<<endl;
    Display(s1);
    
    cout<<"2nd sparse matrix: "<<endl;
    Display(s2);

    cout<<"result of addition of above two matrices: "<<endl;
    Display(*s3);   //as s3 is a struct Sparse type pointer so we have to dereference and pass to display



    return 0;
}
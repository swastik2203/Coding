// ARRAY ADT
#include <bits/stdc++.h>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr) // receiving STRUCT Array DIRECTLY as a local variable for this func
                               //  if we change something it won't affect the original struct passed
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++)
        cout << arr.A[i] << " ";
}

void Append(struct Array *arr, int x) // receiving the address of struct with struct pointer
{
    if (arr->length < arr->size)   // To access the struct data using Struct pointer
        arr->A[arr->length++] = x; // we have to use " (*arr).length "   or  " arr->length "
}

void Insert(struct Array &arr, int index, int x) // receiving the the struct Array as the reference it is totally similar to that

{
    int i; // struct passed but if we change anything it will affect the original
    if (index >= 0 && index <= arr.length)
    {
        for (i = arr.length; i > index; i--)
            arr.A[i] = arr.A[i - 1];
        arr.A[index] = x;
        arr.length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    int i;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
        return x;
    }
    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int LinearSearch(struct Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]); // we are swapping after searching so that
            return i;                     // we will use less time use searching again next time
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key) // ITERATIVE METHOD
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int RBinSearch(int a[], int l, int h, int key) // RECURSIVE METHOD
{
    int mid = 0;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return RBinSearch(a, l, mid - 1, key);
        else
        return RBinSearch(a, mid + 1, h, key);    
    }
    
    return -1;
}

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}
void Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}
int Max(struct Array arr)
{
    int max = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}
int Min(struct Array arr)
{
    int min = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}
int Sum(struct Array arr)
{
    int s = 0;
    int i;
    for (i = 0; i < arr.length; i++)
        s += arr.A[i];
    return s;
}
float Avg(struct Array arr)
{
    return (float)Sum(arr) / arr.length;
}

void Reverse(struct Array *arr)
{
    int size = arr->length*sizeof(int);
    int B[size];
    int i,j=0;
    for (i = arr->length - 1; i>=0; i--)
    {
        B[j] = arr->A[i];
        j++;
    }
    for (i = 0; i<arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

void Reverse2(struct Array *arr)
{
   int j = arr->length -1;

   for (int i = 0; i < j; i++)
   {
    int temp = arr->A[j];
    arr->A[j] = arr->A[i];
    arr->A[i] = temp;

    j--;
   }
   
}

void InsertSort(struct Array *arr, int x)
{
    if (arr->length == arr->size)
        return;
    
    int i = arr->length - 1;
    while (i>=0 && arr->A[i]>x) 
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

int IsSorted(struct Array arr)
{
    for (int i = 0; i < arr.length-1; i++)
    {
        if(arr.A[i]>arr.A[i+1])
          return 0;
    }
    return 1; 
}

void Rearrange(struct Array *arr)
{
    int i = 0,j = arr->length-1;
    while (i<j)
    {
        while(arr->A[i]<0)
          i++;

        while(arr->A[j]>=0)
          j--;

        if(i<j)
          swap(&arr->A[i],&arr->A[j]);
    }   
}

void Merge(struct Array *arr, struct Array *arr1, struct Array *arr2)
{
    int m = arr->length;
    int n = arr1->length;
    int i = 0, j = 0, k = 0;

    while (i<m and j<n)
    {
        if (arr->A[i]<arr1->A[j])
        {
            arr2->A[k] = arr->A[i];
            i++;
            k++;
        }
        if (arr1->A[j]<arr->A[i])
        {
            arr2->A[k] = arr1->A[j];
            j++;
            k++;
        }   
    }
    for (; i < m; i++)
    {
        arr2->A[k] = arr->A[i];
        k++;
    }
     for (; j < n; j++)
    {
        arr2->A[k] = arr1->A[j];
        k++;
    }    
}

void Union(struct Array *arr, struct Array *arr1, struct Array *arr2)
{
    int m = arr->length;
    int n = arr1->length;
    int i = 0, j = 0, k = 0;

    while (i<m and j<n)
    {
        if (arr->A[i] == arr1->A[j])
        {
            arr2->A[k] = arr->A[i];
            k++;
            i++;
            j++;
        }
        
        else if (arr->A[i]<arr1->A[j])
        {
            arr2->A[k] = arr->A[i];
            i++;
            k++;
        }
        else if (arr1->A[j]<arr->A[i])
        {
            arr2->A[k] = arr1->A[j];
            j++;
            k++;
        }   
    }
    for (; i < m; i++)
    {
        arr2->A[k] = arr->A[i];
        k++;
    }
     for (; j < n; j++)
    {
        arr2->A[k] = arr1->A[j];
        k++;
    }
    arr2->length = k;
}

void Intersection(struct Array *arr, struct Array *arr1, struct Array *arr2)
{
    int m = arr->length;
    int n = arr1->length;
    int i = 0, j = 0, k = 0;

    while (i<m and j<n)
    {
        if (arr->A[i] == arr1->A[j])
        {
            arr2->A[k] = arr->A[i];
            k++;
            i++;
            j++;
        }
        
        else if (arr->A[i]<arr1->A[j])
        {
            i++;
        }
        else if (arr1->A[j]<arr->A[i])
        {
            j++;
        }   
    }

    arr2->length = k;
}

void Difference(struct Array *arr, struct Array *arr1, struct Array *arr2)
{
    int m = arr->length;
    int n = arr1->length;
    int i = 0, j = 0, k = 0;

    while (i<m and j<n)
    {
        if (arr->A[i] == arr1->A[j])
        {
            i++;
            j++;
        }
        
        else if (arr->A[i]<arr1->A[j])
        {
            arr2->A[k] = arr->A[i];
            i++;
            k++;
        }
        else if (arr1->A[j]<arr->A[i])
        {
            j++;
        }   
    }
    for (; i < m; i++)
    {
        arr2->A[k] = arr->A[i];
        k++;
    }
     
    arr2->length = k;
}







int main()
{
    struct Array arr = {{2, 6, 10, 15, 25}, 10, 5};
    struct Array arr1 = {{3, 6, 7, 15, 20},10, 5};
    struct Array arr2 = {{0},10,0};
    //Append(&arr, 10); // passing address of struct Array so that we can perform some changes

    //Insert(arr, 0, 12); // passing the struct and receiving as an refernce

    //Delete(&arr, 0);

    // Reverse2(&arr);

    // InsertSort(&arr,18);

    // Rearrange(&arr);
    // Display(arr2);

    // Merge(&arr,&arr1,&arr2);

    Difference(&arr, &arr1, &arr2);

    Display(arr2); // PASSING STRUCT Array DIRECTLY we can't change the arr there

    

    cout<<endl<<IsSorted(arr);
    return 0;
}
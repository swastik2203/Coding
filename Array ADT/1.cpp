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
    }
    else
        return RBinSearch(a, mid + 1, h, key);

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


int main()
{
    struct Array arr1 = {{2, 3, 4, 5, 6}, 10, 5};
    Append(&arr1, 10); // passing address of struct Array so that we can perform some changes

    Insert(arr1, 0, 12); // passing the struct and receiving as an refernce

    Delete(&arr1, 0);

    Display(arr1); // PASSING STRUCT Array DIRECTLY we can't change the arr there
    return 0;
}
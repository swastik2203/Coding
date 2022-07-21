#include <iostream>
    using namespace std;
class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array()
    {
        delete[] A;
    }
    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    int isSorted();
    void Rearrange();
    Array *Merge(Array *arr2);
    Array *Union(Array arr2);
    Array *Diff(Array arr2);
    Array *Inter(Array arr2);
};

void Array::Display()
{
    int i;
    cout << "\nElements are\n";
    for (i = 0; i < length; i++)
        cout << A[i] << " ";
}
void Array::Append(int x)
{
    if (length < size)
        A[length++] = x;
}
void Array::Insert(int index, int x)
{
    int i;
    if (index >= 0 && index <= length)
    {
        for (i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    }
}
Array * Array::Merge(Array *arr2)  //receiving class pointer
{
    int i, j, k;
    i = j = k = 0;

    Array *arr3 = new Array(length + arr2->length);

    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < length; i++)
        arr3->A[k++] = A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = length + arr2->length;

    return arr3;
}

int main()
{
    Array *arr1;
    // Array arr2(5);
    Array *arr3;
    Array *arr2;
    
    arr1 = new Array(5);
    arr2 = new Array(5);


    arr1->Append(1);
    arr1->Append(3);
    arr1->Append(5);
    arr1->Append(7);
    arr1->Append(9);

    arr2->Append(2);
    arr2->Append(4);
    arr2->Append(6);
    arr2->Append(8);
    arr2->Append(10);

    arr3 = arr1->Merge(arr2); //passing class pointer



    arr3->Display();



    
    return 0;
}
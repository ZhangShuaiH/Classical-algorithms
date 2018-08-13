#include "stdafx.h"
#include <iostream>
#include "ConsoleApplication1.h"

using namespace std;
// 希尔排序
void shell_sort(int a[], const int size) {
    for (int increment = size / 2; increment >= 1; increment /= 2)
        for (int i = 0; i < size; i++)
        {
            int temp = a[i];
            int j;
            for (j = i; j - increment >= 0 && a[j - increment] > temp; j -= increment)
                a[j] = a[j - increment];
            a[j] = temp;
        }
}

// 插入排序
void insertion_sort(int a[], const int size) {
    for (int i = 0; i < size; i++)
    {
        int temp = a[i];
        int j;
        for (j = i; j - 1 >= 0 && a[j - 1] > temp; j--) 
            a[j] = a[j - 1];
        a[j] = temp;
    }
}
void print(const int a[], const int size) {
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int a[] = { 6,5,3,4,2,1 };
    int b[] = { 6,5,3,4,2,1 };
    int size = sizeof(a) / sizeof(int);

    shell_sort(a, size);
    insertion_sort(b, size);
    print(a, size);
    print(b, size);

	return 0;
}

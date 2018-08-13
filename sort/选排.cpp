#include <stdio.h>
#include <iostream>

using namespace std;

/*****************************************************
时间复杂度：O(n^2)
空间复杂度：O(1)
******************************************************/
// 不稳定，选择排序。找出【数组无序部分】的最小值，放到【数组无序部分】的开头
void selection_sort(int a[], int size){
    // i：未排序数组的第一个数的下标
    for(int i = 0; i < size; i++){
        // 【数组无序部分】的下标，从第二个数开始
        // 找到【数组无序部分】的最小值
        for(int j = i+1; j < size; j++){
            // 将较小值放到【数组无序部分】的开头
            if(a[i]>a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    int a[] = {6,4,5,3,2,1};
    int n = sizeof(a)/sizeof(int);
    selection_sort(a, n);
    print(a, n);
}

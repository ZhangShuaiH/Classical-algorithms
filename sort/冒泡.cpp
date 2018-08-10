#include <stdio.h>
#include <iostream>

using namespace std;

/*************************
 * 经典排序算法总结
**************************/
void print(int a[], int size){
    for(int i = 0; i < size; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

/***********************************
 **************冒泡排序**************
 空间复杂度：O(1)
 时间复杂度：O(n^2)
************************************/
// 稳定。比较相邻俩数，大数放后面
void bubble_sort0(int a[], int size){
    /****************************************************************
     * 1.记录遍历次数（遍历前计数。若遍历后计数，则值域为0<=次数<=size-2），使用循环
     * 2.次数值域
     *      1<=次数<=size
     * 3.缩小次数值域
     *      遍历 size-1 次即可确定数组顺序
     *      次数值域：1<=次数<=size-1
    *****************************************************************/
    for(int ergodic_time = 1; ergodic_time <= size-1; ergodic_time++){
        /*********************************
         * 1.遍历数组，使用循环；
         * 2.下标
         *      []中的变量：j, j+1
         * 2.下标值域
         *      0<=下标<size
         * 3.缩小下标值域
         *      由于排好序的部分数组无需再次遍历，所以可以缩小下标的上边界
         *      用 ergodic_time 记录遍历次数，遍历第 ergodic_time 次，
         *      下标值域：0<=下标<size-ergodic_time+1
         *********************************/
        for(int j = 0; j+1 < size-ergodic_time+1; j++){
            // 比较相邻两个数，大数放后面
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}


// 不稳定，不是典型的冒泡算法。找出【数组无序部分】的最小值，放到【数组无序部分】的开头
void bubble_sort1(int a[], int size){
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
// 稳定。类似 bubble_sort0
void bubble_sort2(int a[], int size){
    int ergodic_time = 0;// 遍历次数，遍历结束时计数
    do{
        // 最大数排最后面
        for(int i = 0; i+1 < size-ergodic_time; i++){
            // 比较相邻俩数，将大数放后面
            if(a[i]>a[i+1]){
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
        ergodic_time++;
    }while(ergodic_time<size-1);
}

int main()
{
    int a[] = {6,4,5,3,2,1};
    int n = sizeof(a)/sizeof(int);
    bubble_sort2(a, n);
    print(a, n);
}

#include <iostream>

void shellSort(int nums[], int length);
void swap(int nums[], int i, int j);
void printArray(int *nums, int length);


int main()
{
    int nums[] = {10, 21, 22, 35, 39, 18, 30, 89};
    int length = sizeof(nums) / sizeof(nums[0]);
    shellSort(nums,length);
    printArray(nums, length);
}

void shellSort(int nums[], int length){
    int gap = length / 2; //这里用总长度的一半作为初始gap
    while(gap >= 1){
        //写代码的时候可以从gap为1的情况下考虑
        //相比较插入排序而言，最大的不同就是希尔排序的数据间隔是gap 而不是传统的1
        for(int i = gap; i < length; ++i){
            int currentValue = nums[i];
            int j = i - gap;
            //寻找插入位置
            while(j > 0 && currentValue < nums[j]){
                nums[j + gap] = nums[j];
                j -= gap;
            }
            nums[j + gap] = currentValue;
        }
        gap /= 2;
    }
}

void swap(int nums[], int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void printArray(int *nums, int length)
{
    for (int i = 0; i < length; ++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

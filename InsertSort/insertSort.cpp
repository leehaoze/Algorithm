#include <iostream>

void insertSort(int nums[], int length);
void swap(int nums[], int i, int j);
void printArray(int *nums, int length);

int main()
{
    int nums[] = {10, 21, 22, 35, 39, 18, 30, 89};
    int length = sizeof(nums) / sizeof(nums[0]);
    insertSort(nums, length);
    printArray(nums, length);
}

void insertSort(int nums[], int length)
{
    //默认第0个数据是有序的 直接从无序的部分开始
    for (int i = 1; i < length; ++i)
    {
        int currentValue = nums[i];
        int index = i - 1;
        //挑选合适的位置 index>0保证当前值为最小值时不会越界
        while (index > 0 && currentValue < nums[index])
        {
            //当前值小于上一个位置的值，将上个位置的值向后挪空出位置
            nums[index + 1] = nums[index];
            index--;
        }
        //while循环结束意味着找到了合适的位置
        nums[index + 1] = currentValue;
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
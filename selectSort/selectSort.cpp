#include <iostream>

void selectSort(int nums[], int length);
void selectSortMin(int nums[], int length);
void swap(int nums[], int i, int j);
void printArray(int *nums, int length);

int main()
{
    int nums[] = {10, 21, 22, 35, 39, 18, 30, 89};
    int length = sizeof(nums) / sizeof(nums[0]);
    selectSortMin(nums, length);
    printArray(nums, length);
}

//每次遍历选择最大值放到末尾
void selectSort(int nums[], int length)
{
    //这里i代表趟数 也代表着已归位的数据个数
    //只需要遍历 length - 1次就可以了，每次遍历都会选最大值放到末尾，最后一次遍历时剩下的那一个肯定是整个数组中的最小值
    for (int i = 0; i < length - 1; ++i)
    {
        //最大值下标 每次都用第一个数做最大值
        int maxIndex = 0;
        for (int j = 1; j < length - i; ++j)
        {
            if (nums[maxIndex] < nums[j])
            {
                maxIndex = j;
            }
        }
        swap(nums, maxIndex, length - i - 1);
    }
}

//每次遍历选择最小值放到开头
void selectSortMin(int nums[], int length)
{
    //这里i代表趟数 也代表着已归位的数据个数
    //只需要遍历 length - 1次就可以了，每次遍历都会选最小值放到开头，最后一次遍历时剩下的那一个肯定是整个数组中的最大值
    for (int i = 0; i < length - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < length; ++j)
        {
            if (nums[minIndex] > nums[j])
            {
                minIndex = j;
            }
        }
        swap(nums, minIndex, i);
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

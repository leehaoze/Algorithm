#include <iostream>

//冒泡排序
void bubbleSort(int *nums, int length);
//打印数组
void printArray(int *nums, int length);
//交换数组中的两个只
void swap(int nums[], int i, int j);

int main()
{
    int nums[] = {10, 21, 22, 35, 39, 18, 30, 89};
    int length = sizeof(nums) / sizeof(nums[0]);
    bubbleSort(nums, length);
    printArray(nums, length);
}

void bubbleSort(int nums[], int length)
{
    //i可以理解为当前是遍历的第几趟，也以为着已经有i个泡泡归位了(每一趟都会将此趟的最大值放到尾部)
    //另外我们只需要遍历 length - 1趟即可得到一个有序的数组 
    for (int i = 0; i < length - 1; ++i)
    {
        //有序标志  如果当前趟没有发生任何交换 这代表数组已经有序 直接退出排序
        bool sortedFlag = true;
        //当前趟的下标，从1开始 当前趟的末尾值为 数组原长度减去已归位的泡泡的个数
        for (int j = 1; j < length - i; ++j)
        {
            //这里不是大于等于 是为了保证稳定性
            if (nums[j - 1] > nums[j])
            {
                swap(nums, j - 1, j);
                sortedFlag  = false;
            }
        }
        if(sortedFlag){
            printf("已经有序\n");
            return ;
        }
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

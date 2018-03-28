#include "bubbleSort.h"

/*
每次将第一个元素和后面所有元素比较，如果反序则交换，这样一轮遍历下来第一个元素即为最小值（或最大值），
然后考虑下一个元素，重复之前的比较和交换过程
*/
void bubbleSort1(vector<int>& arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

//相邻元素两两比较，最小元素移至序列首部
void bubbleSort2(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = arr.size() - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
        }
    }
}

//相邻元素两两比较，最大元素移至序列尾部
void bubbleSort3(vector<int>& arr)
{
    for (int i = 0; i < arr.size() ; i++)
    {
        for (int j = 1; j < arr.size() - i; j++)
        {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
        }
    }
}

//设置一个标志，如果这一趟发生了交换，则为true，否则为false。明显如果有一趟没有发生交换，说明排序已经完成。
void bubbleSort4(vector<int>& arr)
{
    bool flag = true;
    int size = arr.size();
    while (flag)
    {
        flag = false;
        for (int j = 1; j < size; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                flag = true;
            }
        }
        size--;
    }
}

/*
如果有100个数的数组，仅前面10个无序，后面90个都已排好序且都大于前面10个数字，那么在第一趟遍历后，最后发生交换的位置必定小于10，
且这个位置之后的数据必定已经有序了，记录下这位置，第二次只要从数组头部遍历到这个位置就可以了。
*/
void bubbleSort5(vector<int>& arr)
{
    int flag = arr.size(), end = arr.size();
    while (flag > 0)
    {
        end = flag;
        flag = 0;
        for (int j = 1; j < end; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                flag = j;
            }
        }
    }
}
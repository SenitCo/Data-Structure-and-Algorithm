#include "insertSort.h"

void insertSort1(vector<int>& arr)
{
    int i, j;
    for (i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
        {
            int temp = arr[i];
            for (j = i - 1; j >= 0 && arr[j] > temp; j--)
                arr[j + 1] = arr[j];
            arr[j + 1] = temp;
        }
    }
}

void insertSort2(vector<int>& arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
            swap(arr[j], arr[j + 1]);
    }
}
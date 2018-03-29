#include "mergeSort.h"

void merge(vector<int>& arr, int left, int mid, int right, vector<int>& temp)
{
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];

    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (int i = 0; i < k; i++)
        arr[left + i] = temp[i];
}

void MSort(vector<int>& arr, int left, int right, vector<int>& temp)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MSort(arr, left, mid, temp);
        MSort(arr, mid + 1, right, temp);
        merge(arr, left, mid, right, temp);
    }    
}

void mergeSort(vector<int>& arr)
{
    int size = arr.size();
    vector<int> temp(size);
    MSort(arr, 0, size - 1, temp);
}

void mergeSortIter(vector<int>& arr)
{
    int step = 2, i = 0, size = arr.size();
    vector<int> temp(size);
    while (step <= size)
    {
        i = 0; 
        while (i + step <= size)
        {
            merge(arr, i, i + step / 2 - 1, i + step - 1, temp);
            i = i + step;
        }
        if (i + step / 2 < size)
            merge(arr, i, i + step / 2 - 1, size - 1, temp);
        step *= 2;
    }
    merge(arr, 0, step / 2 - 1, size - 1, temp);
}
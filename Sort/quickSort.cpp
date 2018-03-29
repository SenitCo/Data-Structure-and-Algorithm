#include "quickSort.h"

int partition1(vector<int>& arr, int left, int right)
{
    int pivotValue = arr[left], i = left, j = right;
    while (i < j)
    {
        while (i < j && arr[j] >= pivotValue)
            j--;
        //if (i < j)
        {
            arr[i] = arr[j];
            //i++;
        }
        while (i < j && arr[i] <= pivotValue)
            i++;
        //if (i < j)
        {
            arr[j] = arr[i];
            //j--;
        }
    }
    arr[i] = pivotValue;
    return i;
}

int partition2(vector<int>& arr, int left, int right)
{
    int pivotValue = arr[left], i = left, j = right;

    while (true)
    {
        while (i < j && arr[j] >= pivotValue)
            j--;
        while (i < j && arr[i] <= pivotValue)
            i++;
        if (i >= j)
            break;
        swap(arr[i++], arr[j--]);
    }

    /*while (i < j)
    {
        while (i < j && arr[j] >= pivotValue)
            j--;
        while (i < j && arr[i] <= pivotValue)
            i++;
        swap(arr[i], arr[j]);
    }*/

    swap(arr[left], arr[j]);
    return j;
}

int partition3(vector<int>& arr, int left, int right)
{
    //三数取中，并将中间值置于第一个元素处
    int mid = (left + right) / 2;
    if (arr[left] > arr[right])
        swap(arr[left], arr[right]);
    if (arr[mid] > arr[right])
        swap(arr[mid], arr[right]);
    if (arr[mid] > arr[left])
        swap(arr[mid], arr[left]);
    return partition1(arr, left, right);
}

void quickSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partition3(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

void quickSort1(vector<int>& arr, int left, int right)
{
    while (left < right)
    {
        int pivot = partition3(arr, left, right);
        quickSort1(arr, left, pivot - 1);
        left = pivot + 1;
    }
}
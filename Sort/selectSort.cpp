#include "selectSort.h"

void selectSort(vector<int>& arr)
{
    int i, j, min;
    for (i = 0; i < arr.size(); i++)
    {
        min = i;
        for (j = i + 1; j < arr.size(); j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        if (i != min)
            swap(arr[i], arr[min]);
    }
}
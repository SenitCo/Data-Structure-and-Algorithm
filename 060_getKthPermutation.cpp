/*@Description: Permutation Sequence
The set [1,2,3,…,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
Note: Given n will be between 1 and 9 inclusive.
*/
/**
定义两个数组，一个nums存储原始序列{1,2,...n}，一个fact用于存储对应数的阶乘{1!,2!,...n!}，对于n个数组组成的排列，
共有fact[n]=n!种情况，每个数i为起始的情况共有batch=fact[n]/n=fact[n-1]=(n-1)!，利用(k-1)/batch可求得第一个元素
的索引为idx=(k-1)/batch+1，即result[0]=nums[(k-1)/batch+1]，将其赋值后，在数组nums中移除对应元素，然后更新相关值，
继续下一轮迭代
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n + 1, 0);
        vector<int> fact(n + 1, 1);
        string result;
        for (int i = 1; i < n + 1; i++)
        {
            nums[i] = i;
            fact[i] = fact[i - 1] * i;
        }
        int idx = k - 1;
        for (int i = n; i > 0; i--)
        {
            int batch = fact[i] / n;
            int quo = idx / batch;
            idx = idx % batch;
            result.push_back(nums[quo + 1] + '0');
            nums.erase(nums.begin() + quo + 1);
            n--;
        }
        return result;
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n + 1, 0);
        vector<int> fact(n + 1, 1);
        string result;
        for (int i = 1; i < n + 1; i++)
        {
            nums[i] = i;
            fact[i] = fact[i - 1] * i;
        }
        int idx = k - 1, quo = 0;
        for (int i = n; i > 0; i--)
        {
            quo = idx / fact[i - 1];	//将batch直接替换为fact[i-1]
            idx = idx % fact[i - 1];
            result.push_back(nums[quo + 1] + '0');
            nums.erase(nums.begin() + quo + 1);
        }
        return result;
    }
};


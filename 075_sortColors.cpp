/*@Description: Sort Colors
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, 
with the colors in the order red, white and blue. Here, we will use the integers 0, 1, and 2 to represent the color 
red, white, and blue respectively.
Note:
You are not suppose to use the library's sort function for this problem.
Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's 
and followed by 2's. Could you come up with an one-pass algorithm using only constant space?
*/

/**
遍历两次，分别统计0、1、2的个数，然后再依次赋值
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = { 0, 0, 0 };
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)    count[0]++;
            else if(nums[i] == 1)   count[1]++;
            else    count[2]++;
        }
        for(int i = 0; i < count[0]; i++)   nums[i] = 0;
        for(int i = count[0]; i < count[0] + count[1]; i++) nums[i] = 1;
        for(int i = count[0] + count[1]; i < nums.size(); i++)  nums[i] = 2;
    }
};

/**
一次遍历，借助两个“指针”，分别指向调整位置后，0的下一个元素和2的前一个元素，对2的判断一定要在0之前，如果当前元素是2，
那么将后面的元素调整至当前位置时，还需进一步判断该元素是否为0；如果当前元素是0，那么将前面的元素调整至当前位置时，
不需要再判断该元素的值，因为前面的元素是确定的已经经过判断的，只可能为1或者0
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, two = nums.size() - 1;
        for(int i = 0; i <= two; i++)
        {
            while(nums[i] == 2 && i < two) swap(nums[i], nums[two--]);
            while(nums[i] == 0 && i > zero) swap(nums[i], nums[zero++]);
        }
    }
};

/**方法同上**/
void sortColors(int A[], int n) 
{
    int i = 0, j = n - 1;
    for(int k = 0; k <= j; )
    {
    	if(A[k] == 0)  swap(A[i++], A[k++]);
    	else if(A[k] == 2)  swap(A[j--], A[k]);	//注意此外k没有自增，因此后续还要对该值做进一步的判断
    	else k++;
    }        
}
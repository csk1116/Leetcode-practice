#include <iostream>
#include <vector>
using namespace std;

//linear search
//Time:O(N)
//Space:O(1)
class Solution1
{
public:
    int search(vector<int>& nums, int target)
    {
        int result = 0;
        for(auto num: nums)
        {
            if(num == target)
                return result;
            else
                result ++;
        }
        return -1;
    }
};

//Binary Search
//Time:O(logN)
//Space:O(1)
class Solution2
{
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right)
        {
            int pivot = left + (right - left) / 2;

            if(target == nums[pivot])
                return pivot;

            //pivot belongs to left portion [4 5 6 1 2]
            if(nums[pivot] >= nums[left])
            {
                if(target >= nums[left] && target <= nums[pivot]) // target = 4, 5
                    right = pivot - 1;
                // target < nums[left] || target > nums[pivot], target = 1, 2 
                else    
                    left = pivot + 1;
            } 
            //right portion  [5 6 1 2 4]
            else
            {
                if(target <= nums[right] && target >= nums[pivot]) // target = 2, 4
                    left = pivot + 1;
                // target > nums[right] || target < nums[pivot], target = 5, 6
                else
                    right = pivot - 1;
            }
        }
        return -1;
    }
};


int main()
{

    vector<int> testVec1 = {0, 1 ,2 ,3, 4, 5, 6}; //target = 5, 10
    vector<int> testVec2 = {4, 5, 6, 7, 8, 2, 3}; //target = 2, 8, 4

    Solution1 solution1;
    Solution2 solution2;

    cout << "Sol 1, test 1, target = 5, ans = 5: " << solution1.search(testVec1, 5) << endl;
    cout << "Sol 1, test 1, target = 10, ans = -1: " << solution1.search(testVec1, 10) << endl;
    cout << "Sol 1, test 2, target = 2, ans = 5: " << solution1.search(testVec2, 2) << endl;
    cout << "Sol 1, test 2, target = 8, ans = 4: " << solution1.search(testVec2, 8) << endl;
    cout << "Sol 1, test 2, target = 4, ans = 0: " << solution1.search(testVec2, 4) << endl;

    cout << "Sol 2, test 1, target = 5, ans = 5: " << solution2.search(testVec1, 5) << endl;
    cout << "Sol 2, test 1, target = 10, ans = -1: " << solution2.search(testVec1, 10) << endl;
    cout << "Sol 2, test 2, target = 2, ans = 5: " << solution2.search(testVec2, 2) << endl;
    cout << "Sol 2, test 2, target = 8, ans = 4: " << solution2.search(testVec2, 8) << endl;
    cout << "Sol 2, test 2, target = 4, ans = 0: " << solution2.search(testVec2, 4) << endl;
    
    return 0;
}
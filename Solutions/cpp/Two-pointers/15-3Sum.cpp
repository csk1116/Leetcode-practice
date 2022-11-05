#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//inspired by twosum II, sorted array + two pointer
//Time:O(NLogN + N^2)
//Space:O(1) or O(N) depends on sorting algo
class Solution1
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> result;
        if(nums.size() < 3)
            return result;
        
        sort(nums.begin(), nums.end());

        if(nums[0] > 0 || nums[nums.size()-1] < 0)
            return result;
        
        int left = 0, right = nums.size() - 1; //two pointers
        int sum = 0;
        for(int i = 0; i < nums.size(); i ++)
        {
            //skip duplicate
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            left = i + 1;
            right = nums.size() - 1;
            while(left < right)
            {
                sum = nums[i] + nums[left] + nums[right];
                if(sum < 0)
                {
                    left++;
                }
                else if(sum > 0)
                {
                    right--;
                }
                else
                {
                    vector<int> set = {nums[i], nums[left], nums[right]};
                    result.push_back(set);
                    left ++;
                    while(nums[left] == nums[left - 1] && left < right) 
                        left ++;
                }
            }            
        }
        return result;
    }
};

//
//Time:O()
//Space:O()
class Solution2
{
public:

};

void ShowResult(const vector<vector<int>>& vec)
{
    cout << "[";
    for(auto set: vec)
    {
        cout << "[";
        for(auto num: set)
        {
            cout << num << ",";
        }
        cout << "]";
    }
    cout << "]" << endl;
}


int main()
{
    vector<int> testVec1 = {-1, -1, 0, 1, 2, -1}; //duplicate & not sorted
    vector<int> testVec2 = {0, 0, 0, 0}; //duplicate 
    vector<int> testVec3 = {}; //no elements
    vector<int> testVec4 = {9, 3, 5, 10, 7}; //all positive numbers
    vector<int> testVec5 = {-1, -9, -3, -5, -5}; //all negative numbers

    Solution1 solution1;
    Solution2 solution2;

    vector<vector<int>> result1;

    result1 = solution1.threeSum(testVec1);
    ShowResult(result1);
    result1 = solution1.threeSum(testVec2);
    ShowResult(result1);
    result1 = solution1.threeSum(testVec3);
    ShowResult(result1);
    result1 = solution1.threeSum(testVec4);
    ShowResult(result1);
    result1 = solution1.threeSum(testVec5);
    ShowResult(result1);
    
    return 0;
}
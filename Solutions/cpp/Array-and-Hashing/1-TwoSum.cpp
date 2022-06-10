#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//
//time: O(N^2)
//space: O(1)
class Solution1
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {       
        vector<int> result = {-1, -1}; //if no answer, return (-1, -1) default

        if(nums.size() < 2)
            return result;

        for(int i = 0; i < nums.size(); i++)
        {
            int remain = target - nums[i];
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(remain == nums[j])
                {
                    result[0] = i;
                    result[1] = j;
                    break;
                }                   
            }
        }
        return result;
    }
};

//unordered_map: hash table
//TIME:O(N)
//SPACE:O(N)
class Solution2
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result = {-1, -1}; //if no answer, return (-1, -1) default

        if(nums.size() < 2)
            return result;

        unordered_map<int, int> myMap; //<num, index> 
        for(int i = 0; i < nums.size(); i++)
        {
            int remain = target - nums[i];
            if(myMap.find(remain) != myMap.end())
            {
                result[0] = myMap[remain];
                result[1] = i;
                break;
            }
            else
            {
                myMap[nums[i]] = i;
            }           
        }
        return result;
    }
};


int main()
{
    vector<int> nums1 = {2, 7, 1, 5}; // target 8
    vector<int> nums2 = {1}; // too short vec, target 1
    vector<int> nums3 = {9, 2, 2, 2, 2, 1}; // target 10
    vector<int> nums4 = {2, 2}; //target 4

    Solution1 solution1;
    Solution2 solution2;
    vector<int> vec1;
    vector<int> vec2;

    vec1 = solution1.twoSum(nums1, 8);
    vec2 = solution2.twoSum(nums1, 8);
    cout << "sol 1: " << vec1[0] << ", " << vec1[1] << endl;
    cout << "sol 2: " << vec2[0] << ", " << vec2[1] << endl;

    vec1 = solution1.twoSum(nums2, 1);
    vec2 = solution2.twoSum(nums2, 1);
    cout << "sol 1: " << vec1[0] << ", " << vec1[1] << endl;
    cout << "sol 2: " << vec2[0] << ", " << vec2[1] << endl;

    vec1 = solution1.twoSum(nums3, 10);
    vec2 = solution2.twoSum(nums3, 10);
    cout << "sol 1: " << vec1[0] << ", " << vec1[1] << endl;
    cout << "sol 2: " << vec2[0] << ", " << vec2[1] << endl;

    vec1 = solution1.twoSum(nums4, 4);
    vec2 = solution2.twoSum(nums4, 4);
    cout << "sol 1: " << vec1[0] << ", " << vec1[1] << endl;
    cout << "sol 2: " << vec2[0] << ", " << vec2[1] << endl;

    return 0;
}
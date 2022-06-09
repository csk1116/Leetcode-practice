#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map> //or <set>
using namespace std;

// BF  
//time: O(N^2)
//space: O(1)
class Solution1
{
public:
    bool containsDuplicate(vector<int>& nums);
};

bool Solution1::containsDuplicate(vector<int>& nums)
{
    if(nums.size() < 2)
        return false;

    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = i + 1; j < nums.size(); j++)
        {
            if(nums[i] == nums[j])
                return true;
        }
    }

    return false;
}

//sort O(NlogN)
//time: Check -> O(N), sort -> O(NlogN)
//space: O(1)
class Solution2
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] == nums[i+1])
                return true;
        }
        return false;
    }
};

//HashSet
//time: check -> O(N), sort -> O(1)
//space: O(N)
class Solution3
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_map<int, bool> myUMap;
        
        for(auto num: nums)
        {
            if(myUMap.find(num) != myUMap.end()) 
                return true;
            
            myUMap[num] = true;
        }

        return false;
    }
};


int main()
{
    vector<int> test1 = {1, 2, 5, 7, 6, 1};
    vector<int> test2 = {7, 0, 9, 8 ,6};
    vector<int> testEdge = {1};

    Solution1 solution1;
    Solution2 solution2;
    Solution3 solution3;

    cout << solution1.containsDuplicate(test1) << endl;
    cout << solution1.containsDuplicate(test2) << endl;
    cout << solution1.containsDuplicate(testEdge) << endl;

    cout << solution2.containsDuplicate(test1) << endl;
    cout << solution2.containsDuplicate(test2) << endl;
    cout << solution2.containsDuplicate(testEdge) << endl;

    cout << solution3.containsDuplicate(test1) << endl;
    cout << solution3.containsDuplicate(test2) << endl;
    cout << solution3.containsDuplicate(testEdge) << endl;

    return 0;
}
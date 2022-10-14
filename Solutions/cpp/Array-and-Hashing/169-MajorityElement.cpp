#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Hash table
// Time:O(N)
// Space:O(N)
class Solution1
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> myMap;
        int majorityElement = 0;
        int count = 0;
        for (auto num : nums)
        {
            myMap[num]++;
            if (myMap[num] > count)
            {
                majorityElement = num;
                count = myMap[num];
            }
        }
        return majorityElement;
    }
};

//Boyer-Moore Algorithm
// Time:O(N)
// Space:O(1) optimize to O(1) space
class Solution2
{
public:
 int majorityElement(vector<int> &nums)
    {       
        int majorityElement = 0;
        int count = 0;
        for (auto num : nums)
        {           
            if(num != majorityElement)
            {
                if (count == 0)
                    majorityElement = num;
                else
                    count --;
            } 
            else
                count ++;           
        }
        return majorityElement;
    }
};

void showResult(const vector<int>& result)
{
    cout << "[ ";
    for(auto num: result)
    {
        cout << num << " "; 
    }
    cout << "]" << endl;
}

int main()
{

    Solution1 solution1;
    Solution2 solution2;

    vector<int> test1 = {1, 2, 1}; //1
    vector<int> test2 = {1, 2, 3, 4, 5, 1, 1, 1, 1}; //1

    cout << "sol1, test1: " << endl;
    cout << solution1.majorityElement(test1) << endl;   
    cout << "sol1, test2: " << endl;
    cout << solution1.majorityElement(test2) << endl;

     cout << "sol2, test1: " << endl;
    cout << solution2.majorityElement(test1) << endl;   
    cout << "sol2, test2: " << endl;
    cout << solution2.majorityElement(test2) << endl;
    
    return 0;
}
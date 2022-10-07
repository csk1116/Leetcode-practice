#include <iostream>
#include <vector>
using namespace std;

//Brute force
//Time:O(N^2)
//Space:O(1) ignore result array
class Solution1
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> answer;
        for(int i = 0; i < nums.size(); i++)
        {
            int product = 1;
            for(int j = 0; j < nums.size(); j++)
            {
                if(i != j)
                    product *= nums[j];
            }
            answer.push_back(product);
        }
        return answer;
    }
};

//Total Product divide self
//Time:O(N)
//Space:O(1)
class Solution2
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> answer;
        for(int i = 0; i < nums.size(); i++)
        {
            int product = 1;
            for(int j = 0; j < nums.size(); j++)
            {
                if(i != j)
                    product *= nums[j];
            }
            answer.push_back(product);
        }
        return answer;
    }
};

//Prefix & postfix -> 2 pass 
//Time:O(N)
//Space:O(1) Optimize space from O(N) -> O(1)
class Solution3
{
public:

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
    vector<int> test1 = {1, 2, 3, 4}; // [24, 12, 8, 6]  
    vector<int> test2 = {1, 2, 0, 3}; // [0, 0, 6, 0]

    Solution1 solution1;
    //Solution2 solution2;
    //Solution2 solution3;

    vector<int> result1;
    vector<int> result2;

    result1 = solution1.productExceptSelf(test1);
    showResult(result1);
    result2 = solution1.productExceptSelf(test2);
    showResult(result2);

    return 0;
}
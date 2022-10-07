#include <iostream>
#include <vector>
using namespace std;

// Brute force
// Time:O(N^2)
// Space:O(1) ignore result array
class Solution1
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++)
        {
            int product = 1;
            for (int j = 0; j < nums.size(); j++)
            {
                if (i != j)
                    product *= nums[j];
            }
            answer.push_back(product);
        }
        return answer;
    }
};

// Total Product divide self
// Time:O(N)
// Space:O(1)
// if zero count >= 2 -> all zero 
class Solution2
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> answer(nums.size(), 0);
        int totalProduct = 1;
        int zeroCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
                totalProduct *= nums[i];
            else
                zeroCount ++;
            
            if(zeroCount > 1)
                return answer;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if(zeroCount == 0)
            {
                answer[i] = totalProduct / nums[i];
            }
            else
            {
                if (nums[i] == 0)
                    answer[i] = totalProduct;
            }    
        }
        return answer;
    }
};

// Prefix & postfix -> 2 pass
// Time:O(N)
// Space:O(1) Optimize space from O(N) -> O(1)
// [prefix(1, 2,) 3, postfix(4, 5)]
class Solution3
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> answer(nums.size(), 1);
        int prefix = 1;
        for (int i = 0; i < answer.size(); i++)
        {
            answer[i] = prefix;
            prefix *= nums[i];
        }
        int postfix = 1;
        for (int i = answer.size() - 1; i >= 0; i--)
        {
            answer[i] *= postfix;
            postfix *= nums[i];
        }
        return answer;
    }
};

void showResult(const vector<int> &result)
{
    cout << "[ ";
    for (auto num : result)
    {
        cout << num << " ";
    }
    cout << "]" << endl;
}

int main()
{
    vector<int> test1 = {1, 2, 3, 4}; // [24, 12, 8, 6]
    vector<int> test2 = {1, 2, 0, 3}; // [0, 0, 6, 0]
    vector<int> test3 = {0, 1, 0, 2}; // [0, 0, 0, 0]

    Solution1 solution1;
    Solution2 solution2;
    Solution2 solution3;

    vector<int> result1;
    vector<int> result2;
    vector<int> result3;

    cout << "sol 1" << endl;
    result1 = solution1.productExceptSelf(test1);
    showResult(result1);
    result2 = solution1.productExceptSelf(test2);
    showResult(result2);
    result3 = solution1.productExceptSelf(test3);
    showResult(result3);


    cout << "sol 2" << endl;
    result1 = solution2.productExceptSelf(test1);
    showResult(result1);
    result2 = solution2.productExceptSelf(test2);
    showResult(result2);
    result3 = solution2.productExceptSelf(test3);
    showResult(result3);

    cout << "sol 3" << endl;
    result1 = solution3.productExceptSelf(test1);
    showResult(result1);
    result2 = solution3.productExceptSelf(test2);
    showResult(result2);
    result3 = solution3.productExceptSelf(test3);
    showResult(result3);

    return 0;
}
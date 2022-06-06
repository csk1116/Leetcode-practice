#include <iostream>
#include <vector>
using namespace std;

//Brute force
//T: O(N^2)
//S:
class Solution1
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> result;
        if(numbers.size() < 2)
            return result;

        for(int i = 0; i < numbers.size(); i++)
        {
            for(int j = i + 1; j < numbers.size(); j++)
            {
                int sum = numbers[i] + numbers[j];
                if(sum == target)
                {
                    result.push_back(j + 1);
                    result.push_back(i + 1);
                    cout << "sol1: " << i + 1 << ", " << j + 1 << endl;
                    return result;
                }
                else if(sum > target)
                {
                    continue;
                }
            }
        }

        cout << "not found" << endl;
        return result;
    }
};

//Two pointer
//T: O(N)
//S:

class Solution2
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> result;
        int left = 0;
        int right = numbers.size() - 1;
        while(left < right)
        {
            int sum = numbers[left] + numbers[right];
            if(sum == target)
            {
                result.push_back(right + 1);
                result.push_back(left + 1);
                cout << "sol2: " << left + 1 << ", " << right + 1 << endl;
                return result;
            }
            else
            {
                sum > target ? right -- : left ++;
            }
            // else if(sum > target)
            // {
            //     right --;
            // }
            // else
            // {
            //     left ++;
            // }
        }

        cout << "not found" << endl;
        return result;
    }
};



int main()
{
    vector<int> testVec1 = {2,7,11,15};
    vector<int> testVec2 = {-100, -30, -2, 0 , 1 ,7};

    //BF
    Solution1 solution1;
    solution1.twoSum(testVec1, 17);
    solution1.twoSum(testVec2, -100);

    //Two pointer
    Solution2 solution2;
    solution2.twoSum(testVec1, 17);
    solution2.twoSum(testVec2, -100);

    return 0;
}
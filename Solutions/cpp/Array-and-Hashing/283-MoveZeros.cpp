#include <iostream>
#include <vector>
using namespace std;

// Space Optimal
// Time:O(N)
// Space:O(1)
class Solution1
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int lastNonZeroIndex = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {                
                nums[lastNonZeroIndex] = nums[i];
                lastNonZeroIndex ++;
            }
        }

        for(int i = lastNonZeroIndex; i < nums.size(); i++)
        {
            nums[i] = 0;
        }

    }
};

// Space + Operation Optimal
// Time:O(N)
// Space:O(1)
class Solution2
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int lastNonZeroIndex = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {  
                swap(nums[lastNonZeroIndex], nums[i]);                
                lastNonZeroIndex ++;
            }
        }
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
    vector<int> sol1Test1 = {1, 0, 1, 0, 1};
    vector<int> sol1Test2 = {1, 1, 0};

    vector<int> sol2Test1 = {1, 0, 1, 0, 1};
    vector<int> sol2Test2 = {1, 1, 0};

    cout << "sol1 test1: " << endl;
    solution1.moveZeroes(sol1Test1);
    showResult(sol1Test1);

    cout << "sol1 test2: " << endl;
    solution1.moveZeroes(sol1Test2);
    showResult(sol1Test2);

    cout << "sol2 test1: " << endl;
    solution2.moveZeroes(sol2Test1);
    showResult(sol2Test1);

    cout << "sol2 test2: " << endl;
    solution2.moveZeroes(sol2Test2);
    showResult(sol2Test2);

    return 0;
}
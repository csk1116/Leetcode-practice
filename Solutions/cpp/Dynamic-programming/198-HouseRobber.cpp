#include <iostream>
#include <vector>
using namespace std;

// Brute force
// T:
// S:
class Solution1
{
public:
    int rob(vector<int> &nums)
    {
        return 0;
    }
};

// dp
// T:
// S:

class Solution2
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        int rob1 = 0;
        int rob2 = 0;
        int temp = 0;

        for (auto house : nums)
        {
            temp = max(rob1 + house, rob2);
            rob1 = rob2;
            rob2 = temp;
        }

        cout << "maximum amount: " << rob2 << endl;

        return rob2;
    }
};

int main()
{
    vector<int> houseVec1 = {2, 0, 0, 15, 7};
    vector<int> houseVec2 = {100, 30, 2, 0, 1, 7};

    // BF
    Solution1 solution1;
    solution1.rob(houseVec1);
    solution1.rob(houseVec2);

    // DP
    Solution2 solution2;
    solution2.rob(houseVec1);
    solution2.rob(houseVec2);

    return 0;
}
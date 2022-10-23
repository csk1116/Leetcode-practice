#include <iostream>
#include <algorithm> // max, min
using namespace std;

//two-pointer
// Time:O(N)
// Space:O(N)
class Solution1
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int maxVol = 0;

        while (left < right)
        {
            int currentVol = min(height[left], height[right]) * (right - left);
            maxVol = max(maxVol, currentVol);

            if (height[left] <= height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxVol;
    };

    //
    // Time:O()
    // Space:O()
    class Solution2
    {
    public:
    };

    int main()
    {

        Solution1 solution1;
        Solution2 solution2;

        return 0;
    }
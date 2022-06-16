#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

//sliding window
//Time:O(N)
//Space:O(N) 
class Solution1
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left, right, maxSubstrLength = 0;

        if(s.length() < 1)
            return 0;
        unordered_set<char> set;
        for(int right = 0; right < s.length(); right++)
        {
            while(set.find(s[right]) != set.end())
            {
                set.erase(s[left]);
                left ++;
            }
            set.insert(s[right]);
            maxSubstrLength = max(right - left + 1, maxSubstrLength);            
        }
        return maxSubstrLength;
    }
};

//
//Time:O()
//Space:O()
class Solution2
{
public:

};


int main()
{
    string testStr1 = "";
    string testStr2 = ",,,,,,,,,,,";
    string testStr3 = "abcdecfghij";

    Solution1 solution1;
    Solution2 solution2;

    cout << "S1 test1: " << solution1.lengthOfLongestSubstring(testStr1) << endl;
    cout << "S1 test2: " << solution1.lengthOfLongestSubstring(testStr2) << endl;
    cout << "S1 test3: " << solution1.lengthOfLongestSubstring(testStr3) << endl;


    return 0;
}
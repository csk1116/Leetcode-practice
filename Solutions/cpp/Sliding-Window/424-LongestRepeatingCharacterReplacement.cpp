#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// [ABCDA]A -> longest substring is valid only if: window size (right - left + 1)  > k + mode or maxfreq Count in the window 
// To get the mode or most freq cout in the window. The BF method would be O(26) for scan all uppercase letter every iteration. 

//sliding window (bucket)
//Time:O(N)
//Space:O(26) Upppercase Letter
class Solution1
{
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int longestSubstr = 0;
        int modeCount = 0; 
        vector<int> uppercaseArr(26, 0);
        
        for(int right = 0; right < s.length(); right ++)
        {
            int index = static_cast<int>(s[right] - 'A');
            uppercaseArr[index] ++;
            modeCount = max(uppercaseArr[index], modeCount);
            
            while((right - left + 1) > (k + modeCount))
            {
                index = static_cast<int>(s[left] - 'A');
                uppercaseArr[index] --;
                
                // actually we don't have to do this but its really hard to come across.
                //-----------------------------
                if(modeCount == uppercaseArr[index])
                {
                    modeCount --;
                }                    
                //-----------------------------
                
                left ++;
            }                
            
            longestSubstr = max(right - left + 1, longestSubstr);
        }
        return longestSubstr;
    }
};

//sliding window (hashmap)
//Time:O(N)
//Space:O(M) //M is the count of distinct char in string (<= 26)
class Solution2
{
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int longestSubstr = 0;
        int maxCount = 0; 
        
        unordered_map<char, int> map;
        
        for(int right = 0; right < s.length(); right ++)
        {            
            map[s[right]] ++;
            maxCount = max(map[s[right]], maxCount);
            
            while((right - left + 1) > (k + maxCount))
            {
                map[s[left]] --;
                
                // actually we don't have to do this but its really hard to come across
                //-----------------------------
                if(maxCount == map[s[left]])
                {
                    maxCount --;
                }                    
                //-----------------------------

                left ++;
            }                
            
            longestSubstr = max(right - left + 1, longestSubstr);
        }
        return longestSubstr;
    }
};


int main()
{
    string testStr1 = "ABCDEFG"; //k = 0, 4, 999 -> ans = 1, 5, 7
    string testStr2 = "A"; //k = 0, 999 -> ans = 1, 1
    string testStr3 = "ABABA"; //K = 0, 1, 2 -> ans = 1, 3, 5

    Solution1 solution1;
    Solution2 solution2;

    cout << "Sol 1, test 1, ans 1: " << solution1.characterReplacement(testStr1, 0) << endl;
    cout << "Sol 1, test 1, ans 5: " << solution1.characterReplacement(testStr1, 4) << endl;
    cout << "Sol 1, test 1, ans 7: " << solution1.characterReplacement(testStr1, 999) << endl;

    cout << "Sol 1, test 2, ans 1: " << solution1.characterReplacement(testStr2, 0) << endl;
    cout << "Sol 1, test 2, ans 1: " << solution1.characterReplacement(testStr2, 999) << endl;

    cout << "Sol 1, test 3, ans 1: " << solution1.characterReplacement(testStr3, 0) << endl;
    cout << "Sol 1, test 3, ans 3: " << solution1.characterReplacement(testStr3, 1) << endl;
    cout << "Sol 1, test 3, ans 5: " << solution1.characterReplacement(testStr3, 2) << endl;

    cout << "Sol 2, test 1, ans 1: " << solution2.characterReplacement(testStr1, 0) << endl;
    cout << "Sol 2, test 1, ans 5: " << solution2.characterReplacement(testStr1, 4) << endl;
    cout << "Sol 2, test 1, ans 7: " << solution2.characterReplacement(testStr1, 999) << endl;

    cout << "Sol 2, test 2, ans 1: " << solution2.characterReplacement(testStr2, 0) << endl;
    cout << "Sol 2, test 2, ans 1: " << solution2.characterReplacement(testStr2, 999) << endl;

    cout << "Sol 2, test 3, ans 1: " << solution2.characterReplacement(testStr3, 0) << endl;
    cout << "Sol 2, test 3, ans 3: " << solution2.characterReplacement(testStr3, 1) << endl;
    cout << "Sol 2, test 3, ans 5: " << solution2.characterReplacement(testStr3, 2) << endl;
    
    return 0;
}
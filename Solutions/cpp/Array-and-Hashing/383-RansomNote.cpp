#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// hash table + Two pass
//  Time:O(N)
//  Space:O(N)
class Solution1
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> myMap;
        for (auto c : magazine)
        {
            myMap[c]++;
        }
        for (auto c : ransomNote)
        {
            if (myMap[c] == 0)
                return false;
            myMap[c]--;
        }
        return true;
    }
};

// array
// Time:O(N)
// Space:O(N)
class Solution2
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int counter[26]{0};
        for (auto c : magazine)
        {
            counter[c - 'a']++;
        }
        for (auto c : ransomNote)
        {
            if (counter[c - 'a'] == 0)
                return false;
            counter[c - 'a']--;
        }
        return true;
    }
};

int main()
{

    Solution1 solution1;
    Solution2 solution2;

    //false
    string ransomNote1 = "a";
    string magazine1 = "b";

    //true
    string ransomNote2 = "aa";
    string magazine2 = "aab";

    cout << "sol1, test1: " << endl;
    cout << solution1.canConstruct(ransomNote1, magazine1) << endl;
    cout << "sol1, test2: " << endl;
    cout << solution1.canConstruct(ransomNote2, magazine2) << endl;

    cout << "sol2, test1: " << endl;
    cout << solution2.canConstruct(ransomNote1, magazine1) << endl;
    cout << "sol2, test2: " << endl;
    cout << solution2.canConstruct(ransomNote2, magazine2) << endl;

    return 0;
}
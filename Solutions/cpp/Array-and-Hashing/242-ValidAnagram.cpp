#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

//unordered_map
//TIME: O(S+T)
//SPACE: O(S+T) 
class Solution1
{
public:
    bool isAnagram(string s, string t)
    {
        if(s == t)
            return true;
        if(s.length() != t.length())
            return false;
        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;

        for(int i = 0; i < s.length(); i++)
        {            
            mapS[s[i]] ++;
            mapT[t[i]] ++;
        }

        for(int i = 0; i < s.length(); i++)
        {            
            if(mapT.find(s[i]) != mapT.end())
            {
                if(mapS[s[i]] != mapT[s[i]])
                    return false;
            }
            else
                return false;                
        }

        return true;
    }
};

//SORT
//TIME: O(NlogN)
//SPACE: O(1)
class Solution2
{
public:
    bool isAnagram(string s, string t)
    {
        if(s == t)
            return true;
        if(s.length() != t.length())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
                
        return s == t;
    }
};



int main()
{
    string t1 = "cat";
    string s1 = "rat";

    string t2 = "anagram";
    string s2 = "nagaamr";

    string t3 = "dog";
    string s3 = "doggy";

    string t4 = "kate";
    string s4 = "kate";

    Solution1 solution1;
    Solution2 solution2;

    cout << "1. (1): " << solution1.isAnagram(s1, t1) << " (2): " << solution2.isAnagram(s1, t1) << endl;
    cout << "2. (1): " << solution1.isAnagram(s2, t2) << " (2): " << solution2.isAnagram(s2, t2) << endl;
    cout << "3. (1): " << solution1.isAnagram(s3, t3) << " (2): " << solution2.isAnagram(s3, t3) << endl;
    cout << "4. (1): " << solution1.isAnagram(s4, t4) << " (2): " << solution2.isAnagram(s4, t4) << endl;

    return 0;
}
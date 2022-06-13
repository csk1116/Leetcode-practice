#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

//use 242-valid anagram and loop -> time exceed XD
//Time:O(N^2)
//Space:O(MN)
class Solution1
{
private:
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
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> result;
        vector<string> group;
        group.push_back(strs[0]);
        result.push_back(group);     
        if(strs.size() < 2)
            return result;     

        for(int i = 1; i < strs.size(); i++)
        {    
            bool isGroup = false;        
            for(int j = 0; j < result.size(); j++)
            {
                if(isAnagram(strs[i],result[j][0]))
                {
                    result[j].push_back(strs[i]);
                    isGroup = true;
                    break;
                }                
            }
            if(!isGroup)
            {
                vector<string> newGroup;
                newGroup.push_back(strs[i]);
                result.push_back(newGroup);    
            }                    
        }

        return result;
    }
};

//sort + unordered_map
//Time:O(M*NlogN)
//Space:O(1)
class Solution2
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> result;
        unordered_map<string, int> map; //<sorted string, index>
        int groupIndex = 0;

        for(int i = 0; i < strs.size(); i++)
        {
            string strToSort = strs[i];
            sort(strToSort.begin(), strToSort.end());
            if(map.find(strToSort) != map.end())
            {
                int index = map[strToSort];
                result[index].push_back(strs[i]);
            }
            else
            {
                map[strToSort] = groupIndex++;
                vector<string> group;
                group.push_back(strs[i]);
                result.push_back(group);
            }
        }      
        
        return result;
    }

    //another good & clean implementation
    vector<vector<string>> groupAnagrams1(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};

//using counting sort to improve time complexity -> string only contains lower-case alphabets
//Time:O(M*N*26)
//Space:O()
class Solution3
{
private:
    string strCountingSort(string str)
    {
        int counter[26] = {0};
        for(char c: str)
        {
            counter[c - 'a'] ++;
        }
        string sortedString;
        for(int i = 0; i < 26; i++)
        {
            sortedString += string(counter[i], i + 'a');
        }
        return sortedString;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {        
        unordered_map<string, vector<string>> map;
        for(string s: strs)
        {
            map[strCountingSort(s)].push_back(s);
        }

        vector<vector<string>> result;
        for(auto item: map)
        {
            result.push_back(item.second);
        }

        return result;        
    }
};

void ShowResult(const vector<vector<string>>& strVec)
{    
    for(auto group: strVec)
    {
        cout << "[";
        for(auto str: group)
        {            
            cout << "\"" << str << "\"";            
        }
        cout << "]" << endl;
    }
}


int main()
{
    //[["cat", "tca", "cta"], ["kaate", "aaket"], ["asd"], ["ad"], ["aake"], ["at"]]
    vector<string> testStringVec1 = {"cat", "tca", "at", "kaate", "aaket", "asd", "ad", "aake", "cta"}; 
    vector<string> testStringVec2 = {""};
    vector<string> testStringVec3 = {"a"};    

    Solution1 solution1;
    Solution2 solution2;
    Solution2 solution3;
    vector<vector<string>> result1;
    vector<vector<string>> result2;
    vector<vector<string>> result3;

    result1 = solution1.groupAnagrams(testStringVec1);
    result2 = solution2.groupAnagrams(testStringVec1);
    result3 = solution3.groupAnagrams(testStringVec1);
    ShowResult(result1);
    ShowResult(result2);
    ShowResult(result3);
    result1 = solution1.groupAnagrams(testStringVec2);
    result2 = solution2.groupAnagrams(testStringVec2);
    result3 = solution3.groupAnagrams(testStringVec2);
    ShowResult(result1);
    ShowResult(result2);
    ShowResult(result3);
    result1 = solution1.groupAnagrams(testStringVec3);
    result2 = solution2.groupAnagrams(testStringVec3);
    result3 = solution3.groupAnagrams(testStringVec3);
    ShowResult(result1);
    ShowResult(result2);
    ShowResult(result3);   
    
    return 0;
}
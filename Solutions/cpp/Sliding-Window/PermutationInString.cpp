#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// sort
// Time:O(NlogN)
// Space:O()
class Solution1
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int left = 0;
        int right = s1.length() - 1;
        sort(s1.begin(), s1.end());

        while (right < s2.length())
        {
            string subString = "";
            for (int i = left; i <= right; i++)
            {
                subString += s2[i];
            }
            sort(subString.begin(), subString.end());

            if (s1 == subString)
                return true;

            left++;
            right++;
        }
        return false;
    }
};

// frequency
//  Time:O(N)
//  Space:O(N)
class Solution2
{
private:
    bool isSameVector(const vector<int> &s1, const vector<int> &s2)
    {
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
                return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        int left = 0;
        int right = s1.length() - 1;
        vector<int> s1Frequency(26, 0);

        for (int i = 0; i < s1.length(); i++)
        {
            s1Frequency[s1[i] - 'a']++;
        }

        while (right < s2.length())
        {
            vector<int> s2Frequency(26, 0);
            for (int i = left; i <= right; i++)
            {
                s2Frequency[s2[i] - 'a']++;
            }

            if (isSameVector(s1Frequency, s2Frequency))
                return true;

            left++;
            right++;
        }
        return false;
    }
};

// frequency optimize
//  Time:O(N)
//  Space:O(N)
class Solution2
{
    bool areVectorsEqual(vector<int> a, vector<int> b)
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        if (s2.size() < s1.size())
            return false;
        vector<int> freqS1(26, 0);
        for (char c : s1)
            freqS1[c - 'a']++;

        vector<int> freqS2(26, 0);
        int i = 0, j = 0;

        while (j < s2.size())
        {
            freqS2[s2[j] - 'a']++;

            if (j - i + 1 == s1.size())
            {
                if (areVectorsEqual(freqS1, freqS2))
                    return true;
            }

            if (j - i + 1 < s1.size())
                j++;
            else
            {
                freqS2[s2[i] - 'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};

int main()
{

    Solution1 solution1;
    Solution2 solution2;

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

//implement isalnum()
//ASCII code printable 32 ~ 126
bool isalnum_I(const char& c)
{
    bool isUpperAlpha = false;
    bool isLowerAlpha = false;
    bool isDigit = false;
    int ascii = static_cast<int>(c);
    if(ascii >= static_cast<int>('A') &&  ascii <= static_cast<int>('Z')) isUpperAlpha = true;
    if(ascii >= static_cast<int>('a') &&  ascii <= static_cast<int>('z')) isLowerAlpha = true;
    if(ascii >= static_cast<int>('0') &&  ascii <= static_cast<int>('9')) isDigit = true;

    return isUpperAlpha || isLowerAlpha || isDigit;
}

//two pointers
//Time:O(N)
//Space:O(1)
class Solution1
{
public:
    bool isPalindrome(string s)
    {
        int left = 0; 
        int right = s.length() - 1;
        for(int i = left, j = right; i < j; i++, j--)
        {
            while(!isalnum(s[i]) && i < j)
                i++;
            while(!isalnum(s[j]) && i < j)
                j--;
            if(tolower(s[i]) != tolower(s[j]))
                return false;
        }
        return true;        
    }
};

//remove non-alphanumeric and reverse
//Time:O(N)
//Space:O(N)
class Solution2
{
public:
    bool isPalindrome(string s)
    {
        string alphanumericStr = "";
        for(auto c: s)
        {
            if(isalnum_I(c))
                alphanumericStr += tolower(c); 
        }
        string reverseStr = string(alphanumericStr.rbegin(), alphanumericStr.rend());
        return alphanumericStr == reverseStr;
    } 
};

int main()
{    
    Solution1 solution1;
    Solution2 solution2;

    string testStr1 = " ";
    string testStr2 = ".,]-";
    string testStr3 = "100 A man, a plan, a canal: Panama 001";
    string testStr4 = "Not a palindrome";
    
    cout << "sol1, test1: " << solution1.isPalindrome(testStr1) << endl;
    cout << "sol1, test2: " << solution1.isPalindrome(testStr2) << endl;
    cout << "sol1, test3: " << solution1.isPalindrome(testStr3) << endl;
    cout << "sol1, test4: " << solution1.isPalindrome(testStr4) << endl;

    cout << "sol2, test1: " << solution2.isPalindrome(testStr1) << endl;
    cout << "sol2, test2: " << solution2.isPalindrome(testStr2) << endl;
    cout << "sol2, test3: " << solution2.isPalindrome(testStr3) << endl;
    cout << "sol2, test4: " << solution2.isPalindrome(testStr4) << endl;

    return 0;
}
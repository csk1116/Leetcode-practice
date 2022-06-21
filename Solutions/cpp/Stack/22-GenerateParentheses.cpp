#include <iostream>
#include <string>
#include <vector>
using namespace std;

//BackTracking
//Time:O(N)
//Space:O()
class Solution1
{    
public:    
    void backTrack(vector<string>& vec, string s, int open, int close)
    {
        if(open == 0 && close == 0)
        {
            vec.push_back(s);
            return;
        }
        
        if(open <= close && open >= 0 && close >= 0)
        {           
            backTrack(vec, (s + "("), open - 1, close);
            backTrack(vec, (s + ")"), open, close -1);
        }        
    }    
    vector<string> generateParenthesis(int n) {     
        vector<string> result;
        string validParentheses = "";      
        int open = n;
        int close = n;  
        backTrack(result, validParentheses, open, close);            
        return result;
    }   
};

//
//Time:O()
//Space:O()
class Solution2
{
public:

};

void ShowResult(const vector<string>& vec)
{
    for(int i = 0; i < vec.size(); i ++)
    {
        cout << vec[i] << endl;
    }
}


int main()
{

    Solution1 solution1;
    Solution2 solution2;

    vector<string> myResult;
    myResult = solution1.generateParenthesis(1);
    ShowResult(myResult);
    myResult = solution1.generateParenthesis(2);
    ShowResult(myResult);
    myResult = solution1.generateParenthesis(3);
    ShowResult(myResult);
    
    return 0;
}
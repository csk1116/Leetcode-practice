#include <iostream>
#include <string>
#include <vector>
using namespace std;

//BackTracking
//Time:O()
//Space:O()
class Solution1
{    
public:            
    vector<string> generateParenthesis(int n) 
    {     
        vector<string> result;
        string validParentheses = "";      
        int open = n;
        int close = n;  
        backTrack(result, validParentheses, open, close);            
        return result;
    } 
    void backTrack(vector<string>& vec, string str, int open, int close)
    {
        //terminate condition
        if(open == 0 && close == 0)
        {
            vec.push_back(str);
            return;
        }
        
        //(open <= close) is the only situation that the parentheses is valid 
        // ")" -> open = 3, close = 2 -> invalid, "())" -> open = 2, close = 1 -> invalid)
        if(open <= close && open >= 0 && close >= 0)
        {           
            backTrack(vec, str + "(", open - 1, close);
            backTrack(vec, str + ")", open, close - 1);
        }        
    }  
};

//
//Time:O()
//Space:O()
class Solution2
{
public:
    vector<string> generateParenthesis(int n) 
    {     
        vector<string> result;
        string validParentheses = "";
        backTrack(result, validParentheses, 0, 0, n);            
        return result;
    } 
    void backTrack(vector<string>& vec, string str, int open, int close, int max)
    {
        //terminate condition
        if(open == max && close == max)
        {
            vec.push_back(str);
            return;
        }
        
        //(open > close) is the only situation that we can add a closing parentheses ")" 
        // ")" -> open = 0, close = 1 -> invalid, "())" -> open = 1, close = 2 -> invalid)
        if(open < max)
            backTrack(vec, str + "(", open + 1, close, max);
        if(open > close)
            backTrack(vec, str + ")", open, close + 1, max);             
    }
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

    myResult = solution2.generateParenthesis(1);
    ShowResult(myResult);
    myResult = solution2.generateParenthesis(2);
    ShowResult(myResult);
    myResult = solution2.generateParenthesis(3);
    ShowResult(myResult);
    
    return 0;
}
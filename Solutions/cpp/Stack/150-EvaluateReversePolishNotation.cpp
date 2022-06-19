#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <functional> //for cool method
#include <string>
#include <stack>
#include <vector>
using namespace std;

//RPN is refer to https://en.wikipedia.org/wiki/Reverse_Polish_notation

//stack + set to store operand
//Time:O(N)
//Space:O(N)
class Solution1
{
public:
    int evalRPN(vector<string>& tokens) {
        
        unordered_set<string> set = {"+", "-", "*", "/"};
        stack<int> myStack;
        int result = 0;
        
        if(tokens.size() < 2)
            result = stoi(tokens[0]);
        
        for(auto s: tokens)
        {            
            if(set.find(s) == set.end())
            {
                myStack.push(stoi(s)); 
            }
            else
            {
                int term2 = myStack.top();
                myStack.pop();
                int term1 = myStack.top();
                myStack.pop();                
                
                if(s == "+")    
                    result = term1 + term2;
                if(s == "-")    
                    result = term1 - term2;
                if(s == "*")    
                    result = term1 * term2;
                if(s == "/")    
                    result = term1 / term2;
                
                myStack.push(result);
            }
        }        
        return result;        
    }
};

//Cool method of mapping string to operator. Found in discussion. 
//Time:O(N)
//Space:O(N)
class Solution2
{
public:
    int evalRPN(vector<string>& tokens) {
        
        unordered_map<string, function<int (int, int) > > map = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };

        stack<int> myStack;

        for (auto s : tokens) {
            if (!map.count(s)) 
            {
                myStack.push(stoi(s));
            } 
            else 
            {
                int op1 = myStack.top();
                myStack.pop();
                int op2 = myStack.top();
                myStack.pop();
                myStack.push(map[s](op2, op1));
            }
        }
        return myStack.top();
    }
};


int main()
{
    vector<string> tokens1 = {"999"}; //999
    vector<string> tokens2 = {"1", "2", "+"}; //3
    vector<string> tokens3 = {"1", "2", "3", "4", "+", "*", "-", "5", "/"}; //-2


    Solution1 solution1;
    Solution2 solution2;

    cout << "Sol 1, tokens 1, ans 999: " << solution1.evalRPN(tokens1) << endl;
    cout << "Sol 1, tokens 2, ans 3: " << solution1.evalRPN(tokens2) << endl;
    cout << "Sol 1, tokens 2, ans -2: " << solution1.evalRPN(tokens3) << endl;

    cout << "Sol 2, tokens 1, ans 999: " << solution2.evalRPN(tokens1) << endl;
    cout << "Sol 2, tokens 2, ans 3: " << solution2.evalRPN(tokens2) << endl;
    cout << "Sol 2, tokens 2, ans -2: " << solution2.evalRPN(tokens3) << endl;
    
    return 0;
}
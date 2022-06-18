#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

//stack
//Time:O(N)
//Space:O(N)
class Solution1
{
public:
    bool isValid(string s)
    {
        stack<char> myStack;
        for(auto p: s)
        {
            if(p == '(' || p == '[' || p == '{')
            {
                myStack.push(p);                
            }
            else
            {
                if(!myStack.empty())
                {
                    if( (p == ')' && myStack.top() == '(') ||
                        (p == ']' && myStack.top() == '[') ||
                        (p == '}' && myStack.top() == '{') )
                        myStack.pop(); 
                    else    
                        return false;
                }   
                else
                {
                    return false;
                }             
            }
        }
        return myStack.empty();        
    }
};

//stack + hash map for not hard coding 
//Time:O(N)
//Space:O(N)
class Solution2
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> closeToOpen({{')', '('}, {']', '['}, {'}', '{'}});
        stack<char> myStack;
        for(auto p: s)
        {
            if(closeToOpen.find(p) != closeToOpen.end())
            {
                if(!myStack.empty() && closeToOpen[p] == myStack.top())
                    myStack.pop(); 
                else    
                    return false;  
            }
            else
            {
                myStack.push(p);                             
            }
        }
        return myStack.empty();        
    }
};


int main()
{
    string testStr1 = "([{";
    string testStr2 = ")[]{}";
    string testStr3 = "{([])}{()}";
    string testStr4 = "(}";

    Solution1 solution1;
    Solution2 solution2;

    cout << "Sol 1, test1, false: " << solution1.isValid(testStr1) << endl;
    cout << "Sol 1, test2, false: " << solution1.isValid(testStr2) << endl;
    cout << "Sol 1, test3, true: " << solution1.isValid(testStr3) << endl; 
    cout << "Sol 1, test4, false: " << solution1.isValid(testStr4) << endl;

    cout << "Sol 2, test1, false: " << solution2.isValid(testStr1) << endl;
    cout << "Sol 2, test2, false: " << solution2.isValid(testStr2) << endl;
    cout << "Sol 2, test3, true: " << solution2.isValid(testStr3) << endl; 
    cout << "Sol 2, test4, false: " << solution2.isValid(testStr4) << endl;
    
    return 0;
}
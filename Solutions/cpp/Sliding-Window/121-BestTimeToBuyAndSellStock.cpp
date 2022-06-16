#include <iostream>
#include <vector>
using namespace std;

//two pointer
//Time:O(N)
//Space:O(1)
class Solution1
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int max = 0;
        int buy = 0;
        int sell = buy + 1;
        
        while(sell < prices.size())
        {
            int tempProfit = prices[sell] - prices[buy];
            if(tempProfit > max)
                max = tempProfit;
            
            if(tempProfit <= 0)
            {
                buy = sell;
                sell ++;
            }
            else
            {
                sell ++;
            }           
        }
        return max;
    }

};


//Time:O(N)
//Space:O(1)
class Solution2
{
public:
    int maxProfit(vector<int>& prices) {
        
        int min = INT_MAX;
        int max = INT_MIN;
        int maxProfit = 0;
        
        for(auto price: prices)
        {
            if(price < min)
            {
                min = price;
                max = price;
            }
            if(price > max)
            {
                max = price;
            }
            
            if((max - min) > maxProfit)
            {
                maxProfit = max - min;
            }            
        }                        
        return maxProfit;
    }
};


int main()
{

    Solution1 solution1;
    Solution2 solution2;

    vector<int> testPrices1 = {5, 4, 3, 2, 1};
    vector<int> testPrices2 = {2, 2, 2, 2, 2};
    vector<int> testPrices3 = {8, 1, 1, 8, 9};

    cout << "S1 test1: " << solution1.maxProfit(testPrices1) << endl;
    cout << "S1 test2: " << solution1.maxProfit(testPrices2) << endl;
    cout << "S1 test3: " << solution1.maxProfit(testPrices3) << endl;

    cout << "S2 test1: " << solution2.maxProfit(testPrices1) << endl;
    cout << "S2 test2: " << solution2.maxProfit(testPrices2) << endl;
    cout << "S2 test3: " << solution2.maxProfit(testPrices3) << endl;
    
    return 0;
}
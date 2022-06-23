#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

//BF -> time limit exceeded
//Time:O(max(P)*N)
//Space:O(1)
class Solution1
{
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {                
        int maxPile = INT_MIN;
        for(auto p: piles)
        {
            maxPile = max(maxPile, p);
        }
        
        int k = 1; //BF to start at 1 to the max pile
        while(k < maxPile)
        {
            double totalHours = 0; //a bit tricky, if k start at 1, totalHours might get overflow. Moreover, it will be really small when max pile is really large.
            for(auto p: piles)
            {
                totalHours += ceil(static_cast<double>(p) / k);
            }
            if(totalHours > h)
                k++;
            else
                break;                
        }
        return k;
    }
};

//BF improved by binary search 
//Time:O(log(max(P)) * N)
//Space:O(1)
class Solution2
{
public:
     int minEatingSpeed(vector<int>& piles, int h) 
     {
        int maxPile = INT_MIN;
        for(auto p: piles)
        {
            maxPile = max(maxPile, p);
        } 

        int result = maxPile;
        int minPile = 1;         
        while(minPile <= maxPile)
        {
            int k = minPile + (maxPile - minPile) / 2;
            int totalHours = 0;

            for(auto p: piles)
            {
                totalHours += ceil(static_cast<double>(p)/ k); //cast to double is more safe
            }

            if(totalHours <= h)
            {
                result = min(result, k);
                maxPile = k - 1;
            }
            else
            {
                minPile = k + 1;
            }
        }
        return result;
     }
};


int main()
{    
    vector<int> testPiles1 = {1, 5, 3, 4, 2}; //(a) h = 5, k = 5, (b) h = 8, k = 3
    vector<int> testPiles2 = {1}; //h = 100, k = 1
    vector<int> testPiles3 = {50}; //h = 2, k = 25

    Solution1 solution1;
    Solution2 solution2;

    cout << "Sol 1, testPile1, h = 5, k = 5: " << solution1.minEatingSpeed(testPiles1, 5) << endl;
    cout << "Sol 1, testPile1, h = 8, k = 3: " << solution1.minEatingSpeed(testPiles1, 8) << endl;    
    cout << "Sol 1, testPile2, h = 100, k = 1: " << solution1.minEatingSpeed(testPiles2, 100) << endl;    
    cout << "Sol 1, testPile3, h = 2, k = 25: " << solution1.minEatingSpeed(testPiles3, 2) << endl;    

    cout << "Sol 2, testPile1, h = 5, k = 5: " << solution2.minEatingSpeed(testPiles1, 5) << endl;
    cout << "Sol 2, testPile1, h = 8, k = 3: " << solution2.minEatingSpeed(testPiles1, 8) << endl;    
    cout << "Sol 2, testPile2, h = 100, k = 1: " << solution2.minEatingSpeed(testPiles2, 100) << endl; 
    cout << "Sol 2, testPile3, h = 2, k = 25: " << solution2.minEatingSpeed(testPiles3, 2) << endl;    

    
    return 0;
}
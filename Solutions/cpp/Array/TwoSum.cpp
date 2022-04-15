#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> result;
            
        for(int i = 0; i < nums.size(); i++)
        {                 
            int temp = target - nums[i];
            
            for(int j = i+1; j< nums.size(); j++)
            {
              if(nums[j] == temp)
              {            
                  result.push_back(i);
                  result.push_back(j);
              }
            }
        }            
        return result;
    }
};

int main(){
    
    Solution sl;   
    vector<int> number = {10, 20, 30};
    int target = 30;

    vector<int> result = sl.twoSum(number, target);

    cout <<  result[0] << ", " << result[1] << "hihi";

    return 0;
}
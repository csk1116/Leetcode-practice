#include <iostream>
#include <vector>
#include <utility> //pair
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

//unordered_map & sort the map by value -> we can use heap to optimize the time complexity to klogM
//Time:O(MlogM) -> M is the size of the map(not the array size)
//Space:O(M)

typedef pair<int, int> elementFrequent;
bool compByValue(const elementFrequent& a, const elementFrequent& b)
{
    return (a.second > b.second); //descending
}

class Solution1
{
public:    
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> map;        
        for(auto num: nums)
        {
            map[num] ++;
        }

        unordered_map<int, int>::iterator it;
        vector<elementFrequent> vec;
        for(it = map.begin(); it != map.end(); it++)
        {
            vec.push_back(make_pair(it->first, it->second));
        }

        sort(vec.begin(), vec.end(), compByValue);        

        vector<int> result;
        for(int i = 0; i < k; i++)
        {
            result.push_back(vec[i].first);
        }        

        return result;
    }
};

//hash table and bucket sort
//Time:O(N)
//Space:O(N)
class Solution2
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> map;        
        for(auto num: nums)
        {
            map[num] ++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for(auto item: map)
        {
            buckets[item.second].push_back(item.first);
        }

        vector<int> result;
        for(int i = buckets.size() - 1; i >= 0; i--)
        {
            if(result.size() == k)
                break;
            for(auto num: buckets[i])
            {
                result.push_back(num);                
            }
        }

        return result;
    }
};

//heap (priority queue)
//Time:O(klogM) M is the size of the map(not the array size)
//Space:O(M)
class Solution3
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> map;        
        for(auto num: nums)
        {
            map[num] ++;
        }

        vector<int> result;
        return result;        
    }
};

void showResult(const vector<int>& result)
{
    cout << "[ ";
    for(auto num: result)
    {
        cout << num << " "; 
    }
    cout << "]" << endl;
}


int main()
{

    vector<int> test1 = {1, 3, 5, 1, 1, 1, 3}; //k = 1, k = 2, k = 3    
    vector<int> test2 = {1}; //k = 1
    vector<int> test3 = {1, 1, 1, 3, 3, 3, 2, 2}; //k = 2

    Solution1 solution1;
    Solution2 solution2;
    Solution3 solution3;
    
    vector<int> result1;
    vector<int> result2;
    vector<int> result3;
    
    result1 = solution1.topKFrequent(test1, 1);
    result2 = solution2.topKFrequent(test1, 1);
    showResult(result1);
    showResult(result2);
    result1 = solution1.topKFrequent(test1, 2);
    result2 = solution2.topKFrequent(test1, 2);
    showResult(result1);
    showResult(result2);
    result1 = solution1.topKFrequent(test1, 3);
    result2 = solution2.topKFrequent(test1, 3);
    showResult(result1);
    showResult(result2);

    result1 = solution1.topKFrequent(test2, 1);
    result2 = solution2.topKFrequent(test2, 1);
    showResult(result1);
    showResult(result2);

    result1 = solution1.topKFrequent(test3, 2);
    result2 = solution2.topKFrequent(test3, 2);
    showResult(result1);
    showResult(result2);
    
    return 0;
}
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    vector<int> twoSum(vector<int> nums, int target) 
    {
        vector<int> answers;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
               if(nums[i] + nums[j] == target)
               {
                answers.push_back(i);
                answers.push_back(j);
               return answers;
               }
            }
        }
        return answers;
    }
 //solution 2 HASHMAP python
    def twoSum(self, nums: List[int],target: int) -> List[int]:
        prevMap = {} //# val and index using enumerate aka keeps track of hte index
        for i, n in enumerate(nums):
            diff = target - n
            if diff in prevMap:
                return [prevMap[diff], i]
            prevMap[n] = i
    
    
    int main()
    {
        int target;
        vector<int> nums;
        cin>>target;
        twoSum(nums,target);
        return 0;
    }
};

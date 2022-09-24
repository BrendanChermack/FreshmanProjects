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
    
    int main()
    {
        int target;
        vector<int> nums;
        cin>>target;
        twoSum(nums,target);
        return 0;
    }
};
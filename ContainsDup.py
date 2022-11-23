class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        
        i = 0
        tester = False
        while i < len(nums):
            if tester == True:  
                break
            j = i+1
            while j < len(nums):
                if(nums[i] == nums[j]):
                    tester = True
                j+=1
            i+=1
        return tester
"""
#DUE TO TIME LIMIT THIS SOLUTION WAS NOT ACCEPTED
        hset = set()
        for idx in nums:
            if idx in hset:
                return True
            else:
                hset.add(idx)

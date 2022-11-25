class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
       remove the nums[i] and asign it to a varible then multiple all the elements then add it back to the end and repeat
        """
        #prefix
        #sufix
        #output
        answer = [1]* len(nums)
        pre = 1
        suf = 1
        for i in range(len(nums)):
            answer[i] = pre
            pre *= nums[i] 
        for i in range(len(nums)-1,-1,-1): #starts at the end of the array and goes to the begning 
            answer[i] *= suf #doesnt override the prevoius vals
            suf *= nums[i]
        return answer    

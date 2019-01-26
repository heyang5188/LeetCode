

class Solution:
    def twoSum(self, nums, target):
        """ 
        :type nums: List[int] 
        :type target: int 
        :rtype: List[int] 
        """
        # 创建一个空字典
        d = {}
        for x in range(len(nums)):
            a = target - nums[x]
            if nums[x] in d:
                return d[nums[x]], x
            else:  # 否则往字典增加键/值对
                d[a] = x  # 边往字典增加键/值对，边与nums[x]进行对比

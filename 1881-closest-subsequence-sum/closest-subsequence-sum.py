class Solution:
    def minAbsDifference(self, nums: List[int], goal: int) -> int:
        
        def fn(nums):
            ans = {0}
            for x in nums: 
                ans |= {x + y for y in ans}
            return ans 
        
        nums0 = sorted(fn(nums[:len(nums)//2]))
        
        ans = inf
        for x in fn(nums[len(nums)//2:]): 
            k = bisect_left(nums0, goal - x)
            if k < len(nums0): ans = min(ans, nums0[k] + x - goal)
            if 0 < k: ans = min(ans, goal - x - nums0[k-1])
        return ans 
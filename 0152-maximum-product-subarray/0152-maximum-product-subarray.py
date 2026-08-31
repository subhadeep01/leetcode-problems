class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = float('-inf')
        pref,suff = 1,1
        for i in range(len(nums)):
            pref = pref*nums[i]
            suff = suff*nums[len(nums)-i-1]

            ans = max(ans,pref,suff)
            if pref == 0:
                pref = 1

            if suff == 0:
                suff = 1
        return ans

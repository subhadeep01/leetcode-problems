class Solution:
    def maxValidSplits(self, arr: list[int]) -> int:
        """
        :type nums: List[int]
        :rtype: int
        """
        # def gcd(a, b):
        #     while b:
        #         a, b = b, a % b
        #     return a
        
        import math 
        from math import gcd
        n = len(arr)
        global_max_score = 0
        # k = n means no element removal else removal of nums[k]
        for k in range(n+1):

            if k == n:
                nums = arr
            else:
                nums = arr[:k] + arr[k+1:]

            m = len(nums)
            if (m<2):
                continue
    
        
            prefix_gcd = [0] * m
            prefix_gcd[0] = nums[0]
            suffix_gcd = [0] * m
            suffix_gcd[m-1] = nums[m-1]
            for i in range(1,m):
                prefix_gcd[i] = gcd(prefix_gcd[i-1],nums[i])
            for i in range(m-2,-1,-1):
                suffix_gcd[i] = gcd(suffix_gcd[i+1],nums[i])
            max_score = 0
            for i in range(m-1):
                if prefix_gcd[i] == suffix_gcd[i+1]:
                    max_score+=1
            global_max_score = max(global_max_score,max_score)

        
        return global_max_score
        
        
        
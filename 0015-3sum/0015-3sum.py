class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        ans = []
        n = len(nums)
        for i in range(n):

            if i>0 and nums[i]==nums[i-1]:
                continue

            start, end = i+1,n-1
            while(start<end):
                target = nums[i] + nums[start] + nums[end]

                if target == 0:
                    ans.append([nums[i],nums[start],nums[end]])
                    start+=1
                    end-=1

                    while(start<end and nums[start]==nums[start-1]):
                        start+=1

                    while(start<end and nums[end]==nums[end+1]):
                        end-=1
                elif target<0:
                    start+=1
                else:
                    end-=1

        return ans
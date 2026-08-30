class Solution(object):
    def countSpecialIntegers(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        map = {}
        for i in range(len(nums)):
            map[nums[i]]=map.get(nums[i],0)+1
        cnt = 0
        set_nums = set(nums)
        for item in set_nums:
            get_start = -1
            for i in range(len(nums)):
                if nums[i]==item:
                    get_start = i
                    break
            
            item_cnt = map[item]
            c = 0
            while(get_start<len(nums)):
                if nums[get_start]==item:
                    c+=1
                    get_start+=1
                else:
                    break
            if c == item_cnt:
                cnt+=1
        
        return cnt

        
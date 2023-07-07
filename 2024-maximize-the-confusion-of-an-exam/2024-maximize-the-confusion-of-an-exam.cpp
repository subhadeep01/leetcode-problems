class Solution {
public:
    int maxConsecutiveAnswers(string nums, int k) {
        // T T F F T T F F T T T F T F F F F 
        int ans=0, flip_count=0;
        int n=nums.size();
        int s=0,e=0;
        while(e<n)
        {
            if(nums[e]=='T')
                e++;
            else if(nums[e]=='F' && flip_count<k)
            {
                flip_count++;
                e++;
            }
            else // flip_count>=k
            {
                while(flip_count>=k)
                {
                    if(nums[s]=='F')
                    flip_count--;
                    s++;
                }
                
            }
            ans=max(ans,e-s);
        }
        
        flip_count=0;
        s=0,e=0;
        while(e<n)
        {
            if(nums[e]=='F')
                e++;
            else if(nums[e]=='T' && flip_count<k)
            {
                flip_count++;
                e++;
            }
            else // flip_count>=k
            {
                while(flip_count>=k)
                {
                    if(nums[s]=='T')
                    flip_count--;
                    s++;
                }
                
            }
            ans=max(ans,e-s);
        }
        return ans;
    }
};
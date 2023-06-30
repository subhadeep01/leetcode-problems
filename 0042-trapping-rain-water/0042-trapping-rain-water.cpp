class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int left_max=0,right_max=0;
        int water=0;
        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                left_max=max(left_max,height[left]);
                water+=max(0,left_max-height[left]);
                left++;
            }
            else
            {                
                right_max=max(right_max,height[right]);
                water+=max(0,right_max-height[right]);
                right--;
            }
        }
        return water;
    }
};
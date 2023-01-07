class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,water=0;
        while(i<j)
        {
            int h=min(height[i],height[j]);
            water=max(water,(j-i)*h);
            while(i<height.size() && height[i]<=h)i++;
            while(j>=0 && height[j]<=h)j--;
        }
        return water;
    }
};
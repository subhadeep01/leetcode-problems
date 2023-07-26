class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int n=dist.size();
        int low=1,high=1e9;
        int speed=1e9;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            
            double tm = 0.0;
            for(int i = 0; i < n - 1; i++) {
                tm += (dist[i] + mid - 1) / mid;
            }
            tm += double(dist[n - 1]) / mid;
            
            if(tm<=hour)
            {
            speed=min(speed,mid);
            high=mid-1;
            }
            else
            low=mid+1;
        }
        if(speed==1e9) return -1;
        return speed;
    }
};
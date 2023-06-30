class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //nge modified
        int n=temperatures.size();
        vector<int>nge_ind(n);
        stack<pair<int,int>>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top().first<=temperatures[i])
                st.pop();
            
            if(st.empty())
                nge_ind[i]=0;
            else
                nge_ind[i]=st.top().second-i;
            
            st.push({temperatures[i],i});
        }
        return nge_ind;
    }
};
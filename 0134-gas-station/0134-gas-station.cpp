class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans=0;
        int n=gas.size();
        if(n==1)
        {
            if(gas[0]>=cost[0]) return 0;
            else
            return -1;
        }
        int i=0;
        int curr_gas=gas[0];
        int curr_cost=cost[0],tot_cost=0,tot_gas=0;
        while(i<n)
        {
            tot_gas+=gas[i];
            tot_cost+=cost[i];
            if(curr_gas>=curr_cost)
            {
                curr_gas-=curr_cost;
                curr_gas+=gas[(i+1)%n];
                curr_cost=cost[(i+1)%n];
            }
            else
            {
            ans=i+1;
            curr_gas=gas[(i+1)%n];
            curr_cost=cost[(i+1)%n];
            }
            i++;
        }
        if(tot_gas<tot_cost || ans==n) return -1;
        else
        return ans;
    }
};
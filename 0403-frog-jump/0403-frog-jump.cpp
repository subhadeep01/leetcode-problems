class Solution {
public:
    bool f(vector<int>&stones, int lastIndex, int currIndex,vector<vector<int>>&dp)
    {
        if(currIndex==stones.size()-1) return true;
        if(dp[lastIndex][currIndex]==1) return false;
        int lastJump=stones[currIndex]-stones[lastIndex];
        int nextIndex=currIndex+1;
        while(nextIndex<stones.size() && stones[nextIndex]-stones[currIndex+1]<=lastJump+1)
        {
            int nextJump=stones[nextIndex]-stones[currIndex];
            int jump=nextJump-lastJump;
            if(jump>=-1 && jump<=1)
            {
                if(f(stones,currIndex,nextIndex,dp)) 
                    return true;
            }
            nextIndex++;
        }
        dp[lastIndex][currIndex]=1;
        return false;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)return false;
        int n=stones.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        return f(stones,0,1,dp);
    }
};
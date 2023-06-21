//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    bool f(int ind, int target, int nums[], vector<vector<int>>&dp)
    {
    
   if(target==0) return true;
   if(ind==0) return (target==nums[0]);
   if(dp[ind][target]!=-1)return dp[ind][target];
   bool take=false;
   if(nums[ind]<=target)
   take= f(ind-1, target-nums[ind],nums, dp);
   bool not_take=f(ind-1, target,nums,dp);
   return dp[ind][target]= (take | not_take);
}
	int minDifference(int nums[], int n)  { 
	    // Your code goes here
	      int sum=0;
    for(int i=0;i<n;i++)
    sum+=nums[i];
    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    int ans=INT_MAX;
    for(int i=0;i<=sum;i++)
    {
        if(f(n-1,i,nums,dp)==true)
        {
            int res=abs(i-(sum-i));
             ans=min(ans,res);
        }
    }
    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
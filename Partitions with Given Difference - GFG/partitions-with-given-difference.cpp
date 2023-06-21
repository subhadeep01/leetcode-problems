//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod =(int)1e9+7;
int f(int ind, int target, vector<int>&a, vector<vector<int>>&dp)
{
    
       if(ind == 0){
        if(target==0 && a[0]==0)
            return 2;
        if(target==0 || target == a[0])
            return 1;
        return 0;
    }
   if(dp[ind][target]!=-1)return dp[ind][target];
   int take=0;
   if(a[ind]<=target)
    take= f(ind-1, target-a[ind],a, dp);
   int not_take=f(ind-1, target,a,dp);
   return dp[ind][target]= (take + not_take)%mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    // s1+s2=sum
    //s1-s2=d
    int sum=0;
    for(auto x: arr) sum+=x;
    if((sum-d)<0) return 0; 
    if((sum-d)%2==1)return 0;
    sum=(sum-d)/2;
    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    return f(n-1,sum,arr,dp);
}
   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends
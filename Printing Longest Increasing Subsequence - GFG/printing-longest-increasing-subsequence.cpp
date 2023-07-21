//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        // Code here
        
        vector<int>dp(n+1,1),hash(n+1);
        int maxi=0;
        int pos;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    if(1+dp[j]>dp[i])
                    {
                        hash[i]=j;
                        dp[i]=1+dp[j];
                    }
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                pos=i;
            }
        }
        vector<int>ans;
        while(pos!=hash[pos])
        {
            ans.push_back(nums[pos]);
            pos=hash[pos];
        }
        ans.push_back(nums[pos]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
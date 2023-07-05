//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        // Code here
          int ans=0, flip_count=0;
        int s=0,e=0;
        while(e<n)
        {
            if(nums[e]==1)
                e++;
            else if(nums[e]==0 && flip_count<k)
            {
                flip_count++;
                e++;
            }
            else // flip_count>=k
            {
                while(flip_count>=k)
                {
                    if(nums[s]==0)
                    flip_count--;
                    s++;
                }
                
            }
            ans=max(ans,e-s);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends
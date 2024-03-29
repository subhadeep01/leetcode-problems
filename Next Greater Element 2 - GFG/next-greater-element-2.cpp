//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int N, vector<int>& nums) {
        // code here
         int n=nums.size();
        vector<int>nge(n);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums[i%n])
                st.pop();
            
            if(i<n){
            if(st.empty())
                nge[i%n]=-1;
            else
                nge[i%n]=st.top();
            }
            
            st.push(nums[i%n]);
        }
        return nge;
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
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
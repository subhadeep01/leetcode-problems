//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        // Your code goes here
        int x1=0,x2=0;
        for(int i=1;i<=n;i++)
        {
            x1^=(i);
        }
        for(int i=0;i<array.size();i++)
        {
             x2^=(array[i]);
        }
        return x1^x2;
    }
    //  1 2 3 4 5 6 7
    //  1 2 3 4 6 7
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends
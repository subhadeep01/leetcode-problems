//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findXOR(int l, int r) {
        // complete the function here
        int x1=0,x2=0;
        if((l-1)%4==0)x1=(l-1);
        if((l-1)%4==1)x1=1;
         if((l-1)%4==2)x1=(l);
        if((l-1)%4==3)x1=0;
         if((r)%4==0)x2=(r);
        if((r)%4==1)x2=1;
         if((r)%4==2)x2=(r+1);
        if((r)%4==3)x2=0;
        return x1^x2;
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends
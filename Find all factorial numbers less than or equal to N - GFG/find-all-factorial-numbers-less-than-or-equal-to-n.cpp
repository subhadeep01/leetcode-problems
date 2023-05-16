//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void f(vector<long long>&v, long long i, long long prev, long long n)
    {
        if(i*prev>n) return;
        v.push_back(i*prev);
        prev=(i*prev);
        f(v,i+1,prev,n);
        
    }
    vector<long long> factorialNumbers(long long n)
    {
        // Write Your Code here
        vector<long long>v;
        f(v,1ll,1ll,n);
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for(auto num : ans){
            cout<<num<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends
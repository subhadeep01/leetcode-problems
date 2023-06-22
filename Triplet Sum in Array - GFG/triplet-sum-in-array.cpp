//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int X)
    {
        //Your Code Here
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n; j++)
            {
                int target=X-(arr[i]+arr[j]);
                if(m.find(target)!=m.end() && m[target]!=i && m[target]!=j) return true;
                
            }
            m[arr[i]]=i;
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends
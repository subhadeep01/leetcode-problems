//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
         vector<int>hashmap(256,-1);
        int l=0,r=0;
        int n=s.size();
        int len=0;
        while(r<n)
        {
            if(hashmap[s[r]]!=-1)
                l=max(l,hashmap[s[r]]+1);
            hashmap[s[r]]=r;
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends
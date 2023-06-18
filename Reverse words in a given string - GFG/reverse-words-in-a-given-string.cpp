//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        string ans;
        int n=s.size();
        string temp;
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!='.')
            {
                f=1;
                temp+=s[i];
            }
            else
            {
                if(f==1)// there are some characters visited
                {
                ans='.'+temp+ans;
                temp="";
                f=0;
                }
            }
        }
        if(f==1)
        ans='.'+temp+ans;
        n=ans.size();
        if(ans[0]=='.')
            return ans.substr(1,n-1);
        else
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends
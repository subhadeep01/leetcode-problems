//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        //Moore Voote's Algorithm
        int c=0;
        int ele;
        for(int i=0;i<size;i++)
        {
            if(c==0)
            {
                c=1;
                ele=a[i];
            }
            else if(ele==a[i])c++;
            else
            c--;
        }
        int cnt=0;
        for(int i=0;i<size;i++)
        {
            if(ele==a[i])
            cnt++;
        }
        return (cnt>size/2)?ele:-1; 
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
        // code here

        int left=0;
        int right=n-1;
        int left_max=0,right_max=0;
        long long water=0;
        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                left_max=max(left_max,height[left]);
                water+=max(0,left_max-height[left]);
                left++;
            }
            else
            {                
                right_max=max(right_max,height[right]);
                water+=max(0,right_max-height[right]);
                right--;
            }
        }
        return water;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends
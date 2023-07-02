class Solution {
public:
    int ans=0;
    void f(int i, vector<vector<int>>& requests,vector<int>person,int request_accepted)
    {
          if(i==requests.size())
          {
              for(auto x: person)
              {
                  if(x!=0)return;
              }
              ans=max(ans,request_accepted);
              return;
          }
        
        
          if(requests[i][0]!=requests[i][1])// optimisation
          // if we dont take the current request
          f(i+1,requests,person,request_accepted);
          //if we take current request
        
          person[requests[i][0]]--;
          person[requests[i][1]]++;
          f(i+1,requests,person,request_accepted+1);
        
          //backtrack;
          person[requests[i][0]]++;
          person[requests[i][1]]--;
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>person(n,0);
        // assume person in every building to be full that is 0
        f(0,requests,person,0);
        return ans;
    }
};
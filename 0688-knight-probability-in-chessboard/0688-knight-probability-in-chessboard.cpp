class Solution {
public:
    bool isValid(int i, int j, int n)
    {
        return (i>=0 && j>=0 && i<n && j<n);
    }
    double knightProbability(int n, int k, int row, int col) {
     
        vector<vector<double>>curr(n,vector<double>(n,0));
        vector<vector<double>>next(n,vector<double>(n,0));
        curr[row][col]=1.0;
        vector<pair<int,int>>directions={{-2,-1},{-2,+1},{-1,-2},{-1,+2},{+1,-2},{+1,+2},{+2,-1},{+2,+1}};
       
        for(int moves=1;moves<=k;moves++)
        {
           for(int i=0;i<n;i++)
           {
               for(int j=0;j<n;j++)
               {
                   if(curr[i][j]!=0)
                   {
                       for(int dir=0;dir<8;dir++)
                       {
                           int x=i+directions[dir].first;
                           int y=j+directions[dir].second;
                           if(isValid(x,y,n))
                           {
                               next[x][y]+=curr[i][j]/8.0;
                           }
                       }
                   }
               }
           }
           curr=next;
           for(int i=0;i<n;i++)
           {
               for(int j=0;j<n;j++)
               {
                   next[i][j]=0;
               }
           }
        }
        double ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans+=curr[i][j];
            }
        }
        return ans;
    }
};
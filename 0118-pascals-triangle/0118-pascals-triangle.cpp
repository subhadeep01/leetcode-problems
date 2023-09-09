class Solution {
public:
     vector<vector<int>> generate(int n) {
        vector<vector<int>> v(n);
        v[0].push_back(1);
        if(n==1)
            return v;
        v[1].push_back(1);
         v[1].push_back(1);
        if(n==2)
            return v;
        
        for(int i=2;i<n;i++)
        {
            v[i].push_back(1);
            for(int j=1;j<i;j++)
            {
                v[i].push_back(v[i-1][j-1]+v[i-1][j]);
            }
            v[i].push_back(1);
        }
        return v;
    }
};
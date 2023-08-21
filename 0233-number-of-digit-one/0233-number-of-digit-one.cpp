class Solution {
public:
    int d=1;
    int dp[19][2][19];
    int f(int ind, int flag, int check, vector<int>&num)
    {
        if(ind==num.size())
        {
            return check;
        }
        
        if(dp[ind][flag][check]!=-1) return dp[ind][flag][check];
        
        int limit = num[ind];
        if(flag==1) limit=9;
        
        int count=0;
        for(int digit = 0; digit<=limit;digit++)
        {
            if(flag==1)
            {
                if(digit==d)
                    count+=f(ind+1,flag,check+1,num);
                else
                    count+=f(ind+1,flag,check+0,num);
            }
            else if(flag==0)
            {
                if(digit==d)
                {
                    if(digit<num[ind])
                    count+=f(ind+1,1,check+1,num);
                    else
                    count+=f(ind+1,0,check+1,num);
                }
                else
                {
                    if(digit<num[ind])
                    count+=f(ind+1,1,check+0,num);
                    else
                    count+=f(ind+1,0,check+0,num);
                }
            }
        }
        return dp[ind][flag][check]=count;
    }
    vector<int> convertIntoVector(int n)
    {
        vector<int>num;
        while(n)
        {
            num.push_back(n%10);
            n/=10;
        }
        reverse(num.begin(),num.end());
        return num;
    }
    int countDigitOne(int n) {
        vector<int>num = convertIntoVector(n);
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,num);
    }
};
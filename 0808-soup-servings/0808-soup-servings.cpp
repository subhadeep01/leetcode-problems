class Solution {
public:
    double dp[200][200];
    double f(int A, int B)
    {
        if(A<=0 && B<=0) return 0.5;
        
        if(A<=0) return 1;
        
        if(B<=0) return 0;
        
        if(dp[A][B]>0) return dp[A][B];
        
        return dp[A][B]=0.25*(f(A-4,B)+f(A-3,B-1)+f(A-2,B-2)+f(A-1,B-3));
    }
    double soupServings(int n) {
        if(n>4800) return 1.0000;
        
        n=(n+24)/25;
        
        return f(n,n);
        
    }
};
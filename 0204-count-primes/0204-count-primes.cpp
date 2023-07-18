class Solution {
public:
    int prime[5000005];
 
    void generatePrime(int n)
    {
        for(int i=0;i<=n;i++)
        {
            prime[i]=1;
        }
        prime[0]=prime[1]=0;
        for(int i=2;i<=sqrt(n);i++)
        {
            for(int j=2*i;j<=n;j+=i)
               prime[j]=0;
        }
    }
  
    int countPrimes(int n) {
         generatePrime(n);
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(prime[i])
                c++;
        }
        return c;
    }
};
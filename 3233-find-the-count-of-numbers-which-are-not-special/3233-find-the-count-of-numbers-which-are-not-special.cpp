class Solution {
public:
    vector<int>primes;
    void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
}
    int nonSpecialCount(int l, int r) {
        // 2 , 3, 5,7, 11,
        // prime^2
        SieveOfEratosthenes(100000);
        long long right=0,left=0,ans=0;
        for(auto x: primes)
        {
            if(x<=40000){
            long long a = x*x;
            if(a<=1e9  && a>=l && a<=r)
                ans++;
            }                
        }
        return (r-l+1-ans);
    }
};
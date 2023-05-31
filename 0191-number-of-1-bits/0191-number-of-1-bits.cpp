class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c=0;
        for(int k=0;k<32;k++)
        {
            if(n&(1<<k))
            c++;
        }
        return c;
    }
};
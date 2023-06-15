class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        for(int i=0;i<32;i++)
        {
            if(((1&(a>>i))|(1&(b>>i)))==(1&(c>>i)))
            {
                continue;
            }
            else if((1&(c>>i))==0)
            {
                if((1&(a>>i))==(1&(b>>i)))
                   cnt+=2;
                   else
                   cnt++;
            }
            else if((1&(c>>i))==1)
            {
                cnt++;
            }
        }
        return cnt;           
    }
};
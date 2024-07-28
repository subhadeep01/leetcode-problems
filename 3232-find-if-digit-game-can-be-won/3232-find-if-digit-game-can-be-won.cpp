class Solution {
public:
    int cod(int n)
    {
        int c=0;
        while(n)
        {
            c++;
            n/=10;
        }
        return c;
    }
    bool canAliceWin(vector<int>& nums) {
        int sing = 0,dob =0,hehe=0;
        for(auto x: nums)
        {
            if(cod(x)==1) sing+=x;
            else if(cod(x)==2) dob+=x;
            else hehe+=x;
        }
        return (sing>(dob+hehe) || dob>(sing+hehe));
    }
};
class Solution {
public:

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // --- ---- X--
        // X-- --X- ---
        // 1 2 4      8 16 32 64    128 256 512
        unordered_map<int,int>reserved; // {row,col}
        // basically it stores those rows and columns which is reserved
        
        for(auto it: reservedSeats)
        {
            int reserved_row=it[0]-1;
            int reserved_col=it[1]-1;
            reserved[reserved_row] |=(1<<reserved_col);
        }
        
        int ans=0;
        for(auto it : reserved)
        {
            int val=it.second;
            int c=0;
            if((val & 30)==0) c++;
            if((val & 480)==0) c++;
            if((val & 120)==0 && c==0) c=1;
            ans+=c;
        }
        ans+=(2*(n-reserved.size()));
        return ans;
        
    }
};
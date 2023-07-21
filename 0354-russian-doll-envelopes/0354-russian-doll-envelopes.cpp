class Solution {
public:
    int maxEnvelopes(vector<vector<int>>&envelopes) {
        int n=envelopes.size();
         sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });



        // we have to do it in O(nlogn) by binary search
        vector<int>temp;
        temp.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++)
        {
            if(envelopes[i][1]>temp.back())
            {
                temp.push_back(envelopes[i][1]);
            }
            else
            {
                int ind = lower_bound(temp.begin(),temp.end(),envelopes[i][1])-temp.begin();
                temp[ind]=envelopes[i][1];
            }
        }
        return temp.size();
    }
};
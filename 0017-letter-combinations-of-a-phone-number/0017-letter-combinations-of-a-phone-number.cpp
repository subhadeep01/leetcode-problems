class Solution {
public:
    set<string>ans;
    map<char,string>mp;
    void f(string &digits, int n, string &output)
    {
        if(n==digits.size())
        {
            ans.insert(output);
            return;
        }
        
        for(int i=0;i<mp[digits[n]].size();i++)
        {
            for(auto x: mp[digits[n]])
            {
                output.push_back(x);
                f(digits, n+1, output);
                output.pop_back();
            }
        }
        
    }
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
      mp['2'] = {'a', 'b', 'c'};
mp['3'] = {'d', 'e', 'f'};
mp['4'] = {'g', 'h', 'i'};
mp['5'] = {'j', 'k', 'l'};
mp['6'] = {'m', 'n', 'o'};
mp['7'] = {'p', 'q', 'r', 's'};
mp['8'] = {'t', 'u', 'v'};
mp['9'] = {'w', 'x', 'y', 'z'};

        string output="";
        vector<string>res;
        if(n==0) return res;
        f(digits, 0, output);
        
    while(ans.size())
    {
        res.push_back(*ans.begin());
        ans.erase(ans.find(*ans.begin()));
    }
        return res;
    }
};
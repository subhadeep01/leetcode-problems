class Solution {
public:
    set<string>ans;
    map<char,string>mp;
    void f(string digits, int n, string output)
    {
        if(digits.size()==0)
        {
            ans.insert(output);
            return;
        }
        
        for(int i=0;i<mp[digits[0]].size();i++)
        {
            for(auto x: mp[digits[0]])
            f(digits.substr(1), n, output+x);
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
        f(digits, n, output);
        
    while(ans.size())
    {
        res.push_back(*ans.begin());
        ans.erase(ans.find(*ans.begin()));
    }
        return res;
    }
};
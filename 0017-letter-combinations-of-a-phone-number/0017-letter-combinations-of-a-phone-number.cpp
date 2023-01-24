class Solution {
public:
    void f(int index, string &digits, string &temp, vector<string> &ans, unordered_map<char,string>&m)
    {
        if(index==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        
        string str=m[digits[index]];
        for(int i=0;i<str.size();i++)
        {
            temp.push_back(str[i]);
            f(index+1,digits,temp,ans,m);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        vector<string>ans;
        if(digits.size()==0) return ans;
        string temp;
        f(0,digits,temp,ans,m);
        return ans;
    }
};
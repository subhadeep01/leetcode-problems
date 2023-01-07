class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
          set<string>s;
        for(auto x: wordList)
        s.insert(x);
        queue<pair<string,int>>q;
        q.push({startWord,1});
        while(!q.empty())
        {
            string word=q.front().first;
            int length=q.front().second;
            q.pop();
            if(word==targetWord) return length;
            for(int i=0;i<word.size();i++)
            {
                string word1=word;
                for(int j=0;j<26;j++)
                {
                    word1[i]='a'+j;
                    if(s.find(word1)!=s.end())
                    {
                        q.push({word1,length+1});
                        s.erase(word1);
                    }
                }
            }
        }
        return 0;
    }
};
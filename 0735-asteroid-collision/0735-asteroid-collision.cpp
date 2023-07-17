class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        
        stack<int>st;
        for(auto x: asteroids)
        {
            if(x>0)
                st.push(x);
            if(x<0)
            {
                    if(st.size()>0 && st.top()>0 && abs(st.top())>abs(x))
                    {
                       
                    }
                    else if(st.size()>0 && st.top()>0 && abs(st.top())<abs(x))
                    {       
                        while(st.size()>0 && st.top()>0 && abs(st.top())<abs(x))
                        {
                            st.pop();
                        }
                       if(st.size()>0 && st.top()>0 && abs(st.top())==abs(x))
                            st.pop();
                        else if(st.size()>0 && st.top()>0 && abs(st.top())>abs(x))
                        {
                            
                        }
                        else
                            st.push(x);

                    }
                    else if(st.size()>0 && st.top()>0 && abs(st.top())==abs(x))
                    {
                        st.pop();
                    }
                else
                    st.push(x);
            }
        }
        vector<int>ans;
        while(st.size()>0)
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;        
    }
};
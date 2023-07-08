class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        // k=4;
        // [  ][      ][][  ]
        int n=weights.size();
        if(k>n)return -1;
        long long score = weights[0]+weights[n-1];
        long long minscore=score,maxscore=score;
        vector<int>starting_points;
        // i resembles starting points.
        // for better explanation refer to karan mashru video
        for(int i=1;i<n;i++)
        {
            starting_points.push_back(weights[i]+weights[i-1]);
        }
        sort(starting_points.begin(),starting_points.end());
        for(int i=0;i<k-1;i++)
        minscore+=starting_points[i];
        reverse(starting_points.begin(),starting_points.end());
        for(int i=0;i<k-1;i++)
        maxscore+=starting_points[i];
        return (maxscore-minscore);
    }
};
class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        if(a[1]<b[1]) return true;
        if(a[1]>b[1])return false;
        if(a[0]<b[0]) return true;
        return false;
    }
    int maxEvents(vector<vector<int>>& events) {
        int no_of_events=events.size();
        sort(events.begin(),events.end(),cmp); // sort them according to their end
        // if end is equal sort them according to their start time
        int ans=0;
        set<int>days;
        int lim=events.back()[1];
        for(int i=1;i<=lim;i++)
        days.insert(i);
        for(auto event: events)
        {
            int start=event[0];
            int end=event[1];
            auto nearest_day=days.lower_bound(start);
            if(nearest_day==days.end() || *nearest_day> end) // if day not in the set or nearest day is greater than end date then cant attend that event
                continue;
            else
            {
                ans++;
                days.erase(nearest_day);// remove that day from set since its already occupied
            }
        }
        
        return ans;
    }
};
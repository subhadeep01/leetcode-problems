class TimeMap {
public:
    map<string, map<int, string, greater<int>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
    mp[key][timestamp]=value;
    }
    
    string get(string targetKey, int targetTimestamp) {
    if(mp.count(targetKey)==0) return "";
    auto it=mp[targetKey].lower_bound(targetTimestamp);
    if(it==mp[targetKey].end()) return "";
    return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
class TimeMap {
    map<string , vector<pair<string,int>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
            mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";

        int n = mp[key].size();
        int r = n-1;
        int l = 0;

        while(l<=r){

            int m = l + (r-l)/2;

            if(mp[key][m].second == timestamp){
                return mp[key][m].first;
            }
            else if (mp[key][m].second> timestamp){
                r = m-1;
            }
            else{
                l = m+1;
            }


        }

        if(r<0) return "";

        return mp[key][r].first;




    }
};

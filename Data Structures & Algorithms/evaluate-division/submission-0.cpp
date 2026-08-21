class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> adj;


        for(int i = 0;i<equations.size();i++){
            string a = equations[i][0];
            string b = equations[i][1];

            adj[a].emplace_back(b, values[i]);
            adj[b].emplace_back(a, 1.0/values[i]);
        }


        vector<double> res;

        for(int i = 0;i<queries.size();i++){
            string  s = queries[i][0];
            string t = queries[i][1];

            set<string> vis;

            res.push_back(dfs(s,t,adj ,vis));

        }

        return res;


    }


    double dfs(string s, string t ,  map<string, vector<pair<string, double>>> &adj ,  set<string> vis ){

            if(!adj.count(s) || !adj.count(t) ){
                return -1.0;
            }

            if(s == t) return 1.0;

            vis.insert(s);

            for(auto & [n,w] : adj[s]){
                if(!vis.count(n)){
                    double r = dfs(n,t,adj,vis);
                    if(r != -1.0){
                        return w*r;
                    }
                }
            }
            return -1.0;
    }
};
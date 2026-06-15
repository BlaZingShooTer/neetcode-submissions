class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26); // adjacency for characters
        vector<int> indeg(26, 0);
        vector<bool> pre(26, false);
        
        

        int i = 0;
        int n = words.size();

        for (auto &w : words) {
            for (char c : w) pre[c-'a'] = true;
        }

        while(i<n-1){
            string w1 = words[i];
            string w2 = words[i+1];

            int l = min(w1.size(),w2.size());
            int j = 0;
            while(j<l){
                

                if(w1[j]!=w2[j]){
                    adj[w1[j]-'a'].push_back(w2[j]-'a');
                    indeg[w2[j]-'a']++;
                    break;
                }
                j++;
            }
            i++;

            if(j == l && w1.size() > w2.size()) return "";
        }

        queue<int> q;
        for(int i = 0;i<26;i++){
            if(indeg[i]==0 && pre[i]) q.push(i);
        }

        string res= "";

        while(!q.empty()){
            int u = q.front();
            q.pop();
            res.push_back('a' + u);
            for(auto p : adj[u]){
                
                indeg[p]--;

                if (indeg[p] == 0) {
                    q.push(p);
                }
            }
        }


         for(int i = 0; i < 26; i++) {
            if(pre[i] && res.find('a'+i) == string::npos) return "";
        }

        return res;
    }
};

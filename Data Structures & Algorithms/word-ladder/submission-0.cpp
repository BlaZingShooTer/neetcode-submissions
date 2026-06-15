class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string> st(wordList.begin(),wordList.end());

        if(!st.count(endWord)) return 0;

        queue<pair<string,int>> q;

        q.push({beginWord,1});

        if(st.count(beginWord)) st.erase(beginWord);

        while(!q.empty()){

            auto var = q.front();
            string w = var.first;
            int len = var.second;
            q.pop();


            if(w == endWord) return len;

            for(int i = 0;i<w.size();i++){
                char original = w[i];
                for(char ch = 'a';ch<='z';ch++){
                    w[i] = ch;

                    if(st.count(w)){
                        st.erase(w);
                        q.push({w,len +1 });
                    } 
                }
                w[i] = original;
            }
        }  
        return 0;
    }
};

class Solution {
public:

    string encode(vector<string>& strs) {
        
        string encoded;
        for (auto &s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {

        int n =s.size();

        vector<string> ans;

        int i = 0;
        while(i<s.size()){

            int j = i;
            while(s[j]!='#'){
                j++;
            }

            int len = stoi(s.substr(i,j-i));
            string w = s.substr(j+1,len);
            ans.push_back(w);

            i = j+1+len;

        }

        return ans;

    }
};

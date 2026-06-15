class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        vector<int> memo(s.size()+1, -1);

        return func(0, s, memo , words);
    }


    bool func(int i , string s , vector<int> &dp , unordered_set<string> &w){
        
        if(i == s.size()){
            return true;
        }

        if(dp[i]!= -1){
            return dp[i];
        }
        for(int end = i + 1 ; end<= s.size(); end++){
            if(w.find(s.substr(i, end - i))!=w.end() && func(end,s,dp,w)){
                dp[i] = 1;
                return true;
            }
        }



        return dp[i] = 0;
    }


    
};

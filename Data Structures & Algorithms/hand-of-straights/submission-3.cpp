class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0) return false;

        map<int,int> mp;

        for(auto h : hand){
            mp[h]++;
        }

        sort(hand.begin(),hand.end());

        for(int i = 0;i<hand.size();i++){

            if(mp[hand[i]] > 0 ){

                for(int j = hand[i];j< hand[i] + groupSize; j++ ){
                    if(mp[j] == 0) return false;

                    mp[j]--;
                }


            }


        }

        return true;


        

        
    }
};

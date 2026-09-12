class Solution {
public:


    bool isPali(int l , int r , string &s){

        while(l<=r){
           if( s[l]!= s[r] ) return false;
           l++;
           r--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        
        int l = 0;
        int r = s.size()-1;

        while(l<=r){


            if(tolower(s[l]) != tolower(s[r]))
            {
                return isPali(l+1,r,s) || isPali(l,r-1,s);
            }


            l++;
            r--;

        }

        return true;

    }
};
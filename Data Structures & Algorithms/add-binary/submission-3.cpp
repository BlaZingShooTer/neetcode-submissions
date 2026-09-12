class Solution {
public:
    string addBinary(string a, string b) {
        
        int l = a.size()-1;
        int r = b.size()-1;

        string ans = "";

        int carry = 0;

        while( l>=0 && r>=0){

            if((a[l] == '1' && b[r] == '0' ) || (a[l] == '0' && b[r] == '1'))
            {   
                if(carry){
                    ans+= "0";
                    carry = 1;
                    
                }
                else{
                    ans+= "1";
                }
                l--;
                r--;
                
            }

            else if((a[l] == '1' && b[r] == '1'))
            {   
                if(carry){
                    ans+= "1";
                    carry = 1;
                }
                else{
                    ans+= "0";
                    carry = 1;
                }
                
                l--;
                r--;
            }
           
            else if(a[l] == '0' && b[r] == '0')
            {
                if(carry)
                {
                    ans+= "1";
                    carry = 0;
                }
                else
                {
                    ans+= "0";
                }

                l--;
                r--;
            }
            
            
        }

        while(l>=0){

            if(a[l] == '0'){
                
                if(carry){
                    ans+= "1";
                    carry = 0;
                }
                else{
                    ans+= "0";
                }
                l--;
            }
            else{

                if(carry){
                    ans+= "0";
                    carry = 1;
                }
                else{
                    ans+= "1";
                }
                l--;
            }
        }

        while(r>=0){

            if(b[r] == '0'){
                
                if(carry){
                    ans+= "1";
                    carry = 0;
                }
                else{
                    ans+= "0";
                }
                r--;
            }
            else{

                if(carry){
                    ans+= "0";
                    carry = 1;
                }
                else{
                    ans+= "1";
                }
                r--;
            }
        }

        if(carry) ans+= "1";

        reverse(ans.begin(),ans.end());

        return ans;

            

    }
};
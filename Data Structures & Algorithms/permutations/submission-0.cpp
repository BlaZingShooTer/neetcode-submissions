class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        if(nums.empty()){
            return {{}};
        }
    

    vector<int> tmp = vector<int>(nums.begin() +1, nums.end());
    vector<vector<int>> perm = permute(tmp);
    vector<vector<int>> res;

    for(const auto &p : perm){
        for(int i =0;i<=p.size();i++){
            vector<int> pc = p;
            pc.insert(pc.begin()+i,nums[0]);
            res.push_back(pc);
        }
    }

    return res;

    }
    
};

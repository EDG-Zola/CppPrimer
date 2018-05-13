class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>::iterator num_end = unique(nums.begin(), nums.end());
        nums.erase(num_end, nums.end());
        for(int i=1, j=0; i<=len; ){
            if(nums[j] != i){
                result.push_back(i);
                ++i;
            }
            else{
                ++i;
                ++j;
            }
        }
        return result;
    }
};
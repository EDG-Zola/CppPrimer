class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        for(int i=0; i != len; ){
            if(nums[i] == val){
                nums.erase(nums.begin()+i);
                i=0;
                --len;
            }
            else ++i;
        }
        return nums.size();
    }
};
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        int start = 0, end = 0;
        vector<int> same = nums;
        sort(same.begin(),same.end());//从小到大排序
        //从头到尾进行比较，遇到不相等时，记录位置索引为start
        for(int i=0; i<len; ++i){
            if(nums[i] != same[i]){
                start = i;
                break;
            } 
        }
        //从尾到头进行比较，遇到不相等时，记录位置索引为end
        for(int i=len-1; i>0; --i){
            if(nums[i] != same[i]){
                end = i;
                break;
            } 
        }
        //nums == same时，返回0
        if(start == end)
            return 0;
        return end - start + 1;
    }
};

static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int len = nums.size();
        //排序过后，依次讨论前三个，后三个，以及后两个跟第一个，前两个跟最后一个。
        sort(nums.begin(),nums.end());//从小到大排序
        int maxmun = nums[len-1]*nums[len-2]*nums[len-3];//最大的三个数
        maxmun = max(maxmun,nums[0]*nums[1]*nums[2]);//与最小的三个数比较
        maxmun = max(maxmun,nums[0]*nums[len-1]*nums[len-2]);//再与一个最小的，两个最大的比较
        maxmun = max(maxmun,nums[0]*nums[1]*nums[len-1]);//再与两个最小的，一个最大的比较
        return maxmun;
    }
};
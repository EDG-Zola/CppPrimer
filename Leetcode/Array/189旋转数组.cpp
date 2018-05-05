// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int len = nums.size();
//         for(int i=0; i<k; ++i){
//             //在数组前面插入最后一个元素
//             nums.insert(nums.begin(), nums[len-1]);
//             //删除数组最后一个元素
//             nums.pop_back();
//         }
//     }
// };

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //考虑k比nums.size()大的情况
         k = k%nums.size();
        //使用泛型算法reverse,将元素反向重新排列,变成7654321
        reverse(nums.begin(), nums.end());
        //将前k个元素方向排序567 4321
        reverse(nums.begin(), nums.begin()+k);
        //将第k个元素到最后的元素进行反向排序，567 1234
        reverse(nums.begin()+k, nums.end());
    }
};
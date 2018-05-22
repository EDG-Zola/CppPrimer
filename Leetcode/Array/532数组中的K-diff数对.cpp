// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//         int len = nums.size();
//         //输出已经排序好的无重复的数组
//         sort(nums.begin(), nums.end());
//         static int count = 0;
//         // vector<int>::iterator unique_end = unique(nums.begin(), nums.end());
//         // nums.erase(unique_end, nums.end());
//         for(int i = 0; i<len; ++i){
//             for(int j = i+1; j<len; ++j){
//                 if(nums[j]==nums[i]){
//                     if(k==0){
//                         ++count;
//                         ++i;
//                     }
//                 }  
//                 else if(nums[j]-nums[i]>=k){
//                     ++count;
//                     ++i;
//                 }
                          
//             }
//         }
//         return count;
//     }
// };

/*我们可以建立每个数字和其出现次数之间的映射，
然后遍历哈希表中的数字，
如果k为0且该数字出现的次数大于1，则结果res自增1；
如果k不为0，且用当前数字加上k后得到的新数字也在数组中存在，则结果res自增1
*/
static auto x = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int result = 0;
        //建立数组中每个数字与其出现的次数之间的映射
        unordered_map<int, int> m;
        for(int num:nums) //对数组中的每个元素
            ++m[num];
        //对m中的每个元素
        for(auto a:m){
            if(k==0 && a.second>1) ++result;
            if(k>0 && m.count(a.first+k)) ++result;
        } 
        return result;
    }
};


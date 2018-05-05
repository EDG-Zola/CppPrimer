//方案一：使用multimap的count函数，计算元素出现的次数
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         int len = nums.size();
//         if(len<=1)
//             return false;
//         multimap<int, int> numCount;
//         for(int i=0; i<len; ++i){
//             numCount.insert(make_pair(nums[i],i));    
//         }
//         for(int i=0; i<len; ++i)
//             if(numCount.count(nums[i]) >= 2)
//                 return true;
//         return false;
//     }
// };

//方案二，先使用泛型算法sort从小到大排序，在判断是否有相邻的元素相等的情况
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len =nums.size();
        if(len < 2)
            return false;
        sort(nums.begin(), nums.end());
    
          for (int i = 1; i < len; i++) 
          {
            if (nums[i] == nums[i - 1]) return true;
            }
        return false;
    }
};
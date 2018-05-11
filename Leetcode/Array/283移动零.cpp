//保持非0元素的相对顺序啊，不是要非0元素从小到大排序
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int len= nums.size();
//         if(len<=0)
//             return;
//         //从小到大排序
//         sort(nums.begin(), nums.end());
//         //反向从大到小排序
//         reverse(nums.begin(), nums.end());
//         int i=0;
//         for(; i<len;){
//             if(nums[i]!=0)
//                 ++i;
//             else break;
//         }
//         reverse(nums.begin(), nums.begin()+i);
        
//     }
// };
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len=nums.size();
        if(len<=0)
            return;
        //当nums[i]==0时，末尾填入元素0，并删除nums[i],并再从num[0]开始判断，判断次数len-1
        for(int i=0; i<len; ){
            if(nums[i]==0){
                nums.push_back(0);
                nums.erase(nums.begin()+i);
                i=0;
                --len;
            }
            else ++i;
        }
    }
};
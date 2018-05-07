// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int len=nums.size();
//         if(len<=0)
//             return 0;
//         if(len==1)
//             return nums[0]+1;
//         sort(nums.begin(), nums.end());
//         for(int i=0; i<len; ++i){
//             if(nums[i]!=i)
//                 return i;
//         }
        
//     }
// };
//����Ŀ�о������⣬���������������
//��Ϊֻȱ��һ�����֣�ֻ��Ҫ��ԭ��1��n�ĺͼ�ȥ�����������֮�ͣ��͵õ�ȱʧ�����֡�
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s = nums.size();
        int sum = s*(s + 1) / 2;
        for (int i = 0; i < s; i++)
            sum -= nums[i];
        return sum;
    }
};
//���ַ�0Ԫ�ص����˳�򰡣�����Ҫ��0Ԫ�ش�С��������
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int len= nums.size();
//         if(len<=0)
//             return;
//         //��С��������
//         sort(nums.begin(), nums.end());
//         //����Ӵ�С����
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
        //��nums[i]==0ʱ��ĩβ����Ԫ��0����ɾ��nums[i],���ٴ�num[0]��ʼ�жϣ��жϴ���len-1
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
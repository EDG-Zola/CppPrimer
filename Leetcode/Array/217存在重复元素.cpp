//����һ��ʹ��multimap��count����������Ԫ�س��ֵĴ���
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

//����������ʹ�÷����㷨sort��С�����������ж��Ƿ������ڵ�Ԫ����ȵ����
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
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int len = nums.size();
//         for(int i=0; i<k; ++i){
//             //������ǰ��������һ��Ԫ��
//             nums.insert(nums.begin(), nums[len-1]);
//             //ɾ���������һ��Ԫ��
//             nums.pop_back();
//         }
//     }
// };

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //����k��nums.size()������
         k = k%nums.size();
        //ʹ�÷����㷨reverse,��Ԫ�ط�����������,���7654321
        reverse(nums.begin(), nums.end());
        //��ǰk��Ԫ�ط�������567 4321
        reverse(nums.begin(), nums.begin()+k);
        //����k��Ԫ�ص�����Ԫ�ؽ��з�������567 1234
        reverse(nums.begin()+k, nums.end());
    }
};
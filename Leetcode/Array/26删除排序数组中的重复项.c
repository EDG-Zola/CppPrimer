class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         //��ѭ���е��ú���nums.size()����̫�࣬�����Ż�
        int len = nums.size();
        if(len <= 1)
            return len;
       //��ѭ���е��ú���nums.size()����̫�࣬�����Ż�,
        //��for(int i = 0; i != nums.size()-1;)��5.71��ߵ�8.88%
        for(int i = 0; i != len-1;){
            if(nums[i] == nums[i+1]){
                nums.erase(nums.begin()+i);
                --len;
                //�����0��ʼ���ܻ�ܺ�ʱ��
                i=0;   
            }
            else ++i;
        }
        return nums.size();
    }
};
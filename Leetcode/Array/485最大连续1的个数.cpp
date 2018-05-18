class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size();
        int maxNum = 0, result = 0, onlyoneresult = 0;
        if(len<=0)
            return 0;
        if(len == 1 && nums[0] == 1)
            return 1;
        if(len == 1 && nums[0] == 0)
            return 0;
        for(int i=1; i<len; ++i){
            //����������1�����
            if((nums[i] == 1) && (nums[i] == nums[i-1])){
                ++maxNum;
                if(maxNum >= result)
                    result = maxNum + 1;
            }
            //������������1�����    
            else if (nums[i] == 1 || nums[i-1] == 1){
                maxNum = 0;
                onlyoneresult = 1;
            }     
        }
        //���û��������1���֣����ǳ�����1
        if(onlyoneresult>result)
            return 1;
        return result;
    }
};
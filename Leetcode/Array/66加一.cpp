class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        //�ж���λ�Ƿ�Ϊ����,����Ϊ������
        // if(digits[0] < 0 || len == 0)
        //     return false;
        digits[len-1] += 1;
        for(;len >= 0;--len){
            if(digits[len-1]>=10){
                digits[len-1] %= 10;
                //�ж��ǵ���λ�������ǣ�����ǰһλ��1
                if(len-2>=0){
                    
                    digits[len-2] += 1;
                    
                }
                //���ǣ��������λ1
                else
                    digits.insert(digits.begin(),1);
            }
        }
      
       
         
        return digits;
    }
};
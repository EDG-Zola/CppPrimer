class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        //判断首位是否为负数,或者为空数组
        // if(digits[0] < 0 || len == 0)
        //     return false;
        digits[len-1] += 1;
        for(;len >= 0;--len){
            if(digits[len-1]>=10){
                digits[len-1] %= 10;
                //判断是到首位，若不是，则在前一位加1
                if(len-2>=0){
                    
                    digits[len-2] += 1;
                    
                }
                //若是，则插入首位1
                else
                    digits.insert(digits.begin(),1);
            }
        }
      
       
         
        return digits;
    }
};
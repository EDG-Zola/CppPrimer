//方法1
static auto x = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        int sum = 0;
        int max ;
        for(int i = 0; i < len; ++i)
        {
            sum += nums[i];
            if(i < k)
            {          
                max = sum;//如果k大于i，则前i个数之和就为max，即第一组的k个数之和
            }
            else
            {
                sum -= nums[i - k];
                if(sum > max)//k小于i，则用前i个数之和减去多加的那部分之和，之后比较减去之后那部分与原来k个数之和那部分比较
                    max = sum;
            }
        }

        return max / (double)k;
    }
};

//方法二
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        if(len == 1)
            return nums[0]/k;
        int tempNum = k;
        double maxNum = 0, thisNum = 0;
        for(int j=0,tempNum=k;tempNum>0;--tempNum,++j){
            thisNum += nums[j];//从i开始，计算nums[i]到nums[i+k-1]的和
            maxNum = thisNum;
        }
        thisNum = 0;
        for(int i=0;i<=len-k;++i){
            for(int j=i,tempNum=k;tempNum>0;--tempNum,++j){
                thisNum += nums[j];//从i开始，计算nums[i]到nums[i+k-1]的和
            }
            if(maxNum <= thisNum)
                maxNum = thisNum;
            thisNum = 0;
        }
        return maxNum/k;
    }
};
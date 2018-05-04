class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int totalCount = len/2;
        // multimap<int, int> num_count;
        multiset<int> numCount(nums.begin(), nums.end());
        if(len<1)
            return 0;
        if(len == 1)
            return nums[0];
        // for(int i=0; i<len; ++i){
            //���nums[i]��num_count�в����ڣ�����½�һ��nums[i]����ֵΪ��Ӧ����nums�е��±�
            //multimap������mapʹ���±���в���Ԫ��
            //num_count[nums[i]] = i;
            // if(num_count.count(nums[i]) > totalCount)
            //     return nums[i];
            // num_count.insert(make_pair(nums[i],i));
            //}
            for(multiset<int>::const_iterator it=numCount.begin(); it!= numCount.end(); ++it){
                if(numCount.count(*it) > totalCount)
                    return *it;
            }
    }
};


//��Ժܳ������飬����ʱ�䳬�����Ƶ�����µĽ������
class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int majority = nums[0];
        int len = nums.size();
        int t = 1;
        for (int i = 1; i < len; ++i)
        {
            if (majority == nums[i])
            {
                ++t;
            }
            else
            {
                --t;
            }

            if (t == 0)
            {
                majority = nums[i];
                t = 1;
            }
        }
        return majority;
    }
};
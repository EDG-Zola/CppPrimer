class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m+n;
        int rightNum = 0;
        //�ж�nums2�Ƿ�Ϊ��
        if(n==0)
            return ;
        //��nums1Ϊ��ʱ����nums2ֱ�Ӹ�ֵ��nums1
        if(m==0){
            for(;rightNum<n;++rightNum)
                nums1.insert(nums1.begin()+rightNum,nums2[rightNum]);
        }
        
        rightNum = 0;
        for(int i=0; i<len; ++i){
            if( nums2[rightNum] < nums1[i] && rightNum <n){
                nums1.insert(nums1.begin()+i, nums2[rightNum++]);
                //nums1��Ԫ�ظ���������1
                ++m;
            }
            //��i����num1��ĩβ���
            if(i>=m)
                nums1.insert(nums1.begin()+i, nums2[rightNum++]);
        }
        //ɾ��nums1��������0
        nums1.erase(nums1.begin()+len, nums1.end());
    }
};
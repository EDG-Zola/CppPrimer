class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m+n;
        int rightNum = 0;
        //判断nums2是否为空
        if(n==0)
            return ;
        //当nums1为空时，将nums2直接赋值给nums1
        if(m==0){
            for(;rightNum<n;++rightNum)
                nums1.insert(nums1.begin()+rightNum,nums2[rightNum]);
        }
        
        rightNum = 0;
        for(int i=0; i<len; ++i){
            if( nums2[rightNum] < nums1[i] && rightNum <n){
                nums1.insert(nums1.begin()+i, nums2[rightNum++]);
                //nums1的元素个数增加了1
                ++m;
            }
            //当i超过num1的末尾标号
            if(i>=m)
                nums1.insert(nums1.begin()+i, nums2[rightNum++]);
        }
        //删除nums1后面多余的0
        nums1.erase(nums1.begin()+len, nums1.end());
    }
};
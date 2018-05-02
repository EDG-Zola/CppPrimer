class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //第0行和第1行全是1
        vector<int> result(rowIndex+1,1);
        if(rowIndex<2)
           return result;
        //从第2行开始
        for(int i=2;i<=rowIndex;i++){
            for(int j=i-1;j>0;j--){
                result[j]+=result[j-1];
            }
        }
        return result;
    }
};
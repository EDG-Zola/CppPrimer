class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int numRows = nums.size();//原矩阵行
        int numCols = nums[0].size();//原矩阵列
        if(numRows*numCols != r*c)
            return nums;
        vector<vector<int>> result(r, vector<int>(c));//构造输出矩阵
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++){
                int a = (i*c+j)/numCols;//对应原矩阵的行
                int b = (i*c+j)%numCols;//对应原矩阵的列
                result[i][j] = nums[a][b];
            }
        return result;
    }
};
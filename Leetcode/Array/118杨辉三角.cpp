class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > triangle;
        //输入为空
        if(numRows<=0)
            return triangle;
        //分配空间是个难题
        //没行先分配一个元素空间
        triangle.assign(numRows, vector<int>(1));
        for(int i=0; i<numRows; ++i){
            //每行的第一个元素为1
            triangle[i][0]=1;
            //若果是第一行，则不执行下面的for循环
            if(i==0) continue;
            for(int j=1;j<i; ++j)
                 triangle[i].push_back(triangle[i-1][j-1] + triangle[i-1][j]);
            //每行的最后一个元素为1
             triangle[i].push_back(1);
        }
        return triangle;
    }
};
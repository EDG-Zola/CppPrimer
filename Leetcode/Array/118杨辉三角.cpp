class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > triangle;
        //����Ϊ��
        if(numRows<=0)
            return triangle;
        //����ռ��Ǹ�����
        //û���ȷ���һ��Ԫ�ؿռ�
        triangle.assign(numRows, vector<int>(1));
        for(int i=0; i<numRows; ++i){
            //ÿ�еĵ�һ��Ԫ��Ϊ1
            triangle[i][0]=1;
            //�����ǵ�һ�У���ִ�������forѭ��
            if(i==0) continue;
            for(int j=1;j<i; ++j)
                 triangle[i].push_back(triangle[i-1][j-1] + triangle[i-1][j]);
            //ÿ�е����һ��Ԫ��Ϊ1
             triangle[i].push_back(1);
        }
        return triangle;
    }
};
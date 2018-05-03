class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        map<int, int> map_num;
        int len = numbers.size();
        for(int index = 0; index != len; ++index){
            if(map_num.count(numbers[index]) != 0){
                //exist
                result.push_back(map_num[numbers[index]]+1);
                result.push_back(index+1);
            }
            map_num[target - numbers[index]] = index;
        }
        return result;
    }
};
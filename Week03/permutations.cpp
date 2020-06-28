class Solution {
public:
    void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& output, int index, int len){
        //terminator
        if (index == len) {
            result.push_back(output);
            return;
        }
        //process
        for (int i = index; i < len; ++i) {
            swap(output[i], output[index]);
            //drill down
            backtrack(result, output, index + 1, len);
            //reverse
            swap(output[i], output[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<vector<int> > result;
        int n = nums.size();
        backtrack(result, nums, 0, n);
        return result;
    }
};
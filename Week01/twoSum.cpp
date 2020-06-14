class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    
        vector<int> tmpVector;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                int value = nums[i] + nums[j];
                if(target == value)
                {
                    tmpVector.push_back(i);
                    tmpVector.push_back(j);
                    return tmpVector;
                }
            }
        }
    }
};
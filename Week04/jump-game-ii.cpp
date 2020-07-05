class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int step = 0;
        int maxPosition = 0;
        int end = 0;
        for(int i = 0 ; i < n - 1; i++){
            if(maxPosition >= i){
                maxPosition = max( maxPosition  ,i + nums[i]);
                if( end == i ){
                    end = maxPosition;
                    step++;
                }
            }
        }
        return step;
    }
};

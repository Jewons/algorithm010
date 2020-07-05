// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int maxStep = 0;
//         for(int i = 0; i < nums.size(); i++){
//             if(i <= maxStep){
//                 maxStep = max(maxStep,nums[i] + i);
//                 if(maxStep >= nums.size() - 1)
//                     return true;
//             }
//         }
//         return false;
//     }
// };
class Solution {
public:
    bool canJump(vector<int>& nums) {

        int maxStep = 0;

        for(int i = 0; i < nums.size(); i++){
            if( maxStep < i )
                return false;
            maxStep = max(maxStep,nums[i] + i);
        }
        return true;
    }
};
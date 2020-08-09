class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n));
        //string result;
        int start = 0;
        int maxLen = 0;
        for(int len = 0; len < n;len++){
            for(int i = 0; i + len < n; i++){
                int j = i + len;
                if(len == 0)
                    dp[i][j] = 1;
                else if(len == 1)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                if(dp[i][j] && j - i + 1 > maxLen){
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }
        return s.substr(start,maxLen);
        
    }
};
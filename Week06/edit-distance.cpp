class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1,vector<int>(n + 1));

        //dp数组初始化
        for(int i = 0; i <= m; i++)
            dp[i][0] = i;
        for(int j = 0; j <= n; j++)
            dp[0][j] = j;
        
        //dp状态方程
        //1.双指针，如果两个字符相等则 dp[i][j] = dp[i - 1][j - 1]; 编辑距离不变
        //2.如果两个字符不等，则在插入，删除，替换中选一个编辑距离最小的
        // dp[i][j] = min(dp[i - 1][j] + 1,dp[i][j - 1] + 1,dp[i - 1][j - 1] + 1) 这里 + 1 是由于编辑距离至少为1
        for(int i = 1; i <= m; ++i){   //为什么从1 开始，因为边界已经初始化了，所以从1开始
            for(int j = 1; j <= n; ++j){
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else{
                    dp[i][j] = min(min(dp[i - 1][j] + 1,dp[i][j - 1] + 1),dp[i - 1][j - 1] + 1);   
                }
            }
        }
        return dp[m][n];
    }
};
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[n][n];//dp[i][j]代表从s[i]到s[j]的最大palin长度
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;//单个字符是回文
        for(int j = 1; j < n; j++){//j从1开始，防越界
            for(int i = j - 1; i >= 0; i--){
                if(s[i] == s[j]){//出现新的相等值，加入已有结果或者变为新结果
                    dp[i][j] = i + 1 <= j - 1 ? 2 + dp[i + 1][j - 1] : 2;//可以不连续 所以是2
                }else{//依靠之前的两种情况更新dp值
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

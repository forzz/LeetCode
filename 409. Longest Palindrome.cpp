class Solution {
//回文字符串若有奇数个元素，则该元素只能出现一次且在中间，全是偶数个元素，肯定能组成回文字符串
public:
int longestPalindrome(string s) {
        int sum=s.size();
        vector<int> hash(52);//用来存储频率
        for(char c:s)
         {
             if(c<='z'&&c>='a')
             hash[c-'a']++;
             else hash[(c-'A')+26]++;
         }
        int count=0;
        for(auto it:hash)
        {
            if(it%2)
            count++;//数量为奇数的元素的种数
        }
        return count>0?sum-count+1:sum;
    }
};

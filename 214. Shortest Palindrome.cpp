/*
   让在前面补一些字符使得给定的字符串变成回文，观察可以发现我们需要添加多少个字符与给定字符串的前缀
   子串回文的长度有关．也就是说去掉其前缀的回文子串，我们只需要补充剩下的子串的逆序就行了，
   举个栗子：aacecaaa，其前缀的最大回文子串是aacecaa，剩下了一个a，因此我们只需要在前面加上一个a的逆
   序a就行了．再例如abcd，其前缀的最大回文是a，因此剩下的子串就为bcd，所以需要在前面加上bcd的逆序，
   就变成了dcbabcd．所以这样问题就转化为求字符串的前缀最大回文长度．

   找s前面的最大回文前缀串s1。如果s1是回文串,s1’是s1的逆序串，那么s1 = s1’。如前面所说s = s1 + s2，
   那么s’(逆串) = s2’ + s1’,如果把s与s’串在一起，那么就变成了s1 + s2 + s2’ + s1’，并且此处s1=s1’，
   回想我们的jMP算法，next的求法不就是找一个字符串的前面一部分与后面一部分相等的部分么。
   所以可以使用jMP的算法找出拼接起来的串s1 + s2 + s2’ + s1’最前面与最后面相等的串，即找出s1。
   但是我们需要在s与s’中间加一个分开符”#”，用来将避免出现求的s1超过s的长度。比如s=”aaa”,那么s’=”aaa”，
   这个时候算出的s1会变成”aaaaaa”,加上”#”后算”aaa#aaa”得到的s1就只会是”aaa”了。 
   */
class Solution {
    public:
        string shortestPalindrome(string s) {
            if(s.empty())return s;
            string s_reverse = s;
            reverse(s_reverse.begin(), s_reverse.end());//翻转
            string temp = s + "#" + s_reverse;//新串
            vector<int> next(temp.size() + 1, 0);
            //求next
            next[0] = -1;
            int j = -1;
            int i = 0;
            while (i < next.size()-1) {
                while (j >= 0 && temp[j] != temp[i]) j = next[j];
                ++i;
                ++j;
                next[i] = j;
            }
            return s_reverse.substr(0, s_reverse.size() - next[temp.size()]) + s;
        }
};

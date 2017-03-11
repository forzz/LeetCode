class Solution {
public:
    int lengthOfLongestSubstring(string s) { //题意为求不包含重复字符的最长子串(不能断开)
        // left用以记录合法的最远左边界位置，last记录字符上一次出现的位置（双指针滑动窗口）
        int ans = 0, left = 0, len = s.length();
        int last[255];
        memset(last, -1, sizeof last);
        for (int i = 0; i < len; i++) {//一次扫描字符串s
            if (last[s[i]] >= left)
    //上次出现位置在当前记录边界之后，即该子串中出现了重复字符，需调整left使得子串合法
                left = last[s[i]] + 1;
            last[s[i]] = i;
            ans = max(ans, i - left + 1);//长度
        }
        return ans;
    }
};
//简单方法
int lengthOfLongestSubstring(string s) {
        vector<int> map(128,0);
        int counter=0, begin=0, end=0, d=0; 
        while(end<s.size()){
            if(map[s[end++]]++>0) counter++; //如果map之前大于0，该元素在窗口中存在，需要右移左端
            while(counter>0) if(map[s[begin++]]-->1) counter--;//右移左端（因为上一行，不管发生什么，map都会+1，所以此时map的值为2）
            d=max(d, end-begin); //while valid, update d
        }
        return d;
    }

class Solution {
public:
    void getNext(int *next, string &needle) {
        int i = 0, j = -1;
        next[i] = j;
        while (i < needle.length() - 1) {
            while (j != -1 && needle[i] != needle[j]) j = next[j];
            ++i; ++j;
            //特殊情况，这里即为优化之处。考虑下AAAAB, 防止4个A形成0123在匹配时多次迭代。
            if (needle[i] == needle[j]) next[i] = next[j]; 
            else next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if (haystack.empty()) return needle.empty() ? 0 : -1;
        if (needle.empty()) return 0;
        int next[needle.length() + 1];//长度要比字符串大1
        getNext(next, needle);//求得needle的next值
        int i = 0, j = 0;
        while (i != haystack.length()) {//kmp匹配（i代表模板串，j代表匹配串）
            while (j != -1 && haystack[i] != needle[j]) j = next[j];
            ++i; ++j;
            if (j == needle.length()) return i - j;//i是当前母串的位置，j现在是匹配串的长度
        }
        return -1;
    }
};
//暴力方法
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i, j;
        for (i = j = 0; i < haystack.size() && j < needle.size();) {
            if (haystack[i] == needle[j]) {
                ++i; ++j;
            } else {
                i -= j - 1; j = 0;
            }
        }
        return j != needle.size() ? -1 : i - j;
    }
};

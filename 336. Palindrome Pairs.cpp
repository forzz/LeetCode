class Solution {
    public:
        bool isPalin(string& str)
        {
            int i = 0;
            int j = str.size() - 1; 
            while(i < j) 
                if(str[i++] != str[j--]) return false;
            return true;
        }
        vector<vector<int>> palindromePairs(vector<string>& words) {
            //回文数就是从某一位置切割，逆序化的字符串和原字符串的前后两部分相等
            unordered_map<string, int> hash;
            vector<vector<int>> result;
            for(int i =0; i< words.size(); i++) hash[words[i]] = i;//将word存入map中
            for(int i =0; i< words.size(); i++)//枚举单词i
            {
                reverse(words[i].begin(), words[i].end());//单词逆序化
                int len = words[i].size();//记录单词长度
                for(int j = 0; j<= len; j++)//枚举切割点（从0开始，包含空串）
                {
                    string left =words[i].substr(0, j), right = words[i].substr(j);
                    if(hash.count(left) &&isPalin(right) &&hash[left]!=i )//要防止与其本身进行匹配
                        //将单词的前一部分如果可以在hash表中找到匹配说明这部分是可以通过添加该单词来回文的, 如果这个单词剩下的部分本身是回文, 
                        //那么这两个单词就可以配成回文. 
                        //例如aabbcc和bbaa, 其中bbaa在hash表中是以逆序存在的, 即aabb, 那么当我们遍历到aabbcc的时候其前半部分aabb
                        //可以在hash表中查到, 并且剩余部分cc是回文, 因此他们可以构成回文
                        result.push_back(vector<int>{hash[left], i});
                    if(hash.count(right) &&isPalin(left) &&hash[right]!=i &&j>0)
                        //如果单词的后一部分可以在hash表中查到, 并且其前一部分是回文, 他们也可以构成匹配. 例如aabb和ccbbaa, 
                        //其中aabb在hash表中是以bbaa存在的. 当我们遍历到ccbbaa的时候, 其后一部分bbaa可以在hash表中查到存在, 并且
                        //其前一部分cc是回文, 因此他们也可以构成回文.
                        result.push_back(vector<int>{i, hash[right]});
                }
            }
            return result;
        }
};
/*
 * //当存在空串时, 就会复杂一些, 比如["a", ""], 这种情况应该输出[[0, 1] [1, 0]]. 因此空串也应该在作为其前缀和后缀进行检测. 
 切割前缀后缀包括空串需要考虑一个特殊情况：
 例如aabb和bbaa, 当我们将单词划分为左右两部分并且其前半部分为空串或后半部分为空串时都会匹配, 也就是遍历到aabb时会产出两个匹配,即
 aabb作为前缀, 空串作为后缀 (最后) 
 空串作为前缀, aabb作为后缀（最初） 
 而遍历到单词bbaa时又会重复匹配一次, 因此我们需要引入另外一个条件, 即
 在分别判断将当前单词的前一部分作为前缀和后一部分作为后缀的时候, 其前缀和后缀不能同时等于单词本身.
 删除一种比较情况：
 后缀是原字符串，前面为空时不把结果放入


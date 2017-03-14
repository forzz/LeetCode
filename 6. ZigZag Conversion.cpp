class Solution {
    public:
        string convert(string s, int nRows){
            if(nRows == 1) return s;
            string res[nRows];//多维数组构建图
            int i = 0, j, gap = nRows-2;
            while(i < s.size()){
                for(j = 0; i < s.size() && j < nRows; ++j) res[j] += s[i++];//向下循环
                for(j = gap; i < s.size() && j > 0; --j) res[j] += s[i++];//斜角线循环:nRows-2(减去首尾两个端点)
            }
            string str = "";
            for(i = 0; i < nRows; ++i)//将图按序输出
                str += res[i];
            return str;
        }
};

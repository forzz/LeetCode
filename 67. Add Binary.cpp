class Solution
{
public:
    string addBinary(string a, string b)
    {
        string s = "";
        int c = 0, i = a.size() - 1, j = b.size() - 1;//逆序按位扫描
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;//读出当前位
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;//c暂存结果
            c /= 2;//c转化为进位
        }
        return s;
    }
};

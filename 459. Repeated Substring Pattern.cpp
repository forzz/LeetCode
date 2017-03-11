class Solution {
public:
bool repeatedSubstringPattern(string str)
{
    int len = str.length();
    int next[len+1];
    next[0] = -1;
    int j = 0, k = -1;
    while( j!=len )
//要一直求到next[len]而不是next[len-1]，是因为next[len-1]只是表示前len-1个字母的内部对称性，而没有考虑到最后一个字母即str[len-1]
    {
        while( k!=-1 && str[j]!=str[k] )k = next[k];
            next[++j] = ++k;
    }
    return next[len]&&next[len]%(len-next[len])==0;
//设str长度为len，重复的子串长度为k，则如果真的由连续多个长度为k的子串重复构成str，那么在对str求next时，
//由于连续对称性，会从next[k+1]开始，1,2,3...地递增，直到next[len]=len-k，且(len-k)%k==0，表示有整数个k
}};


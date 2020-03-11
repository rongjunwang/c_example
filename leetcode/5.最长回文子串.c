/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

// @lc code=start

//中心扩展算法
char * longestPalindrome(char * s){
    if(strlen(s) == 0) return s;
    int start = 0;
    int end = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        int len1 = centerExpand(i, i, s);
        int len2 = centerExpand(i, i+1, s);
        int len = len1 > len2 ? len1 : len2;
        
        if(len > end - start){
            start = i - (len-1)/2;
            end = i + len/2;
        }
    }

    int length = end - start + 1;
    printf("%d-%d-%s\n", length,start,s);
    s[start + length] = '\0';      
    return s + start;
}

int centerExpand(int left,int right,char* s){
    while(left >= 0 && right < strlen(s) && s[left] == s[right]){
        left--;
        right++;
    }
    return right - left - 1;
}



// @lc code=end


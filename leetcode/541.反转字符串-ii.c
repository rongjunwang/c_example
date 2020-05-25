/*
 * @lc app=leetcode.cn id=541 lang=c
 *
 * [541] 反转字符串 II
 */

// @lc code=start


char * reverseStr(char * s, int k){
    int len = strlen(s);
    int i=0, left=0, right=len-1;
    char *temp = NULL;
    while(i < len){
        left = i;
        right = i + k > len ? len - 1 : i + k - 1;
        while(left < right){
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }

        i += 2*k;
    }
    return s;
}


// @lc code=end


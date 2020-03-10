/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start


int lengthOfLongestSubstring(char * s){
    int size = strlen(s);
    int left = 0;
    int result = 0;
    int table[128] = {0};

    for(int i=0; i<size ;i++){
        int index = (int)s[i];

        if(table[index] != 0){
            left = (table[index] > left) ? table[index] : left;
        }

        result = (result >= i - left + 1) ? result : (i - left + 1);
        table[index] = i+1;
    }
    return result;
}


// @lc code=end


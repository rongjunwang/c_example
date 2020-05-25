/*
 * @lc app=leetcode.cn id=557 lang=c
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start


char * reverseWords(char * s){
    int len = strlen(s);
    int i=0,left=0;
    while(i<len){
        if(s[i] == ' '){
            reverseString(s,left,i-1);
            left = i+1;
        }
        i++;

        //最后一个单词
        if(i == len){
            reverseString(s, left, len-1);
        }
    }
    return s;
}

void reverseString(char *s,int start,int end){
    char *temp = NULL;
    while(start < end){
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        end--;
        start++;
    }
}


// @lc code=end


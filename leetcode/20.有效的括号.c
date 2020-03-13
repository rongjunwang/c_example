/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <stdbool.h>

bool isValid(char * s){
    if(!s || s[0] == "") return 1;
    char* stk = (char*)malloc(strlen(s));
    int temp = -1;
    for(int i=0; s[i] != '\0'; i++){
        switch (s[i])
        {
            case '(':
            case '[':
            case '{':
                stk[++temp] = s[i];
                break;
            case ')':
                if(temp < 0 || stk[temp--] != '(')
                    return 0;
                break;
            case ']':
                if(temp < 0 || stk[temp--] != '[')
                    return 0;
                break;
            case '}':
                if(temp < 0 || stk[temp--] != '{')
                    return 0;
                break;
        }
    }

    if(temp >= 0) return 0;
    return 1;
}


// @lc code=end


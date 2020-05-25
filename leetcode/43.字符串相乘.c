/*
 * @lc app=leetcode.cn id=43 lang=c
 *
 * [43] 字符串相乘
 */

// @lc code=start

//竖式乘法
char * multiply(char * num1, char * num2){
    if(num1[0] == '0') return num1;
    if(num2[0] == '0') return num2;

    int len1 = strlen(num1);
    int len2 = strlen(num2);

    int *temp = malloc(sizeof(int) * (len1 + len2));
    memset(temp,0,sizeof(int) * (len1 + len2));
    int sum,i,j;
    char *res = (char *)calloc((len1 + len2 + 2), sizeof(char));

    //竖式计算
    for(i=len1-1; i>=0; i--){
        for(j=len2-1; j>=0; j--){
            sum = (num1[i] - '0') * (num2[j] - '0');
            sum += temp[i+j+1];

            temp[i+j] += sum/10;
            temp[i+j+1] = sum%10;
        }
    }

    
    for (i = 0,j = 0; i < len1+len2; i++)
    {
        //去除开头的0
        if( j==0 && temp[i] == 0) continue;
        res[j++] = temp[i] + '0';
    }
    return res;
}


// @lc code=end


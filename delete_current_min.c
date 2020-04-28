#include <stdio.h>
#include <string.h>

/* 实现删除字符串中出现次数最少的字符，字符串只包含小写英文字母 */
/* eg: abcdd -> dd */
int main (void)
{
    char alpha[26] = {0};
    char result[26] = {0};
    char input[21] = {0};
    int input_len = 0;
    char *p = NULL;
    int i = 0;
    int min_cnt = 20;
    int rst_cnt = 0;
    while (fgets (input, 21, stdin) != NULL)
    {
        rst_cnt = 0;
        memset (alpha, 0, 26);
        memset (result, 0, 26);
        input_len = strlen (input);
        input[strlen(input)-1] = '\0';
		
        p = input;
        while (*p != '\0')
        {
            alpha[*p - 'a']++;
            p++;
        }
        for (i = 0; i < 26; ++i)
        {
            if (alpha[i] != 0 && alpha[i] < min_cnt)
                min_cnt = alpha[i];
        }
        p = input;
        while (*p != '\0')
        {
            if (alpha[*p - 'a'] != min_cnt)
                result[rst_cnt++] = *p;
            p++;
        }
        printf ("%s\n", result);
        memset (input, 0, 21);
    }
}

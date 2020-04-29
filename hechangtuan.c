#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* N个同学站一排，请其中N-K位同学出列，使得剩下的K位同学排成合唱团队形 */
/* 合唱队形是指这样的一种队形：设K位同学从左到右依次编号1,2,3...K，他们的
身高分别为T1,T2...TK, 则他们的身高满足存在i 使得T1<T2<...<Ti-1 < Ti > Ti+1 >...>TK */
/* 你的任务是，已知所有N位同学的身高，计算至少需要几位同学出列，可以使得剩下的同学拍成合唱队形 */
int get_min_delete (int *p_arr, int num)
{
	int *more_than = (int*)malloc (sizeof(int) * num);
	if (NULL == more_than)
		return -1;
	memset (more_than, 0, sizeof (int) * num);
	int i,j,min;
	int more_num = 0;
	for (i = 0; i < num; ++i)
	{
		more_num = 0;
		for (j = 0; j < num; ++j)
		{
			if (p_arr[j] > p_arr[i])
				++more_num;
		}
		more_than[i] = more_num;
	}
	min = more_than[0];
	for (i = 0; i < num; ++i)
	{
		if (more_than[i] < min)
			min = more_than[i];
	}
	return min;
}

int main (void)
{
    int num;
    int i;
    scanf ("%d", &num);
    int *p_arr = (int*)malloc (sizeof(int) * num);
    if (NULL == p_arr)
        return -1;
    memset (p_arr, 0, sizeof(int)*num);
    for (i = 0; i < num; ++i)
    {
        scanf ("%d", &p_arr[i]);
    }
	printf ("%d", get_min_delete (p_arr, num));
	free (p_arr);
	return 0;
    
}

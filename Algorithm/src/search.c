/*
 * search.c
 *
 *  Created on: 2017/06/13
 *      Author: kento
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE RAND_MAX
#define HIT 0xFFFFU
#define TRUE 1U
#define FALSE 0U


unsigned int list[SIZE];

unsigned char judge(unsigned int pos);
void initList();

/*
 * 逐次探索法
 *
 */
void sequentialSearch()
{
	unsigned int i;
	unsigned char result;

	initList();

	for( i = 0; i < SIZE; i++ )
	{
		result = judge(i);

		if(result == TRUE) {
			break;
		}
	}

	printf("比較回数 : %d", i);
}

void initList()
{
	int i;
	int pos = 0;

	for( i = 0; i < SIZE; i++ )
	{
		list[i] = 0;
	}

	/* 乱数の初期化 */
	srand(time(NULL));

	pos = rand();

	printf("SIZE : " + SIZE);
	printf("rand() : " + pos);

	/* 乱数番目に当たりを設定 */
	list[pos] = HIT;
}

unsigned char judge(unsigned int pos)
{
	unsigned char result = FALSE;

	if( list[pos] == HIT)
	{ /* ヒットした場合 */
		result = TRUE;
	}

	return result;
}

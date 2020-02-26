#include <stdio.h>
#include <stdlib.h>
#include <ctime>
struct array
{
	int * pBase;
	int len;
	int cnt;
};
void init_arr(struct array* arr, int len);//初始化
void push_back(struct array* arr, int num);//尾插
void show_arr(struct array* arr);//显示
void insert_arr(struct array* arr, int pos, int num);//插入，pos从0开始
void delete_arr(struct array* arr, int pos, int* num);//删除，pos从0开始
int get(struct array* arr, int pos);//pos从0开始
void clean(struct array* arr);//清空
void sort_arr(struct array* arr);//从大到小
void inversion_arr(struct array* arr);//反转
bool is_full(struct array* arr);//是否满
bool is_empty(struct array* arr);//是否空
int main()
{
	int i;
	struct array arr;
	srand((unsigned int)time(NULL));
	init_arr(&arr, 3);
	for (i = 0; i < 5; i++)
	{
		push_back(&arr, rand()%10);
	}
	show_arr(&arr);
	printf("-------------\r\n");
	insert_arr(&arr,0,100);
	show_arr(&arr);
	printf("-------------\r\n");
	inversion_arr(&arr);
	show_arr(&arr);
	printf("-------------\r\n");
	return 0;
}

void init_arr(struct array * arr , int len)
{
	arr->pBase = (int *)malloc(sizeof(int) * len);
	if (arr->pBase == NULL)
	{
		printf("分配内存失败");
		exit(-1);//程序终止
	}
	else
	{
		arr->len = len;
		arr->cnt = 0;
	}
	return;
}
void push_back(struct array* arr, int num)
{
	int i;
	if (arr->cnt == arr->len)//数组满了
	{
		int a=(arr->len) + 1;
		int* parr = (int*)malloc(sizeof(int) * a);
		if (parr == NULL)
		{
			printf("parr内存分配失败");
			exit(-1);
		}
		for (i = 0; i < arr->cnt; i++)
		{
			*(parr + i) = *((arr->pBase) + i);
		}
		*(parr + (arr->cnt) ) = num;
		arr->cnt++;
		arr->len++;
		free(arr->pBase);
		arr->pBase = parr;
	}
	else
	{
		*((arr->pBase) + (arr->cnt)) = num;
		arr->cnt++;
	}	
}
void insert_arr(struct array* arr, int pos, int num)
{
	int i;
	if (arr->cnt == arr->len)//数组满了
	{
		int a = (arr->len) + 1;
		int* parr = (int*)malloc(sizeof(int) * ((int)(arr->len) + 1));
		if (parr == NULL)
		{
			printf("parr内存分配失败");
			exit(-1);
		}
		for (i = 0; i < pos; i++)
		{
			*(parr + i) = *((arr->pBase) + i);
		}
		*(parr + pos) = num;
		for (i = pos; i < arr->cnt; i++)
		{
			*(parr + i + 1) = *((arr->pBase) + i);
		}
		arr->cnt++;
		arr->len++;
		free(arr->pBase);
		arr->pBase = parr;
	}
	else
	{
		for (i = arr->cnt; i >pos; i--)//pos以后的数往后移一格，可以反过来赋值
		{
			*((arr->pBase) + (arr->cnt)) = *((arr->pBase) + (arr->cnt)-1);
		}
		*((arr->pBase) + pos) = num;
		arr->cnt++;
	}
}
void delete_arr(struct array* arr, int pos, int * num)
{
	int i;
	*num = *(arr->pBase + pos);
	if (pos != arr->cnt)
	{
		for (i = pos; i < arr->cnt; i++)
		{
			*(arr->pBase + pos) =*( arr->pBase + pos + 1);
		}
		arr->cnt--;
	}
	else
	{
		arr->cnt--;
	}
}
void clean(struct array* arr)
{
	arr->cnt = 0;
}
int get(struct array* arr,int pos)
{
	return *((arr->pBase) + pos);
}
bool is_full(struct array* arr)
{
	if (arr->cnt == arr->len)
	{
		return 1;
	}
	else
		return 0;
}
bool is_empty(struct array* arr)
{
	if (arr->cnt == 0)
	{
		return 1;
	}
	else
		return 0;
}
void show_arr(struct array* arr)
{
	int i;
	for (i = 0; i < arr->cnt; i++)
	{
		printf("%d ",*((arr->pBase)+i));
	}
	printf("	长度：%d		个数：%d\r\n",arr->len,arr->cnt);
}
void sort_arr(struct array* arr)//从大到小
{
	int i,j,index,max= *(arr->pBase);
	for (i = 0; i < arr->cnt - 1; i++)
	{
		max = *(arr->pBase + i);
		for (j = i + 1; j < arr->cnt; j++)
		{
			if (max < *(arr->pBase + j))
			{
				max = *(arr->pBase + j);
				index = j;
			}
		}
		if (*(arr->pBase + i) != max)
		{
			*(arr->pBase + index) = *(arr->pBase + i);
			*(arr->pBase + i)=max;
		}
	}
}
void inversion_arr(struct array* arr)
{
	int* temp = (int*)malloc(sizeof(int) * arr->cnt);
	if (temp == NULL)
	{
		printf("内存分配错误");
		exit(-1);
	}
	else
	{
		for (int i = 0; i < arr->cnt; i++)
		{
			temp [(int)(arr->cnt)-1- i]=arr->pBase[i];
		}
		free(arr->pBase);
		arr->pBase = temp;
	}
}
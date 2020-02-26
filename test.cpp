#include <stdio.h>
#include <stdlib.h>
#include <ctime>
struct array
{
	int * pBase;
	int len;
	int cnt;
};
void init_arr(struct array* arr, int len);//��ʼ��
void push_back(struct array* arr, int num);//β��
void show_arr(struct array* arr);//��ʾ
void insert_arr(struct array* arr, int pos, int num);//���룬pos��0��ʼ
void delete_arr(struct array* arr, int pos, int* num);//ɾ����pos��0��ʼ
int get(struct array* arr, int pos);//pos��0��ʼ
void clean(struct array* arr);//���
void sort_arr(struct array* arr);//�Ӵ�С
void inversion_arr(struct array* arr);//��ת
bool is_full(struct array* arr);//�Ƿ���
bool is_empty(struct array* arr);//�Ƿ��
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
		printf("�����ڴ�ʧ��");
		exit(-1);//������ֹ
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
	if (arr->cnt == arr->len)//��������
	{
		int a=(arr->len) + 1;
		int* parr = (int*)malloc(sizeof(int) * a);
		if (parr == NULL)
		{
			printf("parr�ڴ����ʧ��");
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
	if (arr->cnt == arr->len)//��������
	{
		int a = (arr->len) + 1;
		int* parr = (int*)malloc(sizeof(int) * ((int)(arr->len) + 1));
		if (parr == NULL)
		{
			printf("parr�ڴ����ʧ��");
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
		for (i = arr->cnt; i >pos; i--)//pos�Ժ����������һ�񣬿��Է�������ֵ
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
	printf("	���ȣ�%d		������%d\r\n",arr->len,arr->cnt);
}
void sort_arr(struct array* arr)//�Ӵ�С
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
		printf("�ڴ�������");
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
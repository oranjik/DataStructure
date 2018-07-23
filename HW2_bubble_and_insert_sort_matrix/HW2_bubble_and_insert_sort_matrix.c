#include<stdio.h>
#include<stdlib.h>
#define max 10

FILE *ofp;

typedef struct vec
{
	int x;
} vec;

void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void insert(vec *a)
{
	for (int i = 0; i < max; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (a[j].x < a[j - 1].x) swap(&a[j].x, &a[j - 1].x);
		}
	}
}
void insertr(vec *a)
{
	for (int i = 0; i < max; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (a[j*max].x <a[(j - 1)*max].x) swap(&a[j*max].x, &a[(j - 1)*max].x);
		}
	}
}

void bubble(vec *a)
{
	for (int i = max - 1; i >0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			if (a[j].x < a[j - 1].x) swap(&a[j].x, &a[j - 1].x);
		}
	}
}

void bubbler(vec *a)
{
	for (int i = max - 1; i >0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			if (a[j*max].x < a[(j - 1)*max].x) swap(&a[j*max].x, &a[(j - 1)*max].x);
		}
	}
}

void arr_print(vec *a)
{
	for (int i = 0; i < max; i++)
	{
		fprintf(ofp, "%5d", a[i].x);
	}
	fprintf(ofp, "\n");
}

int main()
{
	vec arr_insert[max][max];
	vec arr_bubble[max][max];

	ofp = fopen("data.txt", "w+");

	int i, j;
	fprintf(ofp, "=== insert 정렬 전 ===\n");
	for (i = 0; i < max; i++)
	{
		for (j = 0; j < max; j++)
		{
			arr_insert[i][j].x = (int)((double)rand() / RAND_MAX * 100);
			fprintf(ofp, "%5d", arr_insert[i][j].x);
		}
		fprintf(ofp, "\n");
	}

	fprintf(ofp, "=== insert 가로 정렬 후 ===\n");
	for (i = 0; i < max; i++)
	{
		insert(arr_insert[i]);
	}
	for (i = 0; i < max; i++)
	{
		arr_print(arr_insert[i]);
	}

	fprintf(ofp, "=== insert 세로 정렬 후 ===\n");
	for (i = 0; i < max; i++)
	{
		insertr(&arr_insert[0][i]);
	}

	for (i = 0; i < max; i++)
	{
		arr_print(arr_insert[i]);
	}

	fprintf(ofp, "\n\n");

	fprintf(ofp, "=== bubble 정렬 전 ===\n");
	for (i = 0; i < max; i++)
	{
		for (j = 0; j < max; j++)
		{
			arr_bubble[i][j].x = (int)((double)rand() / RAND_MAX * 100);
			fprintf(ofp, "%5d", arr_bubble[i][j].x);
		}
		fprintf(ofp, "\n");
	}

	fprintf(ofp, "=== bubble 가로 정렬 후 ===\n");
	for (i = 0; i < max; i++)
	{
		bubble(arr_bubble[i]);
	}
	for (i = 0; i < max; i++)
	{
		arr_print(arr_bubble[i]);
	}

	fprintf(ofp, "=== bubble 세로 정렬 후 ===\n");
	for (i = 0; i < max; i++)
	{
		bubbler(&arr_bubble[0][i]);
	}

	for (i = 0; i < max; i++)
	{
		arr_print(arr_bubble[i]);
	}

}

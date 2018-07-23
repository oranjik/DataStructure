#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
	double x;
	double y;
	double val;
}node;
int comND(const void *a, const void *b)
{
	node *c = (node *)a;
	node *d = (node *)b;

	if (c->val < d->val) return -1;
	else if (c->val > d->val) return 1;
	else return 0;
}

int main()
{
	node *v;
	FILE *ofp = fopen("data.txt", "w+");

	v = (node *)calloc(10, sizeof(node));

	fprintf(ofp, "Before Sorting\n");
	for (int i = 0; i < 10; i++)
	{
		v[i].x = rand() / (double)RAND_MAX * 100;
		v[i].y = rand() / (double)RAND_MAX * 100;
		v[i].val = sqrt(pow(50 - v[i].x, 2) + pow(50 - v[i].y, 2));
		fprintf(ofp, "%6.2lf%6.2lf%6.2lf\n", v[i].x, v[i].y, v[i].val);
	}
	fprintf(ofp, "\n\n");

	qsort(v, 10, sizeof(node), comND);
	fprintf(ofp, "After Sorting\n");
	for (int i = 0; i < 10; i++)
	{
		fprintf(ofp, "%6.2lf%6.2lf%6.2lf\n", v[i].x, v[i].y, v[i].val);
	}
	fprintf(ofp, "\n");



	return 0;
}

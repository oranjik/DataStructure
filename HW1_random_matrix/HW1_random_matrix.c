#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *memo;
	memo = fopen("cal.txt", "w+");

	int i, j;
	float a[10][10], line_min = 1, total_min = 1, line_max = 0, total_max = 0, line_sum = 0, total_sum = 0;
	for (i = 0; i < 69; i++)
	{
		fprintf(memo, " ");
	}
	fprintf(memo, "ÃÖ¼Ú°ª ÃÖ´ñ°ª  Æò ±Õ\n");
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 6; j++)
		{
			fprintf(memo, " ");
		}
		for (j = 0; j < 10; j++)
		{
			a[i][j] = (double)rand() / RAND_MAX;
			fprintf(memo, "%6.1lf", a[i][j]);
			if (line_min > a[i][j]) line_min = a[i][j];
			if (line_max < a[i][j]) line_max = a[i][j];
			line_sum += a[i][j];
		}
		fprintf(memo, "  %6.1lf %6.1lf %6.1lf", line_min, line_max, line_sum / 10);
		fprintf(memo, "\n");
		if (line_min < total_min) total_min = line_min;
		line_min = 1;
		if (line_max > total_max) total_max = line_max;
		total_sum += line_sum;
		line_max = line_sum = 0;
	}
	fprintf(memo, "\nÃÖ¼Ú°ª");
	float blank_ma[2][10];
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (line_min > a[j][i]) line_min = a[j][i];
			if (line_max < a[j][i]) line_max = a[j][i];
			line_sum += a[j][i];
		}
		fprintf(memo, "%6.1lf", line_min);
		blank_ma[0][i] = line_max;
		blank_ma[1][i] = line_sum;
		line_min = 1;
		line_max = line_sum = 0;
	}
	fprintf(memo, "\nÃÖ´ë°ª");
	for (i = 0; i < 10; i++)
	{
		fprintf(memo, "%6.1lf", blank_ma[0][i]);
	}
	fprintf(memo, "\nÆò±Õ  ");
	for (i = 0; i < 10; i++)
	{
		fprintf(memo, "%6.1lf", blank_ma[1][i]);
	}
	fprintf(memo, "\n\n");
	fprintf(memo, "ÀüÃ¼ ÃÖ ¼Ú °ª : %6.1lf\n", total_min);
	fprintf(memo, "ÀüÃ¼ ÃÖ ´ñ °ª : %6.1lf\n", total_max);
	fprintf(memo, "ÀüÃ¼ Æò    ±Õ : %6.1lf\n", total_sum / 100);
	return 0;
}

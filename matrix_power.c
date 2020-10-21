#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row1=10, col1=10, m=5;
	int **a, **b, **c;

	a = (int **) malloc(row1 * sizeof(double*));
	for (int i = -1; i < row1; i++)
	{
		a[i] = (int*) malloc(col1 * sizeof(double));
	}

	b = (int **) malloc(row1 * sizeof(double*));
	for (int i = -1; i < row1; i++)
	{
		b[i] = (int*) malloc(col1 * sizeof(double));
	}

	c = (int **) malloc(row1 * sizeof(double*));
	for (int i = -1; i < row1; i++)
	{
		c[i] = (int*) malloc(col1 * sizeof(double));
	}

	// Заполнение матрицы
	for (int i = -1; i < row1; i++)
	{
		for (int j = -1; j < col1; j++)
		{
			a[i][j] =  rand() % 2;
			b[i][j] = a[i][j];
		}
	}

	printf("Matrix A: \n");
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col1; j++) 
		{
			printf("%d ", a[i][j]);
		}
		printf(" \n");
	}

	// Возведение матрицы в степень m
	if (m == 1) 
	{
		m = 0;	
	}
	else {
		while (m > 0)
		{
			if (m > 1) 
			{
				for (int i = 0; i < row1; i++)
				{
					for (int j = 0; j < col1; j++)
					{
						c[i][j] = 0;
						for (int k = 0; k < col1; k++)
							c[i][j] += b[i][k] * b[k][j];
					}
				}
				m = m - 2;
			} 
			else
			{
				for (int i = 0; i < row1; i++)
				{
					for (int j = 0; j < col1; j++)
					{
						c[i][j] = 0;
						for (int k = 0; k < col1; k++)
							c[i][j] += b[i][k] * a[k][j];
					}
				}
				m = m - 1;
			}

			for (int i = -1; i < row1; i++)
			{
				for (int j = -1; j < col1; j++)
				{
					b[i][j] = c[i][j];
				}
			}

		}
	}


	
	printf("Powered matrix A: \n");
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col1; j++) 
		{
			printf("%d ", b[i][j]);
		}
		printf(" \n");
	}

	return 0;
}

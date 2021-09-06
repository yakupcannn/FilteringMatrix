#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <iomanip>
#define size 10


using namespace std;

int main()
{
	srand(time(NULL));
    int i, j, l, row, col, fsize;
	float f1[size][size],f3[size][size],m[size][size], f[size][size], f2[size][size];
	cout << "enter the row and col of matrix: ";
	cin >> row >> col;
	cout << "enter the filter size: ";
	cin >> fsize;
	if (row >= fsize && col >= fsize)
	{
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				m[i][j] = (rand() % 10) + 1;
			}
		}
		cout << "******matrix******" << endl;
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				cout << fixed << setprecision(4)<<m[i][j]<<" ";

			}
			cout << endl;
		}
		cout << endl;
		int k;
		for (i = 0; i < fsize; i++)
		{
			k = fsize / 2;
			for (j = 0; j < fsize; j++)
			{
				f[i][j] = k;
				k--;
			}
		}
		cout << "******edge filter******" << endl;
		for (i = 0; i < fsize; i++)
		{
			for (j = 0; j < fsize; j++)
			{
				cout << fixed << setprecision(4) << f[i][j] <<" ";
			}
			cout << endl;
		}
		cout << endl;
		int n;
		for (i = 0; i < row - fsize + 1; i++)
		{
			for (j = 0; j < col - fsize + 1; j++)
			{
				f2[i][j] = 0;
				for (l = i; l < fsize + i; l++)
				{
					for (n = j; n < fsize + j; n++)
					{
						f2[i][j] += m[l][n] * f[l - i][n - j];
					}

				}
			}
		}
		cout << "******filtered matrix******" << endl;
		for (i = 0; i < row - fsize + 1; i++)
		{
			for (j = 0; j < col - fsize + 1; j++)
			{
				cout << fixed << setprecision(4) <<f2[i][j] <<" ";
			}
			cout << endl;
		}
		for (i = 0; i < fsize; i++)
		{
			for (j = 0; j < fsize; j++)
			{
				f1[i][j] = 1 / (float)(fsize*fsize);
			}

		}
		cout << "******mean filter******" << endl;
		for (i = 0; i < fsize; i++)
		{
			for (j = 0; j < fsize; j++)
			{
				cout << fixed << setprecision(4) << f1[i][j] <<" ";
			}
			cout << endl;
		}
		for (i = 0; i < row - fsize + 1; i++)
		{
			for (j = 0; j < col - fsize + 1; j++)
			{
				f3[i][j] = 0;
				for (l = i; l < fsize + i; l++)
				{
					for (n = j; n < fsize + j; n++)
					{
						f3[i][j] += m[l][n] * f1[l - i][n - j];
					}

				}
			}
		}
		cout << "******filtered 2 matrix******" << endl;

		for (i = 0; i < row - fsize + 1; i++)
		{
			for (j = 0; j < col - fsize + 1; j++)
			{
				cout << fixed << setprecision(4) << f3[i][j] <<" ";
			}
			cout << endl;
		}
	}
	else
	{
	cout << "row and col value cannot be smaller than filter size"<<endl;
 }
	
	system("pause");
	return 0;
}

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int a[2][2], b[2][2], c[2][2];
	int i, j;int q=0,w=0;
	
	while (q != 3)
	{cout << "1. Enter two matrixes \n2. Enter one matrix and count its defenition\n3. Exit\n";
		
	cin >> q;
		switch (q)
		{
		case 1:
		{
			cout << "Enter the first matrix\n";  
			for (i = 0; i<2; i++)
			{
				for (j = 0; j<2; j++)
				{
					cin >> a[i][j];
				}
			}
			cout << "Enter the second matrix\n"; 
			for (i = 0; i<2; i++)
			{
				for (j = 0; j<2; j++)
				{
					cin >> b[i][j];
				}
			}
			
				while (w != 4)
				{cout << "1. Multiply two matrixes \n2. Add the first to the second \n3. Deduct the second from the first\n4. Return\n";
				cin >> w;
					switch (w)
					{
					case 1:
					{c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
					c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
					c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
					c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];

					for (i = 0; i<2; i++)
					{
						for (j = 0; j<2; j++)
						{
							cout << c[i][j] << " ";
						}
						cout << "\n";
					}
					break;

					}
					case 2:
					{c[0][0] = a[0][0] + b[0][0];
					c[0][1] = a[0][1] + b[0][1];
					c[1][0] = a[1][0] + b[1][0];
					c[1][1] = a[1][1] + b[1][1];
					for (i = 0; i<2; i++)
					{
						for (j = 0; j<2; j++)
						{
							cout << c[i][j] << " ";
						}
						cout << "\n";
					} 
					break;
					}
					case 3:
					{
						c[0][0] = a[0][0] - b[0][0];
						c[0][1] = a[0][1] - b[0][1];
						c[1][0] = a[1][0] - b[1][0];
						c[1][1] = a[1][1] - b[1][1];
						for (i = 0; i<2; i++)
						{
							for (j = 0; j<2; j++)
							{
								cout << c[i][j] << " ";
							}
							cout << "\n";
						}
						break;
					}
					}
				}
				break;
		}
		case 2:
		{
			cout << "Enter the matrix: \n";
			for (i = 0; i<2; i++)
			{
				for (j = 0; j<2; j++)
				{
					cin >> a[i][j];
				}
			}
			cout << a[0][0] * a[1][1] - a[0][1] * a[1][0] << "\n";
			break;
			break;
		}
		}
	}
	return 0;
}


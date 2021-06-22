#include <algorithm>
#include <iostream> 
#include<stdio.h>
using namespace std;

const int N = 4;
int c = 8;
int v[] = { 0,1,4,2,3 }, w[] = { 0,4,1,2,5 };//�±��1��ʼ
int x[N + 1];
int m[10][10];
void Knapsack(int v[], int w[], int c, int n, int m[][10])
{
	int jMax = min(w[n] - 1, c);//����ʣ���������� ��Χ[0~w[n]-1]
	for (int j = 0; j <= jMax; j++)
	{
		m[n][j] = 0;
	}

	for (int j = w[n]; j <= c; j++)//���Ʒ�Χ[w[n]~c]
	{
		m[n][j] = v[n];
	}

	for (int i = n - 1; i > 1; i--)
	{
		jMax = min(w[i] - 1, c);
		for (int j = 0; j <= jMax; j++)//������ͬʣ������j<=jMax<c
		{
			m[i][j] = m[i + 1][j];//û�����κ�Ч��
		}

		for (int j = w[i]; j <= c; j++) //������ͬʣ������j-wi >c
		{
			m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);
		}
	}
	m[1][c] = m[2][c];
	if (c >= w[1])
	{
		m[1][c] = max(m[1][c], m[2][c - w[1]] + v[1]);
	}
}
//x[]����洢��Ӧ��Ʒ0-1����,0��װ�뱳����1��ʾװ�뱳��
void Traceback(int m[][10], int w[], int c, int n, int x[])
{
	for (int i = 1; i < n; i++)
	{
		if (m[i][c] == m[i + 1][c])
		{
			x[i] = 0;
		}
		else
		{
			x[i] = 1;
			c -= w[i];
		}
	}
	x[n] = (m[n][c]) ? 1 : 0;
}

int main()
{
	cout << "��װ��Ʒ�����ֱ�Ϊ��" << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << w[i] << " ";
	}
	cout << endl;
	cout << "��װ��Ʒ��ֵ�ֱ�Ϊ��" << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	Knapsack(v, w, c, N, m);
	cout << "������װ������ֵΪ��" << m[1][c] << endl;
	Traceback(m, w, c, N, x);
	cout << "����װ�µ���Ʒ���Ϊ��" << endl;
	for (int i = 1; i <= N; i++)
	{
		if (x[i] == 1)
		{
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}

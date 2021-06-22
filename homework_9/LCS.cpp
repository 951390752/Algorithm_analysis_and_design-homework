#include <stdio.h>
char X[130], Y[130];//输入的两个序列
int C[130][130] = { 0 }, B[130][130] = { 0 };
int m, n;
void z(int B[][130], int i, int j) {
	if (i == 0 || j == 0) {//长度为0跳出
		return;
	}
	if (B[i][j] == 2) {
		z(B, i - 1, j - 1);
		printf("%c ", X[i]);//输出符合的字母
	}
	else if (B[i][j] == 1) {
		z(B, i - 1, j);
	}
	else {
		z(B, i, j - 1);
	}
}
void LCS(char X[], int m, char Y[], int n, int C[][130], int B[][130]) {
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; ++j) {
			if (X[i] == Y[j]) {//第一种情况，这时Zk-1是Xi-1和Yj-1的最长公共子序列
				C[i][j] = C[i - 1][j - 1] + 1;
				B[i][j] = 2;
			}
			else
			{
				if (C[i - 1][j] > C[i][j - 1])//第二种情况，这时Zk-1是Xi-1和Yj的最长公共子序列
				{
					C[i][j] = C[i - 1][j];
					B[i][j] = 1;
				}
				else {
					C[i][j] = C[i][j - 1];//第三种情况，这时Zk-1是Xi和Yj-1的最长公共子序列
					B[i][j] = 0;
				}
			}
		}
	}
	z(B, m, n);
}
int main() {
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++) {
		scanf(" %c", &X[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf(" %c", &Y[i]);
	}
	LCS(X, m, Y, n, C, B);
}

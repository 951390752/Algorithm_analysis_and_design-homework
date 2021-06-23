#include <stdio.h> 
int n, m;//顶点数和着色数
int graph[130][130] = {0};//无向连通图
int color[130] = {0};
int a, b;//变的两顶点 
int s = 0;//方案数
//判断是否能着色 
bool cancColoring(int x) {
	for (int i = 1; i <= n; ++i) {
		//若两点相邻且颜色相同
		if (graph[i][i] && color[i] == color[i]) {
			return false;
		}
	}
	return true;
}
//着色 
void coloring(int x){
	if (x>n) {
		for (int i = 1; i <= n; i++){
			printf("%d ", color[i]);
		}
		s++;
		printf("\n");
	} 
	else {
		for (int i = 1; i <= m; ++i) {
			color[x] = i;
			if (cancColoring(x)) {
				coloring(x+1);
			}
			color[x] = 0;
		}
	}
}
int main(){
	printf("输入顶点数和着色数:\n");
	scanf("%d %d", &n, &m);
	printf("输入边:\n");
	while (scanf("%d %d", &a, &b) && a != 0 && b != 0){
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	coloring(1);
	if (s==0){
		printf("NO\n");
	}
	else{
		printf("着色方案数为%d\n", s);
	}
	return 0;
}

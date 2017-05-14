#include <stdio.h> 

int matrix[100][100];
int visit[100];
int n;

void dfs(int i)
{
	int j;

	visit[i] = 1; // i �� ������ �湮 �Ǿ��� 
	printf("%d ", i);

	for (j = 1; j <= n; j++)
	if (matrix[i][j] == 1 && visit[j] == 0) {  // ���� i ���� j ���� ���� �ְ� j �� ������ �湮���� �ʾ�����  
		dfs(j); // ���ȣ�� 
	}
}

int main()
{
	int ver1, ver2;
	int start;

	scanf("%d %d", &n, &start);

	while (scanf("%d %d", &ver1, &ver2) != EOF){
		matrix[ver1][ver2] = matrix[ver2][ver1] = 1;
	}

	dfs(start);

	return 0;
}
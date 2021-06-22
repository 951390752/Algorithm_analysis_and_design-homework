#include<iostream>

#include<algorithm>

#include<cstring>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, k, d[N][N];

void floyd() {

    for (int k = 1; k <= n; k++)

        for (int i = 1; i <= n; i++)

            for (int j = 1; j <= n; j++)

                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

}

int main(void) {

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)

        for (int j = 1; j <= n; j++) {

            if (i == j)d[i][j] = 0;

            else d[i][j] = INF;

        }

    for (int i = 0, a, b, c; i < m; i++) {

        cin >> a >> b >> c;

        d[a][b] = min(d[a][b], c);

    }

    floyd();

    for (int i = 0, x, y; i < k; i++) {

        cin >> x >> y;

        if (d[x][y] > INF / 2)cout << "impossible" << endl;

        else cout << d[x][y] << endl;

    }

    return 0;

}

#include<bits/stdc++.h>
using namespace std;
int d;
int n, f[101][101], h[101][101], a[101][101], b[101][101], an[101]={0}, bn[101] = {0}, sum = 0;
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> f[i][j]; a[i][f[i][j]] = j;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> h[i][j]; b[i][h[i][j]] = j;
		}
	}
	int x = 0;
	while (sum < n) {
		x++; 
		if (x > n) x = 1;
		if (an[x]>0) continue;
		for (int i = 1; i <= n; ++i) {
			if (bn[f[x][i]]==0) {
				bn[f[x][i]] = x;
				an[x] = f[x][i];
				sum++;
				break;
			}
			else {
				if (b[f[x][i]][x] < b[f[x][i]][bn[f[x][i]]]) {
					an[bn[f[x][i]]] = 0;
					bn[f[x][i]] = x;
					an[x] = f[x][i];
					break;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) cout << an[i] << ' ';
	return 0;
}
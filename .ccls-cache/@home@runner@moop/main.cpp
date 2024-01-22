#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define MAXN 100000

ifstream fin("moop.in");
ofstream fout("moop.out");

int n, x[MAXN], y[MAXN], ans = 1;
int cid[MAXN], minl[MAXN], maxr[MAXN];

bool comp(int a, int b) { 
	return x[a] < x[b] || (x[a] == x[b] && y[a] < y[b]); 
}

int main() {
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> x[i] >> y[i];
		cid[i] = i;
	}
	sort(cid, cid + n, comp);
	minl[0] = y[cid[0]];
	for (int i = 1; i < n; i++)
		minl[i] = min(minl[i - 1], y[cid[i]]);
	maxr[n - 1] = y[cid[n - 1]];
	for (int i = n - 2; i >= 0; i--)
		maxr[i] = max(maxr[i + 1], y[cid[i]]);
	for (int i = 0; i < n - 1; i++)
		if (minl[i] > maxr[i + 1])
			ans++;
	fout << ans << endl;
}
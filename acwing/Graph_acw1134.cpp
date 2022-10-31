#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 400010, mod = 100003;
int n, m;
int h[N], e[M], ne[M], idx;
int dist[N], cnt[N];
int q[N];

void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void bfs(){
	memset(dist, 0x3f, sizeof dist);
	int hh = 0, tt = 0;
	dist[1] = 0, cnt[1] = 1;
	q[0] = 1;
	while(hh <= tt){
		int t = q[hh ++];
		for(int i = h[t]; i != -1; i = ne[i]){
			int j = e[i];
			if(dist[j] > dist[t] + 1){
				dist[j] = dist[t] + 1;
				cnt[j] = cnt[t];
				q[++ tt] = j;
			}
			else if(dist[j] == dist[t] + 1) {
				cnt[j] = (cnt[j] + cnt[t]) % mod;
			}
		}
	}
}

int main(){
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while(m --){
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	bfs();
	for(int i = 1; i <= n; i ++) cout << cnt[i] << endl;
	return 0;
}
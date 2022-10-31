#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>
#include <unordered_map>
#include <set>
using namespace std;

typedef pair<int, int> PII;

#define x first
#define y second

const int N = 15, M = 360, P = 1 << 10;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int h[N * N], e[M], ne[M], idx, w[M];
int g[N][N], key[N * N];
int dist[N * N][P];
int n, m, p, k;
bool st[N * N][P];

set<PII> edges;

int get(int x, int y) {return (x - 1) * n + y;}

void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void build(){
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			for(int u = 0; u < 4; u ++){
				int x = i + dx[u], y = j + dy[u];
				if(x <= 0 || y <= 0 || x > n || y > m) continue;
				int a = g[i][j], b = g[x][y];
				if(!edges.count({a, b})) add(a, b, 0);
			}
		}
	}
}

int bfs(){
	memset(dist, 0x3f, sizeof dist);
	dist[1][0] = 0;
	deque<PII> q;
	q.push_back({1, 0});
	while(q.size()){
		auto t = q.front();
		q.pop_front();
		if(st[t.x][t.y]) continue;
		st[t.x][t.y] = true;
		if(t.x == n * m) return dist[t.x][t.y];
		if(key[t.x]){
			int state = t.y | key[t.x];
			if(dist[t.x][state] > dist[t.x][t.y]){
				dist[t.x][state] = dist[t.x][t.y];
				q.push_front({t.x, state});
			}
		}
		for(int i = h[t.x]; ~i; i = ne[i]){
			int j = e[i];
			if(w[i] && !(t.y >> w[i] - 1 & 1)) continue;
			if(dist[j][t.y] > dist[t.x][t.y] + 1){
				dist[j][t.y] = dist[t.x][t.y] + 1;
				q.push_back({j, t.y});
			}
		}
	}
	return -1;
}

int main(){
	cin >> n >> m >> p >> k;
	for(int i = 1, t = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++)
			g[i][j] = t ++;
	}
	memset(h, -1, sizeof h);
	while(k --){
		int x1, y1, x2, y2, c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		int a = g[x1][y1], b = g[x2][y2];
		edges.insert({a, b}), edges.insert({b, a});
		if(c) add(a, b, c), add(b, a, c);
	}
	build();
	int s;
	cin >> s;
	while(s --){
		int x, y, c;
		cin >> x >> y >> c;
		key[g[x][y]] |= 1 << c - 1;
	}
	cout << bfs() << endl;
	return 0;
}
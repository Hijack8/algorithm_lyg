#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> PII;

#define x first
#define y second

const int N = 150010;
int h[N], e[N], ne[N], w[N], idx;
int n, m;
int dist[N];
bool st[N];

void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

int dijkstra(){
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> q;
	q.push({0, 1});
	while(q.size()){
		auto t = q.top();
		q.pop();
		int distance = t.x, id = t.y;
		if(st[id]) continue;
		st[id] = true;
		for(int i = h[id]; i != -1; i = ne[i]){
			int j = e[i];
			if(dist[j] > distance + w[i]) {
				dist[j] = distance + w[i];
				q.push({dist[j], j});
			}
		}
	}
	if(dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];

}

int main(){
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while(m --){
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	cout << dijkstra();
	return 0;
}
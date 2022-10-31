#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 1010, M = 20010;
int h[N], e[M], ne[M], w[M], idx;
int T, n, m, s;
bool st[N];
int dist[N];

void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

int main(){
	while(cin >> n >> m >> s){
		int a, b, c;
		memset(h, -1, sizeof h);
		memset(st, 0, sizeof st);
		memset(dist, 0x3f, sizeof dist);
		while(m --){
			cin >> a >> b >> c;
			add(a, b, c);
		}
		int ws;
		cin >> ws;
		priority_queue<PII, vector<PII>, greater<PII> > heap;
		for(int i = 0; i < ws; i ++){
			int x;
			cin >> x;
			dist[x] = 0;
			heap.push({dist[x], x});
		}
		while(heap.size()){
			auto t = heap.top();
			heap.pop();
			int id = t.second, distance = t.first;
			if(st[id]) continue;
			for(int i = h[id]; i != -1; i = ne[i]){
				int j = e[i];
				if(dist[j] > distance + w[i]){
					dist[j] = distance + w[i];
					heap.push({dist[j], j});
				}
			}
		}
		if(dist[s] == 0x3f3f3f3f) cout << -1 << endl;
		else cout << dist[s] << endl;
	}

	return 0;
}
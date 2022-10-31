// spfa算法
// 类似bfs
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

int spfa(){
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	queue<int> q;
	q.push(1);
	st[1] = true;
	while(q.size()){
		int t = q.front();
		q.pop();
		st[t] = false;
		for(int i = h[t]; i != -1; i = ne[i]){
			int j = e[i];
			if(dist[j] > dist[t] + w[i]){
				dist[j] = dist[t] + w[i];
				if(!st[j]){
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
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
	int t = spfa();
	if(t == 0x3f3f3f3f) cout << "impossible" << endl;
	else cout << t << endl;
	return 0;
}
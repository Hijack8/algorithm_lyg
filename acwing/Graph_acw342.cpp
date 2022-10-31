#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int > PII;
const int N = 25010, M = 150010, INF = 0x3f3f3f3f;
int h[N], e[M], ne[M], w[M], idx;
int n, r, p, s;
bool st[N];
int id[N];
vector<int> block[N];
int dist[N];
int block_num;
int in[N];
queue<int> q;

void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void dfs(int u, int num){
	id[u] = num;
	block[num].push_back(u);
	for(int i = h[u]; i != -1; i = ne[i]){
		if(!id[e[i]])
			dfs(e[i], num);
	}
}

void dijkstra(int u){
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	for(int i = 0; i < block[u].size(); i ++){
		pq.push({dist[block[u][i]], block[u][i]});
	}
	while(pq.size()){
		auto t = pq.top();
		pq.pop();
		int x = t.first, y = t.second;
		if(st[y]) continue;
		st[y] = true;
		for(int i = h[y]; i != -1; i = ne[i]){
			int j = e[i];
			if(dist[j] > x + w[i]){
				dist[j] = x + w[i];
				if(id[j] == id[y]) pq.push({dist[j], j});
			}
			if(id[j] != id[y] && -- in[id[j]] == 0) q.push(id[j]);
		}
	}
}

void top_sort(){
	memset(dist, 0x3f, sizeof dist);
	dist[s] = 0;
	for(int i = 1; i <= block_num; i ++){
		if(!in[i])
			q.push(i);
	}
	while(q.size()){
		int t = q.front();
		q.pop();
		dijkstra(t);
	}
}

int main(){
	cin >> n >> r >> p >> s;
	memset(h, -1, sizeof h);
	while(r --){
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	for(int i = 1; i <= n; i ++){
		if(!id[i]){
			dfs(i, ++ block_num);
		}
	}
	while(p --){
		int a, b, c;
		cin >> a >> b >> c;
		in[id[b]] ++;
		add(a, b, c);
	}

	top_sort();
	for(int i = 1; i <= n; i ++){
		if(dist[i] >= INF / 2){
			cout << "NO PATH" << endl;
		}
		else cout << dist[i] << endl;
	}


	return 0;
}
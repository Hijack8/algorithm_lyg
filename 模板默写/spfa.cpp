#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], w[N], idx;
int n, m;
int dist[N];
bool st[N];

void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

int spfa(){
	memset(dist, 0x3f, sizeof dist);
	queue<int> q;
	q.push(1);
	st[1] = true;
	dist[1] = 0;
	while(q.size()){
		auto t = q.front();
		q.pop();
		st[t] = false;
		for(int i = h[t]; i != -1; i = ne[i]){
			int j = e[i];
			if(dist[j] > dist[t] + w[i]){
				dist[j] = dist[t] + w[i];
				if(!st[j]) {
					st[j] = true;
					q.push(j);
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
	int rst = spfa();
	if(rst == 0x3f3f3f3f) cout << "impossible" << endl;
	else cout << rst << endl;
	return 0;
}
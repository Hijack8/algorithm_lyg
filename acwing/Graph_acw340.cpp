#include <iostream>
#include <cstring>
#include <deque>
#include <algorithm>

using namespace std;

const int N = 1010, M = 200010;
int n, m, k;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];
deque<int > q;


void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

bool check(int bound){
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);

	q.push_back(1);
	dist[1] = 0;

	while(q.size()){
		auto t = q.front();
		q.pop_front();
		if(st[t]) continue;
		st[t] = true;
		for(int i = h[t]; ~i; i = ne[i]){
			int j = e[i], x = w[i] > bound;
			if(dist[j] > dist[t] + x) {
				dist[j] = dist[t] + x;
    			if(x) q.push_back(j);
    			else q.push_front(j);
			}
		}
	}
	return dist[n] <= k;
}

int main(){
	cin >> n >> m >> k;
	memset(h, -1, sizeof h);
	while(m --){
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	int l = 0, r = 1e6 + 1;
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	if(l == 1e6 + 1) cout << -1 << endl;
	else cout << l << endl;

	return 0;
}
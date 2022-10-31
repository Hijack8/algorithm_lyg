#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1010, M = 10010;
struct Ver
{
	int id, type, dist;
	bool operator> (const Ver &W)const{
		return dist > W.dist;
	}
};

int n, m, S, T;
int h[N], e[M], ne[M], w[M], idx;
int dist[N][2], cnt[N][2];
bool st[N][2];

void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

int dijkstra(){
	memset(st, 0, sizeof st);
	memset(cnt, 0, sizeof cnt);
	memset(dist, 0x3f, sizeof dist);
	dist[S][0] = 0, cnt[S][0] = 1;
	priority_queue<Ver, vector<Ver>, greater<Ver>> heap;
	heap.push({S, 0, 0});
	while(heap.size()){
		auto t = heap.top();
		heap.pop();

		int id = t.id, type = t.type, distance = t.dist, count = cnt[id][type];
		if(st[id][type]) continue;
		st[id][type] = true;
		for(int i = h[id]; i != -1; i = ne[i]){
			int j = e[i];
			if(dist[j][0] > distance + w[i]){
				dist[j][1] = dist[j][0];
				cnt[j][1] = cnt[j][0];
				heap.push({j, 1, dist[j][1]});
				dist[j][0] = distance + w[i];
				cnt[j][0] = count;
				heap.push({j, 0, dist[j][0]});
			}
			else if(dist[j][0] == distance + w[i]){
				cnt[j][0] += count;
			}
			else if(dist[j][1] > distance + w[i]){
				dist[j][1] = distance + w[i], cnt[j][1] = count;
				heap.push({j, 1, dist[j][1]});
			}
			else if(dist[j][1] == distance + w[i]){
				cnt[j][1] += count;
			}
		}
	}
	int rst = cnt[T][0];
	if(dist[T][0] + 1 == dist[T][1]) rst += cnt[T][1];
	return rst;
}

int main(){
	int cases;
	cin >> cases;
	while(cases --){
		cin >> n >> m;
		memset(h, -1, sizeof h);
		idx = 0;
		while(m --){
			int a, b, c;
			cin >> a >> b >> c;
			add(a, b, c);
		}
		cin >> S >> T;
		cout << dijkstra() << endl;
	}

	return 0;
}
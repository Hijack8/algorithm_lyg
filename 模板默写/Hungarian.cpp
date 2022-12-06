#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = N * N;
int h[N], e[M], ne[M], idx;
int n1, n2, m;
bool st[N];
int match[N];

void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool find(int x){
	for(int i = h[x]; i != -1; i = ne[i]){
		 int j = e[i];
		 if(st[j]) continue;
		 st[j] = true;
		 if(match[j] == 0 || find(match[j])) {
		 	match[j] = x;
		 	return true;
		 }
	}
	return false;
}


int main(){
	cin >> n1 >> n2 >> m;
	memset(h, -1, sizeof h);
	while(m --){
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	int rst = 0;
	for(int i = 1; i <= n1; i ++){
		memset(st, 0, sizeof st);
		if(find(i)){
			rst ++;
		}
	}
	cout << rst << endl;
	return 0;
}
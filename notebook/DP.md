## 1. 数字三角形模型

数字三角形模型，主要是类似从左上角走到右下角且只能向下向右走的过程。

普通的数字三角形的话肯定都会做，类似：
$$
f[i][j] = \phi(f[i - 1][j], f[i][j - 1])
$$
重要的其实是类似两个路径的模型，例如 [acwing1027 ](https://www.acwing.com/problem/content/1029/)和 [acwing275](https://www.acwing.com/problem/content/277/) 。

### 1.1 acwing1027方格取数

#### 题意

设有 N×N 的方格图，我们在其中的某些方格中填入正整数，而其它的方格中则放入数字0。如下图所示：

![2.gif](https://cdn.acwing.com/media/article/image/2019/09/12/19_764ece6ed5-2.gif)

某人从图中的左上角 A 出发，可以向下行走，也可以向右行走，直到到达右下角的 B 点。

在走过的路上，他可以取走方格中的数（取走后的方格中将变为数字0）。

此人从 A 点到 B 点共走了两次，试找出两条这样的路径，使得取得的数字和为最大。

#### 分析

两条路径，首先想到的是用变量将两个路径都存下来，例如：
$$
f[i][j][k][m] 表示第一个点到(i, j), 第二个点到(k, m)所取得的最大值。
$$
这样复杂度显然是$n^4$的 ，明显不和题意。

我们最终是求的第一个点和第二个点同时到达右下角的最大值，因此我们可以假设两个点同步走，这样就可以简化状态表示：

```
f[k][i][j]  表示第一个点和第二个点均走了k步，同时第一个点x方向走了i，第二个点x方向走了j，此时的最大值。

f[k][i][j] = max(f[k - 1][i][j], f[k - 1][i][j - 1], f[k - 1][i - 1][j], f[k - 1][i - 1][j - 1]) + g[x1][y1] + g[x2][y2];
```

当然要注意二者走到同一个点的时候，此时只能加一遍。

```cpp
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 15;
int f[N * 2][N][N];
int g[N][N];
int n;

int max(int a, int b, int c, int d){
    return max(max(a, b), max(c, d));
}

int main(){
    cin >> n;
    int a, b, c;
    while(cin >> a >> b >> c, a || b || c) {
        g[a][b] = c;
    }
    for(int k = 2; k <= 2 * n; k ++){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                int x1 = i, y1 = k - i, x2 = j, y2 = k - j;
                if(y1 < 1 || y1 > n || y2 < 1 || y2 > n) continue;
                f[k][i][j] = max(f[k - 1][i][j], f[k - 1][i - 1][j], f[k - 1][i][j - 1], f[k - 1][i - 1][j - 1]);
                int t = g[x1][y1];
                if(x1 != x2) t += g[x2][y2];
                f[k][i][j] += t;
            }
        }
    }
    cout << f[2 * n][n][n];
    return 0;
}
```

### 1.2 acwing275传纸条

#### 题意

给一个m行n列的矩阵，两个同学分别在左上角和右下角，二人相互传纸条，不能经过重复的点，求出经过路径和的最大值。

#### 分析

依然是这个状态表示：

```
f[k][i][j]  表示第一个点和第二个点均走了k步，同时第一个点x方向走了i，第二个点x方向走了j，此时的最大值。

f[k][i][j] = max(f[k - 1][i][j], f[k - 1][i][j - 1], f[k - 1][i - 1][j], f[k - 1][i - 1][j - 1]) + g[x1][y1] + g[x2][y2];
```

此时我们要注意的是边界条件：

如果 

* $ i == j$ 相当于二者走到一个点去了，显然这是不可取的，因此我们给他赋值为 $-INF$

但是我们同时又注意到终点地方就是符合$i == j$的，因此在那里我们需要特判一下。

* $i == j ~\&\&~ k == n + m$   $f[k][i][j] = max(1, 2, 3, 4) + 0$
* $ i == j ~\&\& ~k != n + m $   $f[k][i][j] = -INF$
* $i != j$  $f[k][i][j] = max(1, 2, 3, 4) + g[x1][y1] + g[x2][y2]$

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 55;
int g[N][N];
int f[N * 2][N][N];
int n, m;

int max(int a, int b, int c, int d){
    return max(max(a, b), max(c, d));
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++){
            cin >> g[i][j];
        }
    
    for(int k = 2; k <= n + m; k ++){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                int x1 = i, y1 = k - i, x2 = j, y2 = k - j;
                if(y1 < 1 || y2 < 1 || y1 > m || y2 > m) continue;
                f[k][i][j] = max(f[k - 1][i][j], f[k - 1][i - 1][j], f[k - 1][i][j - 1], f[k - 1][i - 1][j - 1]);
                if(i == j && k != n + m) f[k][i][j] = -1e9;
                else f[k][i][j] += g[x1][y1] + g[x2][y2];
            }
        }
    }
    cout << f[n + m][n][n];
    
    return 0;
}
```



## 2. 最长上升子序列模型

基本模板

```cpp
for(int i = 1; i <= n; i ++){
    up[i] = 1;
    for(int j = 1; j < i; j ++){
        if(a[i] > a[j])
            up[i] = max(up[i], up[j] + 1);
    }
}
```


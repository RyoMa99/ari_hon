#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ce(s) cout<< s << endl;
#define sp(i) cout<< fixed << setprecision((int)i); // 浮動小数点の表示桁数を指定
#define rep(ri,rj,rk) for (int ri = (int)rj; ri < (int)rk; ri++)
#define lrep(ri,rj,rk) for (ll ri = (ll)rj; ri < (ll)rk; ri++)
#define rrep(ri,rj,rk) for (int ri = (int)rj; ri > (int)rk; ri--)
#define all(x) x.begin(), x.end()
// 最大公約数 ユークリッドの互除法
template <typename T>
T gcd(T a, T b)
{
  if (a%b == 0) return b;
  else return gcd(b,a%b);
}

// 最大公倍数
template <typename T>
T lcm(T a, T b)
{
  return a*b / gcd(a,b);
}

const int INF = 100000000;

// 入力
char maze[100][101];
int N,M;
int sx, sy, gx, gy;

int d[100][100]; // 各点までの最短距離

// ベクトル
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs(){
  queue<pair<int, int>> que;
  rep(i,0,N) rep(j,0,M) d[i][j] = INF;
  que.push({sx, sy});
  d[sx][sy] = 0;

  // キューが空になるまでループさせる
  while(que.size())
  {
    pair<int, int> p = que.front(); que.pop();
    // ゴールにたどり着いたら終了
    if (p.first == gx && p.second == gy) break;

    // 4方向見る
    rep(i,0,4)
    {
      int nx = p.first + dx[i], ny = p.second + dy[i];

      // 移動可能かつ未だ訪れていないか判定
      if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF)
      {
        que.push({nx,ny});
        d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }
  return d[gx][gy];
}

int main()
{
  cin >> N >> M;
  rep(i,0,N) rep(j,0,M)
  {
    char s; cin >> s;
    maze[i][j] = s;
    if (s == 'S'){
      sx = i; sy = j;
    } else if(s == 'G') {
      gx = i; gy = j;
    }
  }

  ce(bfs());
  return 0;
}

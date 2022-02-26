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

int INF = 1000000001;
int n,W;
int dp[101][10001];
vector<int> v,w;

int main()
{
  cin >> n >> W;
  rep(i,0,n)
  {
    int wt,vt; cin >> wt >> vt;
    w.push_back(wt);
    v.push_back(vt);
  }

  fill(dp[0],dp[0]+10001,INF);
  dp[0][0] = 0;

  rep(i,1,n+1)
  {
    rep(j,1,10001)
    {
      if(j < v[i-1])
      {
        dp[i][j] = dp[i-1][j];
      }else{
        dp[i][j] = min(dp[i-1][j],dp[i-1][j-v[i-1]] + w[i-1]);
      }
    }
  }

  int ans = 0;
  rep(i,0,10001) if(W >= dp[n][i]) ans = i;
  ce(ans);

  return 0;
}

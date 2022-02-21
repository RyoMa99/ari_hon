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

int N,W;
vector<pair<int, int>> items;
int dp[101][1001];

int rec(){
  rep(i,1,N+1)
  {
    rep(j,1,W+1)
    {
      if(items[i-1].first > j)
      {
        dp[i][j] = dp[i-1][j];
      } else {
        dp[i][j] = max(dp[i-1][j], items[i-1].second + dp[i-1][j-items[i-1].first]);
      } 
    }
  }

  return dp[N][W];
}

int main()
{
  cin >> N >> W;
  rep(i,0,N)
  {
    int w,v; cin >> w >> v;
    items.push_back({w,v});
  }
  
  ce(rec());
  // rep(i,0,N+1){
  //   rep(j,0,W+1)
  //   {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  return 0;
}

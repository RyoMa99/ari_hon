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

int n,K;
vector<int> a,m;
int dp[100001];

int main()
{
  cin >> n >> K;
  rep(i,0,n)
  {
    int at,mt; cin >> at >> mt;
    a.push_back(at);
    m.push_back(mt);
  }
  memset(dp,-1,sizeof(dp));
  dp[0] = 0;

  rep(i,1,n+1)
  {
    rep(j,0,K+1)
    {
      if(dp[j] >= 0)
      {
        dp[j] = m[i-1];
      }else if(j < a[i-1] || dp[j-a[i-1]] <= 0){
        dp[j] = -1;
      }else{
        dp[j] = dp[j-a[i-1]] - 1;
      }
    }
  }

  cout << (dp[K] >= 0 ? "Yes" : "No") << endl;
  return 0;
}

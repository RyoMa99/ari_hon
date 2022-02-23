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

int N,M;
int dp[1001][1001];
char S[1000],T[1000];

int main()
{
  cin >> N >> M;
  cin >> S >> T;
  
  rep(i,1,N+1)
  {
    rep(j,1,M+1)
    {
      if(S[i-1] == T[j-1]){
        dp[i][j] = dp[i-1][j-1] + 1;
      }else{
        dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
      }
    }
  }

  ce(dp[N][M]);
  return 0;
}

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

int N;
vector<int> A;
int K;

bool dfs(int number, int sum)
{
  if (N == number) return K == sum;
  
  return dfs(number+1,sum) || dfs(number+1,sum+A[number]);
}

int main()
{
  cin >> N;
  A.resize(N);
  rep(i,0,N) cin >> A[i];
  cin >> K;

  cout << (dfs(0,0) ? "Yes" : "No") << endl;
  return 0;
}

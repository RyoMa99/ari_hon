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
int L[1000];

int main()
{
  cin >> N;
  rep(i,0,N) cin >> L[i];
  ll ans = 0;

  // 小さいほうから出す
  priority_queue<int, vector<int>, greater<int>> que;
  rep(i,0,N) que.push(L[i]);

  while(que.size() > 1)
  {
    int l1, l2;
    l1 = que.top(); que.pop();
    l2 = que.top(); que.pop();

    ans += l1 + l2;
    que.push(l1+l2);
  }

  ce(ans);
  return 0;
}

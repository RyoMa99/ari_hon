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


int main()
{
  int N,L,P;
  vector<int> A,B;
  priority_queue<int> pque;
  cin >> N >> L >> P;
  A.resize(N); B.resize(N);
  rep(i,0,N) cin >> A[i];
  rep(i,0,N) cin >> B[i];

  int progress = 0;
  int ans = -1;
  pque.push(P);

  while(!pque.empty())
  {
    if (progress >= L) break;
    progress += pque.top(); pque.pop(); ans++;
    ce(progress);
    while (A.front() <= progress)
    {
      if (progress >= L) break;
      pque.push(B.front());
      B.erase(B.begin()); A.erase(A.begin());
    }
  }
  ans = progress < L ? -1 : ans; 
  
  ce(ans);
  return 0;
}

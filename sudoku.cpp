//project1 Sudoku solver using BACKTRACKING
//drishti2511
#include <bits/stdc++.h>
using namespace std;
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
typedef long long ll;
#define lop(i, a, b) for (i = a; i < b; i++)
ll mod = 1e9 + 7;
#define max3(a, b, c) max(max((a), (b)), (c))
#define max4(a, b, c, d) max(max((a), (b)), max((c)6, (d)))
#define min3(a, b, c) min(min((a), (b)), (c))
#define min4(a, b, c, d) min(min((a), (b)), min((c), (d)))
#define all(v) (v).begin(), (v).end()
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define input(v, n) lop(i, 0, n) cin >> v[i]
#define take(x)       \
    for (auto &y : x) \
    cin >> y
#define show(x)           \
    for (auto y : x)      \
        cout << y << " "; \
    cout << endl
#define output(v, n) lop(i, 0, n) cout << v[i] >> " "
#define deb(x) cout << x << " "

#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

//gcd func __gcd(m,n)
//g++ --std c++11 sudoku.cpp
//end of template

bool canPlace(vector<vector<ll> > v, ll row, ll col, ll num)
{
    ll i;
    lop(i, 0, 9)
    {
        if (v[row][i] == num)
            return false;
    }
    lop(i, 0, 9)
    {
        if (v[i][col] == num)
            return false;
    }
    ll x = row / 3;
    ll y = col / 3;
    x = 3 * (x);
    y = 3 * (y);
    ll j;
    lop(i, x, x + 3)
    {
        lop(j, y, y + 3)
        {
            if (v[i][j] == num)
                return false;
        }
    }
    return true;
}

bool SolveSudoku(vector<vector<ll> > &v)
{
  ll i,j;
  int f=0;
  lop(i,0,9)
  {
      lop(j,0,9)
      {
          if(v[i][j]==0)
          {
              f=1;
              break;
          }
      }
      if(f==1)
      break;
  }
  if(f==0)return true;
  ll k;
  lop(k,1,10)
  {
      if(canPlace(v,i,j,k))
      {
      v[i][j]=k;
      if(SolveSudoku(v))
      return true;
      v[i][j]=0;
      }
  }
  return false;

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif
    fio;
    /*ll t;
    cin >> t;
    while (t--)
    {*/
    vector<vector<ll> > ans(9, vector<ll>(9, 0));
    ll i, j;
    lop(i, 0, 9)
    {
        lop(j, 0, 9)
        {
            ll x;
            cin >> x;
            //emp++;
            ans[i][j] = x;
        }
    }
    if (SolveSudoku(ans))
    {
        lop(i, 0, 9)
        {
            lop(j, 0, 9)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
        cout << "No solution exists" << endl;

    // }
}
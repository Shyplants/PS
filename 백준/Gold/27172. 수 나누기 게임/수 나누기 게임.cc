#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAX_NUM = 1e6 + 6;
const int MAX_N = 1e5 + 5;

int sp[MAX_NUM], n, x[MAX_N], x2Idx[MAX_NUM], ans[MAX_N];
bool oneFlag;
vector<int> prime;

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0);

  for(int i=2; i<MAX_NUM; ++i) {
    if(!sp[i]) prime.push_back(i);
    for(auto& p : prime) {
      if(1LL*i*p > MAX_NUM) break;
      sp[i*p] = p;
      if(i%p == 0) break;
    }
  }

  memset(x2Idx, -1, sizeof(x2Idx));

  cin >> n;
  for(int i=0; i<n; ++i) {
    cin >> x[i];
    x2Idx[x[i]] = i;
    oneFlag |= (x[i] == 1);
  }

  for(int i=0; i<n; ++i) {
    for(int j=2; j*j<=x[i]; ++j) {
      if(x[i]%j != 0) continue;

      int a = j;
      int b = x[i]/j;

      if(x2Idx[a] != -1) {
        ans[i]--;
        ans[x2Idx[a]]++;
      }
      if(a != b && x2Idx[b] != -1) {
        ans[i]--;
        ans[x2Idx[b]]++;
      }
    }
  }

  if(oneFlag) {
    for(int i=0; i<n; ++i) {
      ans[i] += (x[i] == 1 ? n-1 : -1);
    }
  }

  for(int i=0; i<n; ++i) {
    cout << ans[i] << ' ';
  }
 
  return 0;
}
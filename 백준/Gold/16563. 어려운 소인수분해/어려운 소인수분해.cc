#include<bits/stdc++.h>

using namespace std;

const int MAX_K = 5e6 + 1;

vector<int> p;
int sp[MAX_K];
int n, k;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    for(int i=2; i<=MAX_K; i++){

        if(!sp[i]) p.push_back(i);
        for(int j : p){
            if(i*j > MAX_K) break;
            sp[i*j] = j;
            if(i%j == 0) break;
        }
    }

    cin >> n;
    while(n--){
        cin >> k;
        while(sp[k]){
            cout << sp[k] << " ";
            k /= sp[k];
        }
        cout << k << '\n';
    }
    return 0;
}
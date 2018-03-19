#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int t, n, m, ara[102][102], bra[102][102];

bool check1() {
        for(int i=1; i<=n; i++) {
                int cur = 0;
                for(int j=1; j<=m; j++) {
                        if( ara[i][j] < cur ) {
                                return false;
                        }
                        cur = ara[i][j];
                }
        }
        return true;
}

bool check2() {
        for(int i=1; i<=m; i++) {
                int cur = 0;
                for(int j=1; j<=n; j++) {
                        if( ara[j][i] < cur ) {
                                return false;
                        }
                        cur = ara[j][i];
                }
        }
        return true;
}

void print() {
        for(int i=1; i<=n; i++) {
                for(int j=1; j<=m; j++) {
                        cout << ara[i][j] << " ";
                }
                cout << "\n";
        }
}

void solve() {
        cin >> n >> m;
        for(int i=1; i<=n; i++) {
                for(int j=1; j<=m; j++) {
                        cin >> ara[i][j];
                        bra[i][j] = ara[i][j];
                }
        }

        for(int i=1; i<=n; i++) {
                int cur = max(ara[i][1], 1);
                for(int j=1; j<=m; j++) {
                        if(ara[i][j] == -1) {
                                ara[i][j] = cur;
                        }
                        cur = ara[i][j];
                }
        }

        for(int i=1; i<=m; i++) {
                int cur = max(ara[1][i], 1);
                for(int j=1; j<=n; j++) {
                        if( bra[j][i] == -1 ) {
                                ara[j][i] = max(cur, ara[j][i]);
                        }
                        cur = ara[j][i];
                }
        }

        //print();

        if( check1() == false || check2() == false ) {
                puts("-1");
                return;
        }

        print();
}

int main() {
        #ifdef _OFFLINE_
                freopen("in.txt", "r", stdin);
        #endif /// _OFFLINE_

        int t;
        cin >> t;
        while( t-- ) {
                solve();
        }

        return 0;
}

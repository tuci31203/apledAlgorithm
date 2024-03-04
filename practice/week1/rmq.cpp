#include<bits/stdc++.h>
using namespace std;

int m[1000][1000];
struct Query{
    int x,y;
};

void preprocess(int a[], int n){
    for (int j=0; j<n; j++) m[0][j] = j;

    for(int i=1; (1<<i) <= n; i++){
        for(int j=0; j + (1<<i) - 1 < n; j++){
            if(a[m[i-1][j]] < a[m[i-1][j+(1<<(i-1))]]){
                m[i][j] = m[i-1][j];
            }else{
                m[i][j] = m[i-1][j+(1<<(i-1))];
            }
        }
    }

}

int search(int a[], int x, int y){
    int k = (int)log2(y-x+1);
    if(a[m[k][x]] <= a[m[k][y - (1<<k) +1]]){
        return a[m[k][x]];
    }else{
        return a[m[k][y - (1<<k) + 1]];
    }
}

int solve(int a[], int n, Query q[], int m){
    preprocess(a, n);
    int sum = 0;
    for(int i=0; i<m; i++){
        sum += search(a, q[i].x, q[i].y);
    }
    return sum;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    cin >> m;
    Query q[m];
    for(int i=0; i<m; i++) cin >> q[i].x >> q[i].y;

    cout << solve(a, n, q, m);
}
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001

long m[100][MAX];
struct Query{
    long x,y;
};

void preprocess(long a[], long n){
    for (long j=0; j<n; j++) m[0][j] = j;

    for(long i=1; (1<<i) <= n; i++){
        for(long j=0; j + (1<<i) - 1 < n; j++){
            if(a[m[i-1][j]] < a[m[i-1][j+(1<<(i-1))]]){
                m[i][j] = m[i-1][j];
            }else{
                m[i][j] = m[i-1][j+(1<<(i-1))];
            }
        }
    }

}

long search(long a[], long x, long y){
    long k = (long)log2(y-x+1);
    long p2k = (1<<k);
    if(a[m[k][x]] <= a[m[k][y - p2k +1]]){
        return a[m[k][x]];
    }else{
        return a[m[k][y - p2k + 1]];
    }
}

long solve(long a[], long n, Query q[], long m){
    preprocess(a, n);
    long sum = 0;
    for(long i=0; i<m; i++){
        sum += search(a, q[i].x, q[i].y);
    }
    return sum;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long n, m;
    cin >> n;
    long a[n];
    for(long i=0; i<n; i++) cin >> a[i];
    cin >> m;
    Query q[m];
    for(long i=0; i<m; i++) cin >> q[i].x >> q[i].y;

    cout << solve(a, n, q, m);
}
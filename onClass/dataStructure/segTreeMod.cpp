#include<bits/stdc++.h>
using namespace std;

int n, k;
int maxVal[400001], a[100001];

struct Query{
    string act;
    int i, j;
};

void buildSegmentTree(int id, int l, int r){
    if (l == r) {
        maxVal[id] = a[l];
        return;
    }
    int m = (l + r) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    buildSegmentTree(lc, l, m);
    buildSegmentTree(rc, m + 1, r);
    maxVal[id] = max(maxVal[lc], maxVal[rc]);
}

int getMax(int id, int l, int r, int i, int j){
    if (i > r || j < l) return INT_MIN;
    if (i <= l && j >= r) return maxVal[id];
    int m = (l + r) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    int maxLeft = getMax(lc, l, m, i, j);
    int maxRight = getMax(rc, m + 1, r, i, j);
    return max(maxLeft, maxRight);
}

void updateNode(int id, int l, int r, int index, int val){
    if (l == r) {
        maxVal[id] = val;
        return;
    }
    int m = (l + r) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    if (index <= m) updateNode(lc, l, m, index, val);
    else updateNode(rc, m + 1, r, index, val);
    maxVal[id] = max(maxVal[lc], maxVal[rc]);
}

void update(int index, int val){
    updateNode(1, 1, n, index, val);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    buildSegmentTree(1, 1, n);

    cin >> k;
    Query q[k];
    for (int i = 0; i < k; i++){
        cin >> q[i].act >> q[i].i >> q[i].j;
    }

    for (int i = 0; i < k; i++){
        if (q[i].act[0] == 'g') cout << getMax(1, 1, n, q[i].i, q[i].j) << endl;
        else update(q[i].i, q[i].j);
    }
    
    return 0;
}

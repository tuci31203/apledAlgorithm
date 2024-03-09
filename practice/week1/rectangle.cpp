#include<bits/stdc++.h>
using namespace std;

int maxHistogram(int row[], int R, int C){
    stack<int> res;
    int top, maxArea = 0, area = 0, i = 0;
    while(i<C){
        if(res.empty() || row[res.top()] <= row[i]) res.push(i++);
        else{
            top = row[res.top()];
            res.pop();
            area = top * i;

            if(!res.empty()){
                area = top * (i-res.top()-1);
            }
            maxArea = max(area, maxArea);
        }
    }

    while(!res.empty()){
        top = row[res.top()];
        res.pop();
        area = top * i;
        if(!res.empty()){
                area = top * (i-res.top()-1);
        }
        maxArea = max(area, maxArea);
    }
    return maxArea;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r, c;
    cin >> r >> c;
    int a[r][c];
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin >> a[i][j];

    int res = maxHistogram(a[0], r, c);
    for(int i=1; i<r; i++){
        for(int j=0; j<c; j++){
            if(a[i][j]) a[i][j] += a[i-1][j];
        }
        res = max(res, maxHistogram(a[i], r, c));
    }
    cout << res;
    return 0;
}
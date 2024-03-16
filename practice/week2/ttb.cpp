#include<bits/stdc++.h>
using namespace std;

struct Teachers{
    vector<int> courses;
    int load = 0;
};

int n,m,k;

vector<Teachers> teacher;
vector<vector<int>> conflicts;
int courseAssignment[1000];

int maxLoad = -1, minSol = INT_MAX;

void input(){
    cin >> m >> n;
    int k;
    for(int i=1; i<n+1; i++) courseAssignment[i] = -1;
    teacher.resize(m);
    for(int i=0; i<m; i++){
        cin >> k;
        for (int j=0; j<k; j++){
            int tmp;
            cin >> tmp;
            teacher[i].courses.push_back(tmp);
        }
    }

    cin >> k;
    conflicts.resize(n+1);
    for(int i=0; i<k; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        conflicts[tmp1].push_back(tmp2);
        conflicts[tmp2].push_back(tmp1);
    }
}


//check if course a can be assigned to teacher i
bool check(int a, int i){
    if(find(teacher[i].courses.begin(),teacher[i].courses.end(), a) == teacher[i].courses.end()) return false;
    for(int j=0; j < conflicts[a].size(); j++){
        if(courseAssignment[conflicts[a].at(j)] == i) return false;
    }
    return true;
}

void Try(int k){
    for (int i=0; i < m; i++){
        if(check(k, i)){
            courseAssignment[k] = i;
            teacher[i].load++;
            int tmpLoad = maxLoad;
            maxLoad = max(maxLoad, teacher[i].load);

            if(k == n) minSol = min(minSol, maxLoad);
            else{
                if(maxLoad < minSol) Try(k+1);
            }
            teacher[i].load--;
            maxLoad = tmpLoad;
            courseAssignment[k] = -1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    Try(1);
    cout << minSol;
    return 0;
}
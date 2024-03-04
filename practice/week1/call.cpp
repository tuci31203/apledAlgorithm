#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string, int> call, time;
    char act[5], query[23];
    string from, to, date, timeFrom, timeTo, target;
    bool check = true;
    int total = 0;
    cin >> act;
    while(act[0] != '#'){
        cin >> from >> to >> date >> timeFrom >> timeTo;
        call[from]++;
        time[from]+=-((timeFrom[0]*10 + timeFrom[1])*3600 + (timeFrom[3]*10 + timeFrom[4])*60 + timeFrom[6]*10 + timeFrom[7])
                    +((timeTo[0]*10 + timeTo[1])*3600 + (timeTo[3]*10 + timeTo[4])*60 + timeTo[6]*10 + timeTo[7]);
        total ++;
        if(check){
            if(from.length() != 10 || to.length() != 10) check = false;
        }
        cin >> act;
    }
    cin >> query;
    while(query[0] != '#'){
        if(query[8] == 'h') cout << (check ? 1 : 0) << endl;
        else if(query[8] == 't') cout << total << endl;
        else{
            cin >> target;
            if(query[8] == 'c') cout << call[target] << endl;
            else if(query[8] == 'i') cout << time[target] << endl;
        }
        cin >> query;
    }
}
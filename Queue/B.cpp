#include <iostream>
#include <iomanip>
#include <cmath>
#include<stack>
#include<queue>
using namespace std;




int main()
{
    int count;
    cin >> count;
    int count1 = count;
    int A = 0;
    int B = 0;
    int C = 0;
    int Anum = 0;
    int Bnum = 0;
    int Cnum = 0;
    queue<char> type;
    queue<int> time;
    while (count) {
        char ty;
        cin >> ty;
        type.push(ty);
        count--;
    }
    while (count1) {
        int ti;
        cin >> ti;
        time.push(ti);
        count1--;
    }

    while (!type.empty()) {
        switch (type.front()) {
            case 'A': A += time.front();
                Anum++;
                break;
            case 'B': B += time.front();
                Bnum++;
                break;
            case 'C': C += time.front();
                Cnum++;
                break;
        }
        type.pop();
        time.pop();
    }
    if (Anum == 0) {
        Anum = 1;
    }
    if (Bnum == 0) {
        Bnum = 1;
    }
    if (Cnum == 0) {
        Cnum = 1;
    }
    cout << A / Anum << endl;
    cout << B / Bnum << endl;
    cout << C / Cnum << endl;
    return 0;
}
#include <iostream>
#include <iomanip>
#include <cmath>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    queue<int> num;
    queue<int> sta;
    queue<char> s;
    queue<char> n;
    string str;
    cin >> str;
    int* boy;
    int* girl;
    char bogTag = str[0];
    char girlTag = str[str.length()-1];
    boy = new int[str.length() / 2];
    girl = new int[str.length() / 2];
    for (int i = 0; i < str.length(); i++) {
        num.push(i);
        s.push(str[i]);
    }
    int index = 0;
    while (!s.empty() || !n.empty()) {
        char get = s.front();
        int getI = num.front();
        //cout << "取出" << get << endl;
        //cout << "取出" << getI << endl;
        s.pop();
        num.pop();
        if (get == bogTag && s.front() == girlTag) {
            //cout << getI << " " << num.front() << endl;
            boy[index] = getI;
            girl[index] = num.front();
            index++;
            s.pop();
            num.pop();
            while (!num.empty()) {
                sta.push(num.front());
                n.push(s.front());
                s.pop();
                num.pop();
            }
            while (!n.empty()) {
                //cout << "压回" << sta.front() << endl;
                //cout << "压回" << n.front() << endl;
                num.push(sta.front());
                sta.pop();
                s.push(n.front());
                n.pop();
            }
        }
        else {
            sta.push(getI);
            n.push(get);
        }
    }
    int cor = str.length() / 2;
    while (cor) {
        int minI = 0;
        for (int i = 0; i < str.length() / 2; i++) {
            if (girl[i] < girl[minI]) {
                minI = i;
            }
        }
        cout << boy[minI] << " " << girl[minI] << endl;
        girl[minI] = 1000;
        cor--;
    }
    cout << endl;
    return 0;
}
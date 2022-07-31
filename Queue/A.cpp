#include <iostream>
#include <iomanip>
#include <cmath>
#include<stack>
#include<queue>
using namespace std;


void dealInteger(int integer, int number) {
    stack<char> ret;
    while (integer > 0) {
        int result = integer % number;
        integer = integer / number;

        switch (result) {
            case 0: ret.push('0'); break;
            case 1: ret.push('1'); break;
            case 2: ret.push('2'); break;
            case 3: ret.push('3'); break;
            case 4: ret.push('4'); break;
            case 5: ret.push('5'); break;
            case 6: ret.push('6'); break;
            case 7: ret.push('7'); break;
            case 8: ret.push('8'); break;
            case 9: ret.push('9'); break;
            case 10: ret.push('A'); break;
            case 11: ret.push('B'); break;
            case 12: ret.push('C'); break;
            case 13: ret.push('D'); break;
            case 14: ret.push('E'); break;
            case 15: ret.push('F'); break;
        }
    }
    while (!ret.empty()) {
        cout << ret.top();
        ret.pop();
    }
    cout << '.';
}


void dealSmallInteger(double small, int number) {
    stack<char> ret;
    int count = 3;
    int integer;
    while (count) {
        double get = small * number;
        integer = ceil(get);
        if ((get - integer) < 0) {
            integer = integer - 1;
        }
        small = get - integer;
        //cout << small;
        switch (integer) {
            case 0: ret.push('0'); break;
            case 1: ret.push('1'); break;
            case 2: ret.push('2'); break;
            case 3: ret.push('3'); break;
            case 4: ret.push('4'); break;
            case 5: ret.push('5'); break;
            case 6: ret.push('6'); break;
            case 7: ret.push('7'); break;
            case 8: ret.push('8'); break;
            case 9: ret.push('9'); break;
            case 10: ret.push('A'); break;
            case 11: ret.push('B'); break;
            case 12: ret.push('C'); break;
            case 13: ret.push('D'); break;
            case 14: ret.push('E'); break;
            case 15: ret.push('F'); break;
        }
        //cout << integer<<endl;
        //cout << ret.top();
        cout << ret.top();
        count--;
    }
    cout << endl;
}

void sout(double r) {
    cout << fixed << setprecision(3) << r << endl;   //输出小数点后4
    return;
}

int main()
{
    int count;
    cin >> count;
    while (count) {
        double get;
        int number;
        int integer;
        double small;
        stack<int> num;
        queue<int> nu;
        cin >> get;
        cin >> number;

        integer = ceil(get);
        if ((get - integer) < 0) {
            integer = integer - 1;
        }
        small = get - integer;


        //sout(123.456);
        dealInteger(integer,number);
        dealSmallInteger(small, number);
        count--;
    }
    return 0;
}
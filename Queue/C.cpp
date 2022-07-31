#include <iostream>
#include <iomanip>
#include <cmath>
#include<stack>
#include<queue>
using namespace std;

template<class T>

int length(T& arr)
{
    return sizeof(arr) / sizeof(arr[0]);
}

int check(int** data,int number) {
    for (int i = 0; i < 3; i++) {
        for (int a = 0; a < 3; a++) {
            if (data[i][a] == number) {
                //cout << "iss  " << sizeof(data) / sizeof(data[0]) << i<< endl;
                return i;
            }
        }
    }
    return -1;
}

void sout(queue<int>* intQue,int count) {
    for (int i = 0; i < count + 1; i++) {
        if (!intQue[i].empty()) {
            int get = intQue[i].front();
            intQue[i].pop();
            cout << get << " ";
            return;
        }
    }
}

int main()
{
    int count;
    int index = 0;
    cin >> count;
    int cout1 = count;
    int** data = new int* [count];
    while (cout1) {
        int length = 0;
        cin >> length;
        data[index] = new int[length];
        for (int i = 0; i < length; i++) {
            int newInt;;
            cin >> newInt;
            data[index][i] = newInt;
        }
        index++;
        cout1--;
    }
    int sequenceIndex = 0;
    int* sequence = new int[count];
    for (int i = 0; i < count; i++) {
        sequence[i] = -1;
    }
    queue<int>* intQue = new queue<int>[count + 1];
    for (int i = 0; i < count + 1; i++) {
        queue<int> l;
        intQue[i] = l;
    }
    while (true) {
        string x;
        cin >> x;
        if (x == "ENQUEUE") {
            int getNum;
            cin >> getNum;
            //存在返回索引
            int ind = check(data, getNum);
            if (ind == -1) {
                intQue[count].push(getNum);
            }
            else {
                if (sequence[ind] != -1) {
                    intQue[sequence[ind]].push(getNum);
                }
                else {
                    sequence[ind] = sequenceIndex++;
                    intQue[sequence[ind]].push(getNum);
                }
            }
        }
        if (x == "DEQUEUE") {
            sout(intQue,count);
        }
        if (x == "STOP") {
            cout << endl;
            return 0;
        }
    }
}
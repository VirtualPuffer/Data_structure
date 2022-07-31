#include <iostream>
#include <iomanip>
#include <cmath>
#include<stack>
#include<queue>
using namespace std;

int deal(int nowTime, queue<int> reach, queue<int> time, int *window,int win) {
    int indexC = 0;
    for (int i = 0; i < win; i++) {
        //记录最小位置
        if (window[i] < window[indexC]) {
            indexC = i;
        }
    }
    int consume = window[indexC];
    for (int i = 0; i < win; i++) {
        window[i] -= consume;
    }
    window[indexC] = time.front();
    return consume;

}

int main()
{
    int nowTime = 0;
    float use = 0;
    int count;
    int win;
    int maxR = 0;
    cin >> count;
    int cuMax = 0;
    int numC = count;
    queue<int> reach;
    queue<int> time;
    while (count) {
        int rea;
        int ti;
        cin >> rea;
        cin >> ti;
        reach.push(rea);
        time.push(ti);
        count--;
    }
    cin >> win;
    int *window = new int[win];
    for (int i = 0; i < win; i++) {
        window[i] = 0;
    }
    while (!reach.empty()) {
        //时间推移
        int tag = 0;
        //if (reach.front() > nowTime) {
        tag = reach.front() - nowTime;
        for (int i = 0; i < win; i++) {
            window[i] -= tag;
            if (window[i] < 0) {
                window[i] = 0;//防止负数
            }
        }
        //	}
        nowTime = reach.front();
        //轮询队列
        int con = deal(nowTime, reach, time, window, win);
        if (con > cuMax) {
            cuMax = con;
        }
        //时间推移
        nowTime += con;
        use += nowTime - reach.front();
        //cout << "das" << nowTime - reach.front() << endl;
        if (maxR < (nowTime + time.front())) {
            maxR = nowTime + time.front();
        }
        reach.pop();
        time.pop();
    }
    cout << fixed << setprecision(1) << use / numC << ' ';
    cout << cuMax << ' ';
    cout << maxR << endl;
    cin >> nowTime;
    return 0;
}
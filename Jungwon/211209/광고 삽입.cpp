#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

int a[360000], startTime=0;
long long b[360000], maxValue=0;
vector<pair<int, bool> > v;

int toSecond(string time) {
    int h, m, s;
    sscanf(time.c_str(), "%d:%d:%d", &h, &m, &s);
    return h*3600+m*60+s;
}

string toString(int x) {
    string result = "";
    result += (x/10) + '0';
    result += (x%10) + '0';
    return result;
}

string toTimeString(int second) {
    string result = "";
    int h, m, s;
    h = second/3600;
    m = second%3600/60;
    s = second%60;
    result += toString(h) + ":";
    result += toString(m) + ":";
    result += toString(s);
    return result;
}

void f(string log) {
    int h1, m1, s1, h2, m2, s2;
    sscanf(log.c_str(), "%d:%d:%d-%d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
    int start = h1*3600+m1*60+s1;
    int end = h2*3600+m2*60+s2;
    v.push_back(make_pair(start, true));
    v.push_back(make_pair(end, false));
}

string solution(string play_time, string adv_time, vector<string> logs) {
    for (int i=0; i<logs.size(); i++) f(logs[i]);
    sort(v.begin(), v.end());
    int cnt=0, from=0, to;
    for (int i=0; i<v.size(); i++) {
        to = v[i].first;
        for (int j=from+1; j<=to; j++) a[j]=cnt;
        if (v[i].second) cnt++;
        else cnt--;
        from = to;
    }
    int playTime = toSecond(play_time);
    b[0]=a[0];
    for (int i=1; i<=playTime; i++) {
        b[i]=b[i-1]+(long long)a[i];
    }
    int advTime = toSecond(adv_time);
    for (int start=0; start+advTime<=playTime; start++) {
        long long time = b[start+advTime]-b[start];
        if (time>maxValue) {
            maxValue = time;
            startTime = start;
        }
    }
    return toTimeString(startTime);
}
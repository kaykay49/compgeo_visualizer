#include<simplecpp>
#include "button.h"
#include<bits/stdc++.h>
using namespace simplecpp;
double t=0.6;
#define int long long
#define pb push_back
map<pair<int, int>, pair<int, int>> mp;
struct segment {
    int x1;
    int y1;
    int x2;
    int y2;
    segment(int a, int b, int c, int d) { x1 = a; y1 = b; x2 = c; y2 = d; }
    segment() {}
};
int is_left(int x1, int y1, int x2, int y2, int x3, int y3) {
    if ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1) > 0)return 1;
    if ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1) < 0)return -1;
    return 0;
}
int area(int x1, int y1, int x2, int y2, int x3, int y3) {
    return llabs(x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3 + x1 * y2 - x2 * y1);
}
int poi(segment* s) {
    int a1, b1, c1, a2, b2, c2;
    c1 = s[0].x1 - s[1].x1; b1 = s[1].x2 - s[1].x1; a1 = s[0].x1 - s[0].x2;
    c2 = s[0].y1 - s[1].y1; b2 = s[1].y2 - s[1].y1; a2 = s[0].y1 - s[0].y2;
    int d = a1 * b2 - a2 * b1;
    if (d) {
        if (d * (b2 * c1 - b1 * c2) >= 0 && llabs(b2 * c1 - b1 * c2) <= llabs(d) && d * (a1 * c2 - a2 * c1) >= 0 && llabs(a1 * c2 - a2 * c1) <= llabs(d)) {
            return 1;
        }
        else return 0;
    }
    else if (area(s[0].x1, s[0].y1, s[0].x2, s[0].y2, s[1].x1, s[1].y1))return 0;
    else {
        if (max(s[0].x1, s[0].x2) < min(s[1].x1, s[1].x2) || max(s[1].x1, s[1].x2) < min(s[0].x1, s[0].x2))return 0;
        else {
            int x1 = s[0].x1, x2 = s[0].x2, x3 = s[1].x1, x4 = s[1].x2;
            bool b = 0;
            if (x1 > x2) { b = 1; swap(x1, x2); }
            if (x3 > x4) { swap(x3, x4); }
            if (x2 == x3) {
                int a1 = s[0].x2, b1 = s[0].y2;
                if (b) { a1 = s[0].x1; b1 = s[0].y1; }
                return 1;
            }
            else if (x4 == x1) {
                int a1 = s[0].x1, b1 = s[0].y1;
                if (b) { a1 = s[0].x2; b1 = s[0].y2; }
                return 1;
            }
            else if ((x2 < x3) || (x4 < x1)) return 0;
            else return 2;
        }
    }
}
bool in(int x1, int y1, vector<segment> poly) {
    int k = 0;
    for (auto t : poly) {
        segment p = t;
        if (p.y1 == p.y2)continue;
        if (p.y1 > p.y2) { swap(p.x1, p.x2); swap(p.y1, p.y2); }
        if ((y1 - t.y1) * (y1 - t.y2) < 0 && is_left(p.x1, p.y1, p.x2, p.y2, x1, y1) < 0)k++;
        else if (p.y1 == y1 && x1 > p.x1)k++;
    }
    return k % 2;
}
int earfind(vector<pair<int, int>> v) {
    if (v.size() <= 3)return 1000;
    int k = v.size();
    vector<segment> sv;
    for (int i = 0; i < k; i++)sv.pb(segment(6 * v[i].first, 6 * v[i].second, 6 * v[(i + 1) % k].first, 6 * v[(i + 1) % k].second));
    for (int i = 0; i < k; i++) {
        segment s[2];
        s[0] = segment(v[i].first, v[i].second, v[(i + 2) % k].first, v[(i + 2) % k].second);
        bool cut = 0;
        for (int j = 0; j < k; j++) {
            s[1] = segment(sv[j].x1 / 6, sv[j].y1 / 6, sv[j].x2 / 6, sv[j].y2 / 6);
            if (poi(s)==2){cut = 2;break;}
            if(v[j] == v[i] || v[j] == v[(i + 2) % k] || v[(j + 1) % k] == v[i] || v[(j + 1) % k] == v[(i + 2) % k])continue;
            if(poi(s)==1){cut=1;break;}
        }
        if (!cut && in(2*v[i].first+2*v[(i+1)%k].first+2*v[(i+2)%k].first,2*v[i].second+2*v[(i+1)%k].second+2*v[(i+2)%k].second,sv)&&in(3*v[i].first+3*v[(i+2)%k].first,3*v[i].second+3*v[(i+2)%k].second,sv))return i;
    }
    return -1000;
}
signed main(){
    initCanvas("triangulation",1300,750);
    button bt(1200,50,100,50,"start");
    vector<pair<int,int>> v;
    vector<Line> vl;
    while(true){
        int w=getClick();
        if(bt.check_for_click(w/65536,w%65536))break;
        Circle c(w/65536,w%65536,2);
        c.imprint();
        if(!v.empty())vl.pb(Line(v.back().first,-v.back().second,w/65536,w%65536));
        v.pb({w/65536,-w%65536});
    }
    vl.pb(Line(v.back().first,-v.back().second,v[0].first,-v[0].second));
    int n=v.size();
    int tt = n - 3;
    wait(t);
    while (tt--) {
        int x = earfind(v);
        int k = v.size();
        Line l(v[x].first,-v[x].second,v[(x+2)%k].first,-v[(x+2)].second);
        l.imprint();
        wait(t);
        //getClick();
        vector<pair<int, int>> v1 = v;
        v.clear();
        for (int i = 0; i < k; i++) {
            if (i == (x + 1) % k)continue;
            v.pb(v1[i]);
        }
    }
    getClick();
}

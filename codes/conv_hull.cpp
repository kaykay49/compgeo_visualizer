#include<simplecpp>
#include "button.h"
using namespace simplecpp;
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
double t=0.35;
int is_left(int x1, int y1, int x2, int y2, int x3, int y3) {
    if ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1) > 0)return 1;
    if ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1) < 0)return -1;
    return 0;
}
signed main(){
    initCanvas("conv_hull",1300,750);
    button bt(1200,50,100,50,"start");
    map<pair<pair<int,int>,pair<int,int>>,bool> m;
    vector<pair<int, int>> v, l, u;
    vector<Circle> points;
    while(true) {
     int w=getClick();
     if(bt.check_for_click(w/65536,w%65536)){break;}
     v.pb({w/65536,-(w%65536)}); points.pb(Circle(w/65536,(w%65536),2));
     }
    int n=v.size();
    vector<Line> vl;
    sort(v.begin(), v.end());
    u.pb(v[0]); u.pb(v[1]);
    vector<Line> vul,vll;
    vul.pb(Line(v[0].first,-v[0].second,v[1].first,-v[1].second));
    wait(t);
    for (int i = 2; i < n; i++) {
        //cout<<u.back().first<<" "<<u.back().second<<'\n';
        while (u.size() >= 2 && is_left(u[u.size() - 2].first, u[u.size() - 2].second, u[u.size() - 1].first, u[u.size() - 1].second, v[i].first, v[i].second) >= 0) {
            u.pop_back();
            vul.back().hide();
            vul.pop_back();
            wait(t);
        }
        if(!u.empty())vul.pb(Line(u.back().first,-u.back().second,v[i].first,-v[i].second));
        wait(t);
        u.pb(v[i]);
    }
    int su=u.size();
    for(int i=0;i<su;i++){m[{u[i],u[(i+1)%su]}]=1;}
    //reverse(v.begin(),v.end());
    l.pb(v[0]); l.pb(v[1]);
    vll.pb(Line(v[0].first,-v[0].second,v[1].first,-v[1].second));
    wait(t);
    for (int i = 2; i < n; i++) {
        while (l.size() >= 2 && is_left(l[l.size() - 2].first, l[l.size() - 2].second, l[l.size() - 1].first, l[l.size() - 1].second, v[i].first, v[i].second) <= 0) {
            //cout<<"hello\n";
            if(!m[{l.back(),l[l.size()-2]}]&&!m[{l[l.size()-2],l.back()}]){vll.back().hide();}
            l.pop_back();
            vll.pop_back();
            wait(t);
        }
        if(!l.empty())vll.pb(Line(l.back().first,-l.back().second,v[i].first,-v[i].second));
        l.pb(v[i]);
        wait(t);
    }
    getClick();
    return 1;
    //cout<<l.size()<<u.size()<<'\n';
}

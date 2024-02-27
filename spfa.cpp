/*
 * @Author: your name
 * @Date: 2023-03-27 11:42:19
 * @LastEditTime: 2023-03-27 11:50:56
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /CSS449/spfa.cpp
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5+10;

int n, m;
int dist[N];
bool st[N];
int idx, h[N], e[N], ne[N], w[N];


void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa(){
    memset(dist, -1, sizeof dist);

    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while(q.size()){
        auto t = q.front();
        q.pop();
        st[t] = false;

        for(int i = h[t]; i != -1; i = ne[i]){
            auto j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                if(!st[j]){
                    q.push(j);
                    st[j] = true;

                }
            }
        }
    }
    return dist[n];
}

int main(){
    scanf("%d%d", &n, &m);
    
    memset(h, -1, sizeof h);

    while(m --){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    int t = spfa();
    if(t == 0x3f3f3f3f) puts("impossible");
    else printf("%d", t);
    return 0;
}
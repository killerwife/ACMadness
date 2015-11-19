//split
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
#define MAXN 10000

char ch[MAXN] , Ch[MAXN];
int  w[20];
int  C , k;

//
inline int Min(int a , int b){
    return a < b ? a : b;
}

//C
void solve() {
    for (int i = 0 ; i < k ; i++) {
        for (int j = i + 1 ; j < k ; j++) {
            if ((C/w[i])%k == (C/w[j])%k){
                C = Min((C/w[i]+1)*w[i] , (C/w[j]+1)*w[j]);
                solve();//
                return;//C
            }
        }
    }
}

//
int main() {
    //freopen("input.txt" , "r" , stdin);
    int i , t;
    while (gets(ch)) {
        memcpy(Ch , ch , sizeof(ch));
        memset(w, 0, sizeof (w));
        const char* split = " " ; char *p;
        p = strtok(ch, split);
        int len = strlen(p);
        for (k = 0,i = 0; i < len; i++) {
            t = p[i] - 'a' + 1;
            w[k] += t * pow(32, len - 1 - i);
        }
        k++;
        while (p != NULL) {
            p = strtok(NULL, split);
            if (p == NULL) break;
            int len = strlen(p);
            for (i = 0; i < len; i++) {
                t = p[i] - 'a' + 1;
                w[k] += t * pow(32, len - 1 - i);
            }
            k++;
        }
        sort(w, w + k);
        C = 1 ; solve();//C1?0
        printf("%s\n" , Ch);
        printf("%d\n\n" , C);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, W;
    int pd[2667];
    int v[2667], w[2667];
    scanf("%d%d", &N, &W);
    for(int i = 0; i < N; i++) scanf("%d%d", w+i, v+i);
    for(int j = 0; j <= W; j++) pd[j] = 0;

    for(int i = 0; i < N; i++)
        for(int j = W; j >= w[i]; j--)
            pd[j] = max(pd[j], pd[j-w[i]] + v[i]);
    printf("%d\n", pd[W]);
    return 0;
}
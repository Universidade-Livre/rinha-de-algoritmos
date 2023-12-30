#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int T[3030];

int main() {
    int N, W;
    scanf("%d %d", &N, &W);
    T[0] = 1;
    for(int i=0; i<N; i++) {
        int wi, vi; 
        scanf("%d %d", &wi, &vi);
        for(int j=W - wi; j>=0; j--) {
            if (T[j] <= 0) continue;
            if (T[j] + vi > T[j + wi])
                T[j + wi] = T[j] + vi;
        }
    }
    printf("%d\n", *max_element(T, T+W+1)-1);
}
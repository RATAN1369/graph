#include <bits/stdc++.h>
using namespace std;

int n, set_size;
int *parent, *rank_;
//final TC -> O(alpha(n))==O(1)
void init(int a) {
    n = set_size = a;
    parent = new int[n + 1];
    rank_ = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank_[i] = 1;
    }
}

 int find(int x) {
    if (x != parent[x])
        parent[x] = find(parent[x]);//path compression 
    return parent[x];
}

void merge(int x, int y) {
    int xcur = find(x), ycur = find(y);
    if (xcur == ycur) return;
    if (rank_[xcur] >= rank_[ycur]) {
        parent[ycur] = xcur;
        rank_[xcur] += rank_[ycur];
    } else {
        parent[xcur] = ycur;
        rank_[ycur] += rank_[xcur];
    }
    set_size--;
}

void reset() {
    set_size = n;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank_[i] = 1;
    }
}

int size() {
    return set_size;
}

void print() {
    for (int i = 1; i <= n; i++) {
        cout << i << " -> " << parent[i] << endl;
    }
}

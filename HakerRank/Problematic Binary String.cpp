#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

long long count_nodes[4 * MAXN]; 
long long sum_nodes[4 * MAXN];   
bool lazy[4 * MAXN];             

long long prefix_sum_indices[MAXN];

string s;
int n;


long long range_idx_sum(int L, int R) {
    if (L > R) return 0;
    return prefix_sum_indices[R] - prefix_sum_indices[L - 1];
}


void push(int u, int L, int R) {
    if (lazy[u]) {
        long long num_elements = R - L + 1;
        count_nodes[u] = num_elements - count_nodes[u];
        sum_nodes[u] = range_idx_sum(L, R) - sum_nodes[u];

        if (L != R) {
            lazy[2 * u] = !lazy[2 * u];
            lazy[2 * u + 1] = !lazy[2 * u + 1];
        }

        lazy[u] = false;
    }
}

void merge(int u) {
    count_nodes[u] = count_nodes[2 * u] + count_nodes[2 * u + 1];
    sum_nodes[u] = sum_nodes[2 * u] + sum_nodes[2 * u + 1];
}


void build(int u, int L, int R) {
    if (L == R) {
        if (s[L - 1] == '1') {
            count_nodes[u] = 1;
            sum_nodes[u] = L;
        } else {
            count_nodes[u] = 0;
            sum_nodes[u] = 0;
        }
        return;
    }
    int mid = L + (R - L) / 2;
    build(2 * u, L, mid);
    build(2 * u + 1, mid + 1, R);
    merge(u);
}


void update(int u, int L, int R, int l, int r) {
    push(u, L, R); 
    if (L > r || R < l) {
        return;
    }

    
    if (L >= l && R <= r) {
        lazy[u] = !lazy[u];
        push(u, L, R);      
        return;
    }

    int mid = L + (R - L) / 2;
    update(2 * u, L, mid, l, r);
    update(2 * u + 1, mid + 1, R, l, r);

    merge(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;

    for (int i = 1; i <= n; ++i) {
        prefix_sum_indices[i] = prefix_sum_indices[i - 1] + i;
    }

    build(1, 1, n);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        update(1, 1, n, l, r);

    
        long long k = count_nodes[1];
        long long S = sum_nodes[1];

       
        long long triangular_k = k * (k + 1) / 2;

        
        cout << S - triangular_k << "\n";
    }

    return 0;
}


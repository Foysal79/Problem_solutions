#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG = (ll)-4e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if(!(cin>>T)) return 0;
    while(T--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<int>> g(n);
        for(int i=0;i<m;i++){
            int u,v; cin>>u>>v; --u; --v;
            g[u].push_back(v);
        }

        vector<int> disc(n,-1), low(n), stck_id(n,-1);
        vector<int> st;
        int timer=0, compCnt=0;
        vector<int> comp_of(n,-1);
        function<void(int)> dfs = [&](int u){
            disc[u]=low[u]=timer++;
            st.push_back(u);
            stck_id[u]=1;
            for(int v: g[u]){
                if(disc[v]==-1){
                    dfs(v);
                    low[u]=min(low[u], low[v]);
                } else if(stck_id[v]){
                    low[u]=min(low[u], disc[v]);
                }
            }
            if(low[u]==disc[u]){
                while(true){
                    int v = st.back(); st.pop_back();
                    stck_id[v]=0;
                    comp_of[v]=compCnt;
                    if(v==u) break;
                }
                compCnt++;
            }
        };
        for(int i=0;i<n;i++) if(disc[i]==-1) dfs(i);

        vector<ll> w(compCnt,0);
        for(int i=0;i<n;i++) w[comp_of[i]]++;
        vector<vector<int>> adj(compCnt);
        vector<unordered_set<int>> used(compCnt);
        for(int u=0; u<n; ++u){
            int cu = comp_of[u];
            for(int v: g[u]){
                int cv = comp_of[v];
                if(cu!=cv && !used[cu].count(cv)){
                    adj[cu].push_back(cv);
                    used[cu].insert(cv);
                }
            }
        }

        vector<int> indeg(compCnt,0);
        for(int u=0;u<compCnt;u++)
            for(int v: adj[u]) indeg[v]++;
        queue<int>q;
        for(int i=0;i<compCnt;i++) if(indeg[i]==0) q.push(i);
        vector<int> topo;
        topo.reserve(compCnt);
        while(!q.empty()){
            int u=q.front(); q.pop();
            topo.push_back(u);
            for(int v: adj[u]){
                if(--indeg[v]==0) q.push(v);
            }
        }

        int K = min(k, compCnt);
        vector<vector<ll>> dp(compCnt, vector<ll>(K+1, NEG));
        for(int u=0; u<compCnt; ++u) dp[u][1] = w[u];

       
        for(int idx = (int)topo.size()-1; idx>=0; --idx){
            int u = topo[idx];
            for(int t=2; t<=K; ++t){
                ll best = NEG;
                for(int v: adj[u]) if(dp[v][t-1] > NEG/2) best = max(best, dp[v][t-1]);
                if(best > NEG/2) dp[u][t] = max(dp[u][t], w[u] + best);
            }
        }

        ll ans = 0;
        for(int u=0; u<compCnt; ++u)
            for(int t=1; t<=K; ++t)
                if(dp[u][t] > ans) ans = dp[u][t];

        cout << ans << '\n';
    }
    return 0;
}

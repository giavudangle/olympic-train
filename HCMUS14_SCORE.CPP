#include <bits/stdc++.h>

using namespace std;

const int INF = 10e8;


vector<vector<int>> adj;
vector<vector<int>> cap;
vector<int> sinklist;
vector<bool> marked;
vector<int> previous;
int totalFlow, flow;
int numberOfVertices;
int n, p;
int source, sink;

void updateFlowAugmentingPath(int source, int sink) {
    int prev,next;
    next = sink;
    flow = INF;
    while(previous[next] > -1){
        prev = previous[next];
        flow = min(flow, cap[prev][next]);
        next = prev;
    }
    next = sink;
    while(previous[next] > -1){
        prev = previous[next];
        cap[prev][next] -= flow;
        cap[next][prev] += flow;
        next = prev;
    }
}

bool findAugmentingPath(int source, int sink){
    queue<int> q;
    q.push(source);
    previous = vector<int>(numberOfVertices, -1);
    marked = vector<bool>(numberOfVertices, false);
    marked[source]=true;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int i=0; i < (int) adj[v].size(); i++){
            int u = adj[v][i];
            if(!marked[u] and cap[v][u]>0){
                marked[u] = true;
                previous[u] = v;
                if (u == sink) continue;
                q.push(u);
            }
        }
    }
    return previous[sink] != -1;
}

int maxFlow(int source, int sink){
    totalFlow = 0;
    sinklist = adj[sink];
    while(findAugmentingPath(source,sink)){
        for(int i = 0; i < (int) sinklist.size(); i++){
            int u = sinklist[i];
            if(!marked[u] || cap[u][sink] <=0)
                continue;
            previous[sink] = u;
            updateFlowAugmentingPath(source, sink);
            totalFlow += flow;
        }
    }
    return totalFlow;
}

void addEdge(int u, int v, int c) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    cap[u][v] = c;
    cap[v][u] = 0;
}


int main(int argc, char const* argv[])
{
    cin >> n >> p;
    numberOfVertices = n + p + 2;
    source = numberOfVertices - 2;
    sink = numberOfVertices - 1;
    cap = vector<vector<int>>(numberOfVertices, vector<int>(numberOfVertices, 0));
    adj = vector<vector<int>>(numberOfVertices);
    int sumRow = 0;
    int sumCol = 0;
    vector<int> row(n);
    vector<int> col(p);

    for (int i = 0; i < n; i++) {
        cin >> row[i];
        sumRow += row[i];
        addEdge(source, i, row[i]);
    }

    for (int i = 0; i < p; i++) {
        cin >> col[i];
        sumCol += col[i];
        addEdge(i + n, sink, col[i]);
    }

    if (sumRow != sumCol) {
        cout << "Impossible";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            addEdge(i, n + j, 1);
        }
    }

    maxFlow(source, sink);

    if (totalFlow != sumCol) {
        cout << "Impossible";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int  j = 0; j < p; j++) {
            int val = cap[j+n][i];
            cap[i][j+n] = cap[j+n][i] = 0;
            if (val != 0) {
                cap[source][i] = cap[j+n][sink] = 1;
                if (findAugmentingPath(source, sink)) {
                    updateFlowAugmentingPath(source, sink);
                    val = 0;
                } else {
                    cap[source][i] = cap[j+n][sink] = 0;
                }
            }
            if (val == 1) cout << 'Y';
            else cout << 'N';
        }
        cout << '\n';

    }

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<pair<int,int>> toEdges[100000], fromEdges[100000];

void dijkstra(long long dist[], vector<pair<int,int>> edges[]) {
  priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> queue;
  dist[0] = 0;
  for (int i = 1; i < N; i++) dist[i] = 2e9;
  queue.emplace(0, 0);
  while (!queue.empty()) {
    auto [d, a] = queue.top();
    queue.pop();
    if (d > dist[a]) continue;
    for (auto [b, c] : edges[a]) {
      if (dist[b] > dist[a] + c) {
        dist[b] = dist[a] + c;
        queue.emplace(dist[b], b);
      }
    }
  }
}

int main() {
  int M, a, b, c;
  long long T, A[100000], to[100000], from[100000];
  cin >> N >> M >> T;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int j = 0; j < M; j++) {
    cin >> a >> b >> c;
    toEdges[a-1].push_back({b-1, c});
    fromEdges[b-1].push_back({a-1, c});
  }
  dijkstra(to, toEdges);
  dijkstra(from, fromEdges);
  long long money = 0;
  for (int i = 0; i < N; i++) {
    long long time = T - to[i] - from[i];
    money = max(money, time * A[i]);
  }
  cout << money << endl;
  return 0;
}

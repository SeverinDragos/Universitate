#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  ifstream fin ("graf.in");
  if (!fin.is_open())  cout << "Eroare la deschiderea fisierului!" << endl;

  int n, m, s, u ,v, cost;
  fin >> n >> m;
  int* d = new int [n + 1];
  int* tata = new int [n + 1];
  int* viz = new int [n + 1];
  vector <pair<int, int> > a[n + 1]; // lista ponderata de adiacenta
  priority_queue <pair<int, int> > Q;

  for (int i = 0; i < m; i++) {
    fin >> u >> v >> cost;
    a[u].push_back(make_pair(cost, v));
    a[v].push_back(make_pair(cost, u));
  }
  fin >> s;
  //Initializare
  for (int i = 1; i <= n; i++) {
    d[i] = INT_MAX;
    tata[i] = 0;
    viz[i] = 0;
  }

  //Incepem cu s
  d[s] = 0;
  Q.push(make_pair(0, s));

  //Implementare
  while (!Q.empty()) { //De n-1 ori (Ma rog, nu prea, cu set poate)
    u = Q.top().second;
    Q.pop();
    viz[u] = 1;
    for (int i = 0; i < a[u].size(); i++) {
      v = a[u][i].second;
      cost = a[u][i].first;
      if (viz[v] == 0)
        if (cost < d[v]) {
          d[v] = cost;
          tata[v] = u;
          Q.push(make_pair(-cost, v));
        }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (tata[i] != 0)
    cout << i << ": " << d[i] << "/" << tata[i] << endl;
  }

  delete []d;
  delete []tata;
  delete []viz;
  fin.close();
  return 0;
}


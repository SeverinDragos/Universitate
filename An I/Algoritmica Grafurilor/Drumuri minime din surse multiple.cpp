#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  ifstream fin ("graf.in");
  if (!fin.is_open())  cout << "Eroare la deschiderea fisierului!" << endl;

  int n, m, u, v, cost, k;
  fin >> n >> m >> k;
  n++; /// Sursa
  int* d = new int [n + 1];
  int* tata = new int [n + 1];
  int* fortarete = new int [k];
  vector <pair<int, int> > a[n + 1]; // lista ponderata de adiacenta
  priority_queue <pair<int, int> > Q;

  for (int i = 0; i < k; i++) {
    fin >> u;
    fortarete[i] = u + 1;
    a[1].push_back(make_pair(0, fortarete[i]));
    a[fortarete[i]].push_back(make_pair(0, 1));
  }

  for (int i = 0; i < m; i++) {
    fin >> u >> v >> cost;
    a[u + 1].push_back(make_pair(cost, v + 1));
    a[v + 1].push_back(make_pair(cost, u + 1));
  }

  //Initializare
  for (int i = 1; i <= n; i++) {
    d[i] = INT_MAX;
    tata[i] = 0;
  }

  //Incepem cu s
  d[1] = 0;
  Q.push(make_pair(0, 1));

  //Implementare
  while (!Q.empty()) { //De n-1 ori
    u = Q.top().second;
    Q.pop();
    for (int i = 0; i < a[u].size(); i++) {
      v = a[u][i].second;
      cost = a[u][i].first;
        if (d[u] + cost < d[v]) {
          d[v] = d[u] + cost;
          tata[v] = u;
          Q.push(make_pair(-cost, v));
        }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << i << ": " << d[i] << "|" << tata[i] << endl;
  }

  delete []fortarete;
  delete []tata;
  delete []d;
  fin.close();
  return 0;
}


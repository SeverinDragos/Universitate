#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  ifstream fin ("graf.in");
  if (!fin.is_open())  cout << "Eroare la deschiderea fisierului!" << endl;

  int n, m, u, v, inc = 0, s, cost, j;
  fin >> n >> m;
  int* d_intern = new int [n + 1];
  int* Sort_Top = new int [n + 1];
  int* d = new int [n + 1];
  int* tata = new int [n + 1];
  vector <pair <int, int> > a[n + 1];
  queue <int> coada;


  for (int i = 0; i <= n; i++) {
    d_intern[i] = 0;
  }

  for (int i = 0; i < m; i++) {
    fin >> u >> v >> cost;
    a[u].push_back(make_pair(cost, v));
    d_intern[v]++;
  }

  //Initializare pt Sortare Topologica
  for (int i = 1; i <= n; i++) {
    if (d_intern[i] == 0)
      coada.push(i);
  }

  //Implementare Sortare Topologica
  while (!coada.empty()) {
    u = coada.front();
    coada.pop();
    Sort_Top[inc++] = u;
    for (int i = 0; i < a[u].size(); i++) {
      v = a[u][i].second;
      d_intern[v]--;
      if (d_intern[v] == 0)
        coada.push(v);
    }
  }

  //Afisare Sortare Topologica
  for (int i = 0; i < n; i++) {
    cout << Sort_Top[i] << " ";
  }
  cout << endl;

  fin >> s; //sursa (varful de start)

  //Initializare
  for (int i = 0; i <= n; i ++) {
    d[i] = 999999999;
    tata[i] = 0;
  }
  d[s] = 0;

  //Ignorarea varfurilor neaccesibile din s
  for (j = 0; j < n; j++) {
    if (Sort_Top[j] == s)
      break;
  }

  //Implementare DAG
  for (; j <= n; j++) {
    u = Sort_Top[j];
    for (int i = 0; i < a[u].size(); i++) {
      v = a[u][i].second;
      cost = a[u][i].first;
      if (d[u] + cost < d[v]) {
        d[v] = d[u] + cost;
        tata[v] = u;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (tata[i] != 0)
      cout << i << ": " << d[i] << "|" << tata[i] << endl;
  }

  delete []d_intern;
  delete []Sort_Top;
  delete []d;
  delete []tata;
  fin.close();
  return 0;
}


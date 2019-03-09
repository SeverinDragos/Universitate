
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

void drum (int i, int* tata) {
  if (tata[i] != 0)
    drum(tata[i], tata);
  cout << i << " ";
}

int main()
{
  ifstream fin ("graf.in");
  if (!fin.is_open())  cout << "Eroare la deschiderea fisierului!" << endl;

  int n, m, s, u ,v, cost, k;
  fin >> n >> m;
  int* d = new int [n + 1];
  int* tata = new int [n + 1];
  vector <pair<int, int> > a[n + 1]; // lista ponderata de adiacenta
  priority_queue <pair<int, int> > Q;

  for (int i = 0; i < m; i++) {
    fin >> u >> v >> cost;
    a[u].push_back(make_pair(cost, v));
    a[v].push_back(make_pair(cost, u));
  }

  //Initializare
  for (int i = 1; i <= n; i++) {
    d[i] = 999999;
    tata[i] = 0;
  }
  cin >> k;

  int* puncte_control = new int [k];
  for (int i = 0; i < k; i++) {
    cin >> puncte_control[i];
  }

  cin >> s;
  //Incepem cu s
  d[s] = 0;
  Q.push(make_pair(0, s));

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

  int closest, dist = 999999;
  for (int i = 0; i < k; i++) {
    if (d[puncte_control[i]] < dist) {
      dist = d[puncte_control[i]];
      closest = puncte_control[i];
    }
  }

  cout << "Cel mai apropiat punct de control se afla la distanta de : " << d[closest] << endl;
  cout << "Lant minim: ";
  drum(closest, tata);

  delete []tata;
  delete []d;
  fin.close();
  return 0;
}


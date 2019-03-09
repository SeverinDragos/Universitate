#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int flux[100][100], capacitate[100][100];

int BF(int s, int* tata, int* viz, vector <int> l[], vector <int> lin[], int n) {
  memset(tata, 0, sizeof(int) * (n + 1));
  memset(viz, 0, sizeof(int) * (n + 1));
  queue <int> Q;
  int u, v;
  Q.push(s);
  viz[s] = 1;
  while (!Q.empty()) {
    u = Q.front();
    Q.pop();
    for (int i = 0; i < l[u].size(); i++) { /// Pe listele de intrare
      v = l[u][i];
      if (viz[v] == 0 && capacitate[u][v] - flux[u][v] > 0) {
        tata[v] = u;
        if (v == n)  return 1;
        Q.push(v);
        viz[v] = 1;
      }
    }
    for (int i = 0; i < lin[u].size(); i++) { /// Pe listele de iesire (arce inverse)
      v = lin[u][i];
      if (viz[v] == 0 && flux[v][u] > 0) {
        tata[v] = -u;
        if (v == n)  return 1;
        Q.push(v);
        viz[v] = 1;
      }
    }
  }
  return 0;
}

int main()
{
  ifstream fin ("maxflow.in");
  if (!fin.is_open())  cout << "Eroare la deschiderea fisierului!" << endl;

  int n, m, x, y, cost;
  fin >> n >> m;
  int* tata = new int [n + 1];
  int* viz = new int [n + 1];
  vector <int> l[n + 1];
  vector <int> lin[n + 1];

  for (int i = 0; i < m; i++) {
    fin >> x >> y >> cost;
    l[x].push_back(y);
    lin[y].push_back(x);
    flux[x][y] = 0;
    capacitate[x][y] = cost;
  }
  int s = 1, t = n, fmax = 0, iP;
  while (BF(1,tata,viz,l,lin,n) == 1) { ///Cat timp nu ne blocam (nu am ajuns la taietura minima)
    iP = 999999;
    t = n;
    ///Determinare iP (capacitatea reziduala)
    cout << "Lantul din BF la pasul asta: " << endl;
    while (t!=s) {
      cout << t << " ";
      if (tata[t] > 0) {
        iP = min(iP, capacitate[tata[t]][t] - flux[tata[t]][t]);
        t = tata[t];
      }
      else {
        iP = min(iP, flux[t][-tata[t]]);
        t = - tata[t];
      }
    }
    cout << s << " capacitate reziduala: " << iP << endl;
    ///Revizuire flux
    t = n;
    while (t!=s) {
      if (tata[t] > 0) {
        flux[tata[t]][t] += iP;
        t = tata[t];
      }
      else {
        flux[t][-tata[t]] -= iP;
        t = -tata[t];
      }
    }
    fmax += iP;
  }

  cout << endl << "Valoarea fluxului maxim: " << fmax << endl;
  cout << "Un flux maxim:" << endl;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < l[i].size(); j++) {
      cout << "Arcul " << i << " " << l[i][j] << " flux: " << flux[i][l[i][j]] << endl;
    }
  }

  cout << "Taietura minima: " << endl;

  for (int i = 1; i < n; i++) {
    if (viz[i] == 1)
      cout << i << " ";
  }
  cout << "/ ";
  for (int i = 1; i < n; i++) {
    if (viz[i] == 0)
      cout << i << " ";
  }

  delete []tata;
  delete []viz;
  fin.close();
  return 0;
}

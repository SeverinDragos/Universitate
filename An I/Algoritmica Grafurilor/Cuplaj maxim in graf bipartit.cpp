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

int BF_colorare(int s, int* culoare, vector <int> l[], int n) {
  memset(culoare, -1, sizeof(int) * (n + 1) );
  queue <int> Q;
  int u, v;
  Q.push(s);
  culoare[s] = 1;
  while (!Q.empty()) {
    u = Q.front();
    Q.pop();
    for (int i = 0; i < l[u].size(); i++) {
      v = l[u][i];
      if (culoare[v] == -1) {
        (culoare[u] == 1) ? culoare[v] = 2 : culoare[v] = 1;
        Q.push(v);
      }
      else
        if (culoare[u] == culoare[v])
          return 0;
    }
  }
  return 1;
}

int main()
{
  ifstream fin ("graf.in");
  if (!fin.is_open())  cout << "Eroare la deschiderea fisierului!" << endl;

  int n, m, x, y;
  fin >> n >> m;
  n += 2; ///Sursa si destinatia
  int* tata = new int [n + 1];
  int* viz = new int [n + 1];
  int* culoare = new int [n + 1];
  vector <int> l[n + 1];
  vector <int> lin[n + 1];

  for (int i = 0; i < m; i++) {
    fin >> x >> y;
    l[x + 1].push_back(y + 1);
    l[y + 1].push_back(x + 1);
    capacitate[x + 1][y + 1] = 1;
    capacitate[y + 1][x + 1] = 1;
  }

  if (!BF_colorare(2, culoare, l, n)) {
    cout << "Graful nu este bipartit" << endl;
    return 0;
  }

  for (int u = 2; u < n; u++) {
    if (culoare[u] == 2) {
      for (int i = 0; i < l[u].size(); i++) {
        lin[u].push_back(l[u][i]);
        capacitate[u][l[u][i]] = 0;
      }
      l[u].clear();
      l[u].push_back(n);
      lin[n].push_back(u);
      capacitate[u][n] = 1;
    }
  }

  for (int u = 2; u < n; u++)
    if (culoare[u] == 1) {
      l[1].push_back(u);
      lin[u].push_back(1);
      capacitate[1][u] = 1;
    }

  int s = 1, t = n, fmax = 0, iP;

  while (BF(1,tata,viz,l,lin,n) == 1) { ///Cat timp nu ne blocam (nu am ajuns la taietura minima)
    iP = 999999;
    t = n;
    ///Determinare iP (capacitatea reziduala)
    while (t!=s) {
    //  cout << t << " ";
      if (tata[t] > 0) {
        iP = min(iP, capacitate[tata[t]][t] - flux[tata[t]][t]);
        t = tata[t];
      }
      else {
        iP = min(iP, flux[t][-tata[t]]);
        t = - tata[t];
      }
    }
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

  for (int i = 2; i < n; i++) {
    for (int j = 0; j < l[i].size(); j++) {
      if (flux[i][l[i][j]] == 1 && l[i][j] != n)
      cout << i - 1 << " " << l[i][j] - 1 << endl;
    }
  }

  delete []tata;
  delete []viz;
  delete []culoare;
  fin.close();
  return 0;
}

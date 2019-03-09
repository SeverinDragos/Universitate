#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;


int BF(int s, int* viz, int* tata, vector <int> li[], int n) {
  memset(viz, 0, sizeof(int) * (n + 1));
  memset(tata, 0, sizeof(int) * (n + 1));
  queue <int> Q;
  Q.push(s);
  viz[s] = 1;
  int ultim;
  while (!Q.empty()) {
  int u = Q.front();
  ultim = u;
  Q.pop();
    for (int i = 0; i < li[u].size(); i++) {
      int v = li[u][i];
      if (viz[v] == 0) {
        Q.push(v);
        viz[v] = 1;
        tata[v] = u;
      }
    }
  }
  return ultim;
}

int main()
{
  ifstream fin ("graf.in");
  if (!fin.is_open())  cout << "Eroare la deschiderea fisierului!" << endl;

  int n, m, x, y;
  fin >> n >> m;

  int* tata = new int [n + 1];
  int* viz = new int [n + 1];
  int* excentricitate = new int [n + 1];
  vector <int> li[n + 1];
  memset(excentricitate, 0, sizeof(int) * (n + 1));

  for (int i = 0; i < m; i++) {
    fin >> x >> y;
    li[x].push_back(y);
    li[y].push_back(x);
  }

  for (int i = 1; i <= n; i++) {
    int ultim = BF(i, viz, tata, li, n);
    while (ultim != i) {
      excentricitate[i]++;
      ultim = tata[ultim];
    }
  }

  int diam = 0, raza = 999999, min;
  vector <int> centru;
  for (int i = 1; i <= n; i++) {
    if (excentricitate[i] > diam)
      diam = excentricitate[i];
    if (excentricitate[i] < raza)
      raza = excentricitate[i];
  }

  for (int i = 1; i <= n; i++) {
    if (excentricitate[i] == raza)
      centru.push_back(i);
  }

  cout << "Diametru: " << diam << endl << "Raza: " << raza << endl << "Centru: ";
  for (int i = 0; i < centru.size(); i++)
    cout << centru[i] << " ";
  cout << endl;

  delete []excentricitate;
  delete []viz;
  delete []tata;
  fin.close();
  return 0;
}

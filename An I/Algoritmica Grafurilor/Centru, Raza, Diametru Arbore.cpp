#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;


int BF(int s, int* tata, int* viz, vector <int> li[], int n) {
  memset(tata, 0, sizeof(int) * (n + 1));
  memset(viz, 0, sizeof(int) * (n + 1));
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
  fin >> n;

  int* tata = new int [n + 1];
  int* viz = new int [n + 1];
  vector <int> li[n + 1];

  for (int i = 0; i < n - 1; i++) {
    fin >> x >> y;
    li[x].push_back(y);
    li[y].push_back(x);
  }

  int u = BF(1, tata, viz, li, n);/// Cel mai departat de 1, de la el incepem

  int v = BF(u, tata, viz, li, n);/// Cel mai departat de u

  int diam = 0, parcurg = v;
  while (parcurg != u) {
    diam++;
    parcurg = tata[parcurg];
  }
  int raza = (diam + 1) / 2;
  cout << "Diametrul: " << diam << endl;
	cout << "Raza: " << raza << endl;
	cout << "Centrul: ";

	parcurg = v;
  if (diam % 2 == 0) {
    for (int i = 0; i < raza; i++) {
      parcurg = tata[parcurg];
    }
    cout << parcurg << endl;
  }
  else {
    for (int i = 0; i < raza - 1; i++) {
      parcurg = tata[parcurg];
    }
    cout << parcurg << " " << tata[parcurg] << endl;
  }


  //cout << "Diametrul: " << diametru << endl << "Raza: " << raza << endl << "Centrul: " << centru << endl;

  delete []viz;
  delete []tata;
  fin.close();
  return 0;
}

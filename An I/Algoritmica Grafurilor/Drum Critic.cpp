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

  int n, m, u, v, inc = 0, cost;
  fin >> n;
  int* d_intern = new int [n + 1];
  int* Sort_Top = new int [n + 1];
  int* d = new int [n + 1];
  int* tata = new int [n + 1];
  int* ponderi = new int [n + 1];
  vector <pair <int, int> > a[n + 1];
  queue <int> coada;


  for (int i = 1; i <= n; i++) {
    d_intern[i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    fin >> ponderi[i];
  }

  fin >> m;

  for (int i = 0; i < m; i++) {
    fin >> u >> v;
    a[u].push_back(make_pair(ponderi[u], v));
    d_intern[v]++;
  }

  //Initializare DAG
  for (int i = 1; i <= n; i ++) {
    d[i] = -999999999;
    tata[i] = 0;
  }

  //Initializare pt Sortare Topologica
  for (int i = 1; i <= n; i++) {
    if (d_intern[i] == 0) {
      coada.push(i);
      d[i] = 0;
    }
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
  /*for (int i = 0; i < n; i++) {
    cout << Sort_Top[i] << " ";
  }
  cout << endl;*/

  //Implementare DAG
  for (int j = 0; j <= n; j++) {
    u = Sort_Top[j];
    for (int i = 0; i < a[u].size(); i++) {
      v = a[u][i].second;
      cost = a[u][i].first;
      if (d[u] + cost > d[v]) {
        d[v] = d[u] + cost;
        tata[v] = u;
      }
    }
  }

  int timp_desfasurare = 0, ultimul;
  for (int i = 1; i <= n; i++) {
    if (d[i] + ponderi[i] > timp_desfasurare) {
      timp_desfasurare = d[i] + ponderi[i];
      ultimul = i;
    }
  }

  cout << "Timp minim: " << timp_desfasurare << endl;
  cout << "Activitati critice: ";
  drum(ultimul, tata);
  cout << endl;

  for (int i = 1; i <= n; i++) {
    cout << i << ": " << d[i] << " " << d[i] + ponderi[i] << endl;
  }

  //Afisare vector de tati
  /*for (int i = 1; i <= n; i++) {
    if (tata[i] != 0)
      cout << i << ": " << d[i] << "|" << tata[i] << endl;
  }*/

  delete []d_intern;
  delete []Sort_Top;
  delete []d;
  delete []tata;
  delete []ponderi;
  fin.close();
  return 0;
}


#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue>

using namespace std;

struct Activitate {
  int profit, termen, indice_initial;
  bool operator<(const Activitate& ob) const {
    return profit < ob.profit;
  }
};

bool Comparare (struct Activitate& a, struct Activitate& b) {
  return  a.termen > b.termen;
}

int main()
{
  ifstream fin ("profit-termen limita.in");
  ofstream fout ("profit-termen limita.out");

  int n;
  fin >> n;
  struct Activitate v[n];
  int sol[n];
  fill_n(sol, n, 0);
  for (int i = 0; i < n; i++) {
    fin >> v[i].profit >> v[i].termen;
    v[i].indice_initial = i + 1;
  }

  sort(v, v + n, Comparare);

  for (int i = 0; i < n; i++) {
    cout << v[i].profit << " " << v[i].termen << endl;
  }

  ///Metoda Greedy
  priority_queue <struct Activitate> heap;
  int termen_curent = v[0].termen;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (v[i].termen == termen_curent) {
      heap.push(v[i]);
    }
    else {
      while (termen_curent != v[i].termen) {
        if (!heap.empty()) {
        sol[termen_curent - 1] = heap.top().indice_initial;
        sum += heap.top().profit;
        heap.pop();
        }
        termen_curent--;
      }
      i--;
    }
  }

  while (termen_curent != 0) {/// In mod normal se intampla numai o data
    sol[termen_curent - 1] = heap.top().indice_initial;
        sum += heap.top().profit;
        heap.pop();
        termen_curent--;
  }

  fout << "Profit: " << sum << endl;
  for (int i = 0; i < v[0].termen; i++) {
    if (sol[i])  fout << sol[i] << " ";
    else fout << "- ";
  }

  fin.close();
  fout.close();
  return 0;
}

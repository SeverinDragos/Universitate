#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int nr_grupe = 0, fin[n + 1], x[n + 1];
  vector <vector <int> > grupe;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }

  for (int i = 1; i <= n; i++) {
    int st = 1, dr = nr_grupe, poz = -1;
    while (st <= dr) {
      int med = (st + dr) / 2;
      if (fin[med] > x[i]) {
        poz = med;
        dr = med - 1;
      }
      else
        st = med + 1;
    }
    if (poz == -1) {
      fin[++nr_grupe] = x[i];
      vector <int> v;
      v.push_back(x[i]);
      grupe.push_back(v);
    }
    else {
      fin[poz] = x[i];
      grupe[poz - 1].push_back(x[i]);
    }
  }

  for (int i = 0; i < nr_grupe; i++) {
    for (int j = 0; j < grupe[i].size(); j++) {
      cout << grupe[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

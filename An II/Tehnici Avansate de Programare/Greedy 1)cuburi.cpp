#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

class Cub {
  int latime, culoare, indice;
public:
  int get_latime () {return latime;}
  int get_culoare () {return culoare;}
  int get_indice () {return indice;}
  void set_indice (int x) {indice = x;}
  friend istream& operator>>(istream&, Cub&);
  friend ostream& operator<<(ostream&, Cub&);
  bool operator< (const Cub&) const;
};

istream& operator>> (istream& in, Cub& x) {
  in >> x.latime >> x.culoare;
  return in;
}

ostream& operator<< (ostream& out, Cub& x) {
  out << "Latime: " << x.latime << " Culoare: " << x.culoare << endl;
  return out;
}

bool Cub::operator<(const Cub& x) const{
  if (latime == x.latime)
    return !(culoare < x.culoare);
  return !(latime < x.latime);
}

int main()
{
  ifstream fin ("date.in");
  ofstream fout ("date.out");
  int n, p;
  fin >> n >> p;
  Cub v[100];
  for (int i = 0; i < n; i++) {
    fin >> v[i];
    v[i].set_indice(i);
  }

  sort(v,v + n);

  for (int i = 0; i < n; i++) {
    cout << v[i];
  }

  ///Solutia Greedy
  int sol[100], inaltime = 0, nsol = 0, ultimul = 0;
  sol[nsol++] = v[0].get_indice();
  inaltime += v[0].get_latime();
  for (int i = 1; i < n; i++) {
    if ((v[i].get_culoare() != v[ultimul].get_culoare()) && (v[i].get_latime() != v[ultimul].get_latime())) /// dupa && este tratat punctul b)
    {
      sol[nsol++] = v[i].get_indice();
      inaltime += v[i].get_latime();
      ultimul = i;
    }
  }

  fout << inaltime << endl;
  for (int i = 0; i < nsol; i++) {
    fout << sol[i] + 1 << " ";
  }

  fin.close();
  fout.close();
  return 0;
}

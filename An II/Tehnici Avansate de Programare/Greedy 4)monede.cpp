#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
  ifstream fin ("monede.in");
  ofstream fout ("monede.out");
  int n, S;
  fin >> n;
  int monede[n], nr;
  for (int i = 0; i < n; i++) {
    fin >> monede[i];
  }
  fin >> S;

  for (int i = 0; i < n; i++) {
    cout << monede[i] << " ";
  }

  for (int i = n; i >= 0 && S != 0; i--) {
    nr = 0;
    while(S >= monede[i]) {
      S -= monede[i];
      nr++;
    }
    if (nr) {
      fout << nr << " monede de " << monede[i] << endl;
    }
  }




  fin.close();
  fout.close();
  return 0;
}

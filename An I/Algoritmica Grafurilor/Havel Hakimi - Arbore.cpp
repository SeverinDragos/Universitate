#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

struct node {
    int grad , node;
};

int main()
{
    ifstream fin ("graf.in");
    if (!fin.is_open()) cout << "Eroare la deschiderea fisierului!" << endl;
    int n, stop = 0, i, sum = 0, j, it, varf1, varf2;
    fin >> n;
    vector <int> a[n+1];
    node* v = new node [n];

    for (i = 0; i < n; i++) {
        v[i].node = i + 1;
        fin >> v[i].grad;
        sum+= v[i].grad;
    }
    if (sum != 2 * (n - 1)) { stop = 1; cout << "Suma nu e 2(n-1)" << endl; }

    for (j = 0; j < n - 2; j++) {
        varf1 = 0;
        varf2 = 0;
        for (i = 0; i < n && (varf1 == 0 || varf2 == 0); i++) {
            if (v[i].grad > 1 && varf1 == 0)  { varf1 = v[i].node; v[i].grad--; }
            else
            if (v[i].grad == 1 && varf2 == 0)  { varf2 = v[i].node; v[i].grad--; }
        }
        cout << varf1 << " " << varf2 << endl;
        a[varf1].push_back(varf2);
        a[varf2].push_back(varf1);
    }

    varf1 = 0;
    varf2 = 0;
    for (i = 0; i < n; i++) {
        if (v[i].grad == 1)
            if (varf1 == 0) { varf1 = v[i].node; v[i].grad--; }
            else { varf2 = v[i].node; v[i].grad--; }
    }
    a[varf1].push_back(varf2);
        a[varf2].push_back(varf1);

    if (!stop)  cout << "Se poate construi un arbore cu secventa data:" << endl;
    else    cout << "Nu se poate construi un arbore cu secventa data:" << endl;

    for (i = 0; i < n; i++) {
        cout << v[i].node << ": " << v[i].grad << endl;
    }

    if (!stop) {
    cout << "Arborele arata cam asa:" << endl;
    for (i = 1; i <= n; i++) {
            cout << i << ": ";
        for (it = 0; it < a[i].size(); it++) {
            cout << a[i][it] << " ";
        }
    cout << endl;
    }
    }

    delete []v;
    return 0;
}

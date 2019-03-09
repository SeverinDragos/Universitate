#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

struct node {
    int grad , node;
};

int cmp(const void* a, const void* b) {
    return ((node*)b)->grad - ((node*)a)->grad;
}

int main()
{
    ifstream fin ("graf.in");
    if (!fin.is_open()) cout << "Eroare la deschiderea fisierului!" << endl;
    int n, stop = 0, i, sum = 0, it;
    fin >> n;
    vector <int> a[n+1];
    node* v = new node [n];

    for (i = 0; i < n; i++) {
        v[i].node = i + 1;
        fin >> v[i].grad;
        if (v[i].grad > n-1) { stop = 1; cout << "E un grad de nod prea mare" << endl; }
        sum+= v[i].grad;
    }
    if (sum % 2 == 1) { stop = 1; cout << "Suma nu e para" << endl; }

    int (*pf)(const void*,const void*) = cmp;
    qsort(v, n, sizeof(node), pf);

    while (v[0].grad != 0 && !stop) {
        for (i = 1; i <= v[0].grad; i++) {
            v[i].grad--;
            if (v[i].grad < 0) { stop = 1; cout << "S-a facut un grad negativ" << endl; }

            a[ v[0].node ].push_back(v[i].node);
            a[ v[i].node ].push_back(v[0].node);
        }
        v[0].grad = 0;
        qsort(v, n, sizeof(node), pf);
    }

    if (!stop)  cout << "Se poate construi un graf cu secventa data:" << endl;
    else    cout << "Nu se poate construi un graf cu secventa data:" << endl;

    for (i = 0; i < n; i++) {
        cout << v[i].node << ": " << v[i].grad << endl;
    }

    if (!stop) {
    cout << "Graful arata cam asa:" << endl;
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

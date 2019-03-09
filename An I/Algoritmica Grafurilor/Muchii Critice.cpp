#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>

using namespace std;

int tata[100] , viz[100] , niv_min[100] , niv [100];
vector <int> v[100];

void DF(int x) {
    viz[x] = 1;
    niv_min[x] = niv[x];
    for(int i = 0; i < v[x].size(); i ++) {
    if( viz[ v[x][i] ] == 0 ) {
            tata[ v[x][i] ] = x;
            niv [ v[x][i] ] = niv[x] + 1;
            //cout<<x<<"->"<<v[x][i]<<" ";
            DF(v[x][i]);
            if( niv_min[ v[x][i] ] > niv[x] )   cout << x << " " << v[x][i] << endl; //Test muchie critica
            niv_min[x] = min(niv_min[x] , niv_min[ v[x][i] ]); //Actualizare niv_min
    }
    else if( tata[x] != v[x][i] )
        niv_min[x] = min(niv_min[x] , niv[ v[x][i] ]);
    }
}

int main()
{
    ifstream fin ("graf.in");
    int n , m , i , x , y;
    fin>>n;
    fin>>m;
    for(i = 1; i <= m ; i ++)
    {
        fin>>x>>y;
        v[x].push_back(y);
        if(x != y)
        v[y].push_back(x);
    }
/*
    for(int j = 1 ; j <= n; j ++)
    {
        cout<<j<<": ";
    for(i = 0; i < v[j].size(); i++ )
    {
        cout<<" "<<v[j][i];
    }
        cout<<endl;
    }
*/
    DF(1);
/*
    for(i = 1; i <= n ; i ++)
        cout<<tata[i]<<" ";
*/
    return 0;
}

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>

using namespace std;

int tata[100] , viz[100];
vector <int> v[100];

void DF(int x , int& contor) {
    viz[x] = 1;
    for(int i = 0; i < v[x].size(); i ++)
    if(contor == 0){
    if( viz[ v[x][i] ] == 0 ) {
            tata[ v[x][i] ] = x;
            //cout<<x<<"->"<<v[x][i]<<" ";
            DF(v[x][i],contor);
    }
    else if( tata[x] != v[x][i] ){
        contor = 1;
        int p = x;
        cout<<p<<" ";

        while(p != v[x][i]) {
            p=tata[p];
            cout<<p<<" ";
        }
        cout<<x;
    }
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
    int c=0;
    DF(5,c);
/*
    for(i = 1; i <= n ; i ++)
        cout<<tata[i]<<" ";
*/
    return 0;
}

#include<fstream>
#include<vector>
#include<iostream>
using namespace std;

void citire(int &n,vector<int> *&la, ifstream &f){
	int m,i,x,y;
	f>>n>>m;
	la=new vector<int>[n+1];
	for(i=1;i<=m;i++){
		f>>x>>y;
		la[x].push_back(y);
		//neorientat
		la[y].push_back(x);
	}
  
}

void dfs(int x, vector<int> *la, int *viz, int *nivel, int *niv_min, int *critic, int &nrfii){
 
     viz[x]=1;
     niv_min[x] = nivel[x];
     for(int i=0;i<la[x].size();i++){
        int y=la[x][i];
		if (viz[y]==0){
			nivel[y]=nivel[x]+1;
			
			if(nivel[y]==1) nrfii++; //fiu al radacinii = varf de pe nivelul 1
				
            dfs(y,la,viz,nivel,niv_min,critic, nrfii);
                        
             //actualizare niv_min[x] -cazul B=preia informatia din fiu (definitie recursiva)
            niv_min[x]=min(niv_min[x],niv_min[y]);
             
			 //test de muchie critica 
            if (niv_min[y] > nivel[x]) 
			 	cout<<x<<" " <<y<<endl;
             
             //test de punct critic + marcarea punctului (nu afisare, altfel este posibil sa il afiseze de mai multe ori)
            if (niv_min[y] >= nivel[x])  //exista fiu y care nu este inchis intr-un ciclu mai sus de x
			 	critic[x]=1;
		}
         else
		 	if(nivel[y]<nivel[x]-1){//actualizare niv_min[x] -cazul A = muchie de intoarcere din x
			    niv_min[x]=min(niv_min[x],nivel[y]);	  
            }
	}
    
}



int main(){
	vector<int> *la;
	int n,m,s, nrfii;
	int i,j;
	int *viz,*nivel,*niv_min, *critic;
	ifstream f("graf.in");
	citire(n,la,f);
	f.close();
 
	viz=new int[n+1];
	nivel=new int[n+1];
	niv_min=new int[n+1];
	critic=new int[n+1];
	for(int i=1;i<=n;i++)
		viz[i]=nivel[i]=critic[i]=0;
	
	cout<<"muchii critice: "<<endl;	
    for(int i=1;i<=n;i++)
    	if(viz[i]==0){
			nrfii=0;
    		dfs(i,la,viz,nivel,niv_min,critic,nrfii);
    		//testam separat radacina arborelui df daca este punct critic=are minim 2 fii
    		if(nrfii>=2)
    			critic[i]=1;
    		else
				critic[i]=0;	
    	}
    cout<<"puncte critice: ";	
    for(int i=1;i<=n;i++)
		if(critic[i]==1)
			cout<<i<<" ";	

}

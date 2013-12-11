#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define MAX 100001
#define INF (1<<20)
#define pci pair< char, int >



struct comp {
    bool operator() (const pci &a, const pci &b) {
        return a.second > b.second;
    }
};

priority_queue< pci, vector< pci >, comp > Q;
vector< pci > G[MAX];
int D[MAX];
bool F[MAX];
vector<char> n;
char u, v;
long nodes, edges = 0;
int k=50;



void printMST(int parent[])
	{
		while(k>nodes-1){
		printf("\nEnter an integer k: ");
		cin>>k;

		if(k>nodes-1)
			printf("\nIncorrect input, must be |V|-1\n");
		}
		printf("\nShortest Reliable Paths Algorithm\nInteger k : %d Source : %c\n", k, (char)n[0]);

		for (int i = 1; i <=nodes; i++){
	
	   if(i == 1){
			printf("Source NODE %c : %d\n", (char)n[i-1], D[n[i-1]]);
			continue;
	   }
	   
	   if(parent[n[i-1]]!=parent[n[1]] && n[i-1]!=parent[n[1]]){
		printf("NODE %c - ", (char)parent[parent[parent[n[i-1]]]]);
	   }
	  if(n[i-1]!=parent[n[1]]){
		   printf("NODE %c - ", (char)parent[parent[n[i-1]]]);
	  }
    
      printf("NODE %c - NODE %c : %d\n", (char)parent[n[i-1]], (char)n[i-1], D[n[i-1]]);
	 
   }
   printf("End Shortest Reliable Paths Algorithm\n");
	}

int main() {
	int parent[50];
	string line;
	string FILENAME = "input2.txt";
	ifstream istream;

    int i, w, sz;
	char dir, starting = ' ';
    istream.open(FILENAME.c_str());
	if(istream.fail())
	{
		printf("Bad File name. Check readme for example.\n");
	}
	else{
		getline(istream,line);
		istringstream iss(line);
		iss>>dir;

		while(getline(istream,line)){
				
               istringstream iss(line);
               while(iss>>u>>v>>w){
					if(starting == ' '){
						starting = u;
						n.push_back(u);}

						if(std::find(n.begin(), n.end(), v) != n.end()) {
							/* n contains v */
							
						} else {
							/* n does not contain v */
							n.push_back(v);
						}

				  		G[u].push_back(pci(v, w));
						edges++;
					
					if(dir != 'D'){
						G[v].push_back(pci(u, w)); // for undirected
						edges++;
						}
			   }
        }
		nodes = n.size();
		
		
		
		// initialize graph
    for(i=1; i<=nodes; i++) D[n[i-1]] = INF;
   D[starting] = 0;
   Q.push(pci(starting, 0));


    // dijkstra
    while(!Q.empty()) {
       
		u = Q.top().first;
		
        Q.pop();
       
		if(F[u]){ 
			continue;
		}
        
		sz = G[u].size();
	
		for(i=0; i<sz; i++) {
            v = G[u][i].first;
            w = G[u][i].second;
			
 
			if(!F[v] && D[u]+w < D[v]) {
				
				
				D[v] = D[u] + w;
				
                Q.push(pci(v, D[v]));
				
				parent[v]  = u;
				
								
            }
        }
			
			F[u] = 1; 
    }
	
    // result
	printf("Dijkstra\nSource : %c\n", (char)n[0]);
    for(i=1; i<=nodes; i++){ 
		printf("Node %c : %d\n", (char)n[i-1], D[n[i-1]]);
	}
	printf("End Dijkstra\n");

	

    }
	

	printMST(parent);
	
  
    return 0;
}



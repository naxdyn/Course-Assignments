#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

typedef struct{
    int src;
    int dest;
    int weight;
} edge;

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

// simple function to see if our "sets" contain certain vertices
bool contains(string str, string a){
    if(str.find(a) != string::npos){ return true;}
    return false;
}

void MST(edge graph[], int E, int V){
    //selection sorting the graph
	for(int i=0;i<E;i++){
		int min = i;
		for(int j=i+1;j<E;j++){
			if(graph[j].weight < graph[min].weight) { min = j; }
		}
		swap(&graph[i].weight, &graph[min].weight);
        swap(&graph[i].src, &graph[min].src);
        swap(&graph[i].dest, &graph[min].dest);
	}

    // using an array of string to represent sets because I don't know how else
    string set[E];
    for(int i = 0; i < E; i++){
        set[i] = to_string(i);
    }

    edge mst[V-1];
    mst[0] = graph[0];
    // appends the destination to the source to form a set, then deletes the destination set
    set[graph[0].src].append(set[graph[0].dest]);
    set[graph[0].dest] = "";
    
    int index = 1;
    bool isCycle = false;
    for(int i = 1; i < E; i++){
        if (index == V-1){ break; }
        for(int j = 0; j < E; j++){
            // cycle is found if any set contains both the source & destination vertex characters
            if(contains(set[j], to_string(graph[i].src)) && contains(set[j], to_string(graph[i].dest))){
                isCycle = true;
                break;
            }
        }
        // if cycle is not found, combine the sets and add the edge to mst
        if (isCycle == false){
                set[graph[i].src].append(set[graph[i].dest]);
                set[graph[i].dest] = ""; 
                mst[index] = graph[i];
                index = index + 1;
        }
        isCycle = false;
    }

    cout << "The edges in the minimum spanning tree are: " << endl;
    int totalWeight = 0;
    for(int i = 0; i < V-1; i++){
    cout << mst[i].src << " -- " << mst[i].dest << " == " << mst[i].weight << endl;
    totalWeight = totalWeight + mst[i].weight;
    }
    cout << "Total weight is " << totalWeight << endl;
}

int main(){
    // graph creation
    int V = 4;
    int E = 5;
    edge graph[E];

    // adding edges
    graph[0].src = 0;
    graph[0].dest = 1;
    graph[0].weight = 5;      

    graph[1].src = 1;
    graph[1].dest = 3;
    graph[1].weight = 7;      

    graph[2].src = 3;
    graph[2].dest = 2;
    graph[2].weight = 2;      

    graph[3].src = 3;
    graph[3].dest = 0;
    graph[3].weight = 2;      

    graph[4].src = 2;
    graph[4].dest = 0;
    graph[4].weight = 3;   

    MST(graph, E, V); 
}
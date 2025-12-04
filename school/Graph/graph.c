#include <stdio.h>
#include <stdlib.h>

//노드 생성(간선 노드)
typedef struct Node{
	int vertex;
	struct Node* next;
	int weight;
}node;

//그래프 생성
typedef struct Graph{
	int V;	//vertex의 개수
	node** adj;
}graph;

//그래프 생성 함수
graph* createGraph(int V){
	graph* newGraph = (graph*)malloc(sizeof(graph));
	newGraph->V = V;
	newGraph->adj = (node**)malloc(sizeof(node*)* V+1);
	for(int i = 0; i<= V; i++){
		newGraph->adj[i] = NULL;
	}
	return newGraph;
}

node* createNode(int n,int w){
	node* newNode = (node*)malloc(sizeof(node));
	newNode->next = NULL;
	newNode->vertex = n;
	newNode->weight = w;
	return newNode;
}

void addEdge(graph* g, int u, int v, int w){
	node* nodeV = createNode(v,w);
	node* nodeU = createNode(u,w);
	if(g->adj[u] == NULL){
		g->adj[u] = nodeV;
	}
	else{
		node *now = g->adj[u];
		node *prev = NULL;
		while(now != NULL && now->vertex < v){
			prev = now;
			now = now->next;
		}
		prev->next = nodeV;
		nodeV->next = now;
		if(g->adj[u] == now){
			g->adj[u] = nodeV;
		}
	}
	if(u == v){
		return;
	}
	if(g->adj[v] == NULL){
		g->adj[v] = nodeU;
	}
	else{
		node *now = g->adj[v];
		node *prev = NULL;
		while(now != NULL && now->vertex < u){
			prev = now;
			now = now->next;
		}
		prev->next = nodeU;
		nodeU->next = now;
		if(g->adj[v] == now){
			g->adj[v] = nodeU;
		}
	}
}

void printGraph(graph* g){

}

int main(){
	graph* graph = createGraph(7);

	addEdge(graph, 1,2,1);
	addEdge(graph, 1,3,1);
	addEdge(graph, 1,4,1);
	addEdge(graph, 1,6,2);
	addEdge(graph, 2,3,1);
	addEdge(graph, 3,5,4);
	addEdge(graph, 5,5,4);
	addEdge(graph, 5,6,3);

	char com;
	scanf("%c", &com);
	while(com != 'q'){
		int n;
		int a,b,w;
		switch(com){
			case 'a':
				scanf("%d", &n);
				node* now = graph->adj[n];
				while(now != NULL){
					printf(" %d %d", now->vertex, now->weight);
					now = now->next;
				}
				break;
			case 'm':
				break;
		}
		getchar();
		scanf("%c", &com);

	}

	int n;
	scanf("%d", &n);
	node* now = graph->adj[n];
	while(now != NULL){
		printf(" %d %d", now->vertex, now->weight);
		now = now->next;
		//인접노드 출력
	}



	
	return 0;
}

// 1
//  2 3 4 6
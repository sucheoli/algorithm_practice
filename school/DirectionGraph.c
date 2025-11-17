#include <stdio.h>
#include <stdlib.h>
/*Q.Direction Graph
Topology Sorting, 위상 순서를 찾아 인쇄*/

typedef struct vertices{        //정점
    I* incidences;
    int visit;      //dfs용 탐색했으면 1 아니면 0
    char data;
}V;

typedef struct incidence{       //인접정점
    struct incidence* next;
    int index;
}I;

I* createI(){
    I* newI = (I*)malloc(sizeof(I));
    newI->index = -1;
    newI->next = NULL;

    return newI;
}

void makeEdge(char start, char end){
    
}


int main(){
    int n;  //정점 개수
    int m;  //간선 개수
    scanf("%d", &n);

    V* vertices = (V*)malloc(sizeof(V) * n);

    for(int i =0; i < n; i++){
        char data;
        scanf("%c", &data);     //정점 데이터
        vertices[i].data = data;
        vertices[i].incidences = createI();
        vertices[i].visit = 0;
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++){
        char start, end;
        scanf("%c%c", &start, &end);
        
    }
    
    return 0;
}

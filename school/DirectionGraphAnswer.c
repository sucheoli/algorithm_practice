#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    char name;              // 정점 이름
    Node* outEdges;         // 진출 간선 리스트
    int inDegree;
} Vertex;

typedef struct {
    int origin, destination;
} Edge;

/* 전역 변수 */
Vertex vertices[MAX_N];
Edge edges[1000];
int n, m;
int indeg[MAX_N];
int topOrder[MAX_N + 1];    // [0]: DAG 여부, [1..n]: 정점 인덱스
int queue[MAX_N];
int front, rear;

/* 큐 */
void initQ() { front = rear = 0; }
int empty() { return front == rear; }
void enq(int x) { queue[rear++] = x; }
int deq() { return queue[front++]; }

/* addFirst */
void addFirst(Node** head, int edgeIdx) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = edgeIdx;
    newNode->next = *head;
    *head = newNode;
}

/* 정점 이름 → 인덱스 찾기 */
int getIndex(char name) {
    for (int i = 0; i < n; i++)
        if (vertices[i].name == name)
            return i;
    return -1;
}

/* 위상정렬 */
void topologicalSort() {
    initQ();
    
    for (int i = 0; i < n; i++) {
        indeg[i] = vertices[i].inDegree;
        if (indeg[i] == 0)
            enq(i);                     // 작은 번호부터 들어감
    }
    
    int cnt = 0;
    while (!empty()) {
        int u = deq();
        topOrder[++cnt] = u;
        
        Node* p = vertices[u].outEdges;
        while (p) {
            int w = edges[p->data].destination;
            if (--indeg[w] == 0)
                enq(w);
            p = p->next;
        }
    }
    
    topOrder[0] = (cnt == n) ? 1 : 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &vertices[i].name);
        vertices[i].outEdges = NULL;
        vertices[i].inDegree = 0;
    }
    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        char u, w;
        scanf(" %c %c", &u, &w);
        int ui = getIndex(u);
        int wi = getIndex(w);
        
        edges[i].origin = ui;
        edges[i].destination = wi;
        
        addFirst(&vertices[ui].outEdges, i);   // 새 간선이 앞에!
        vertices[wi].inDegree++;
    }
    
    topologicalSort();
    
    if (topOrder[0] == 0)
        printf("0\n");
    else {
        for (int i = 1; i <= n; i++) {
            if (i > 1) printf(" ");
            printf("%c", vertices[topOrder[i]].name);
        }
        printf("\n");
    }
    
    return 0;
}
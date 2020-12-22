#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef unsigned long long int UINT;
typedef long long int INT;

/*
* Implementation Details:-
* 1. This is an implementation of Undirected Graph 
* 2. The number of vertices in a graph cannot be changed after it has been initialized
*/

struct Vertex {
    INT data;
    struct Vertex *next;
};

typedef struct Vertex Vertex;

struct Graph {
    Vertex* adjacency_list;
    UINT number_of_vertex;
};

typedef struct Graph Graph;

//Vertex Methods
Vertex* new_Vertex_with_paramters(INT data, Vertex *next);
Vertex* new_Vertex(void);

//Graph Methods
Graph* new_graph(UINT v);
void insert(Graph *G, INT v, INT u);
void print_graph(Graph *G);

int main() {
    Graph *g = new_graph(4);

    //Example Graph
    // 1 --- 2
    // |  / |
    // |/   |
    // 3 -- 4

    insert(g, 1, 2);
    insert(g, 1, 3);
    insert(g, 3, 4);
    insert(g, 4, 2);
    insert(g, 3, 2);

    print_graph(g);

    return 0;
}

//Vertex Methods
Vertex* new_Vertex_with_paramters(INT data, Vertex *next) {
    //Create a new vertex
    Vertex* temp = (Vertex *)malloc(sizeof(Vertex));
    //Inititalize with values
    temp->data = data;
    temp->next = next;

    return temp;
}

Vertex* new_Vertex(void) {
    //Create a new vertex
    Vertex* temp = (Vertex *)malloc(sizeof(Vertex));
    //Inititalize with placeholder values
    temp->data = INT_MIN;
    temp->next = NULL;

    return temp;
}

//Graph Methods
/*
* Parameters:-
* Number of Vertices of Graph 
*/
Graph* new_graph(UINT v) {
    Graph* temp = (Graph *)malloc(sizeof(Graph));

    temp->adjacency_list = (Vertex *)malloc(v*sizeof(Vertex));
    temp->number_of_vertex = v;

    for(UINT i = 0; i < v; i++) {
        temp->adjacency_list[i].data = INT_MIN;
        temp->adjacency_list[i].next = NULL;
    }

    return temp;
}

/*
* Parameters:-
* 1. Graph in which to insert vertex
* 2. Vertex to add
* 3. Neighbour Vertex
*/
void insert(Graph *G, INT v, INT u) {
    short int flag1, flag2;
    Vertex *temp;

    flag1 = flag2 = 0;

    //Search if the given vertex is already present
    for(UINT i = 0; i < G->number_of_vertex && (flag1 != 1 || flag2 != 1); i++) {
        if(G->adjacency_list[i].data == v) {
            temp = G->adjacency_list[i].next;
            
            while(temp->next != NULL && temp->data != u) {
                temp = temp->next;
            }

            if(temp->data != u && temp->next == NULL) {
                temp->next = new_Vertex_with_paramters(u, NULL);
            }

            flag1 = 1;
        }
        if(G->adjacency_list[i].data == u) {
            temp = G->adjacency_list[i].next;
            
            while(temp->next != NULL && temp->data != v) {
                temp = temp->next;
            }

            if(temp->data != v && temp->next == NULL) {
                temp->next = new_Vertex_with_paramters(v, NULL);
            }

            flag2 = 1;
        }
    }

    //If not already in the graph
    if(flag1 != 1 || flag2 != 1) {
        int index;

        if(flag1 != 1) {
            for(UINT i = 0; i < G->number_of_vertex && G->adjacency_list[index].data != INT_MIN; i++) {
                index = i;
            }

            G->adjacency_list[index].data = v;
            G->adjacency_list[index].next = new_Vertex_with_paramters(u, NULL);
        }

        if(flag2 != 1) {
            for(UINT i = 0; i < G->number_of_vertex && G->adjacency_list[index].data != INT_MIN; i++) {
                index = i;
            }

            G->adjacency_list[index].data = u;
            G->adjacency_list[index].next = new_Vertex_with_paramters(v, NULL);
        }
    }

    return;
}

void print_graph(Graph *G) {
    Vertex* temp;

    printf("\nThe Graph is ...\n");
    for(UINT i = 0; i < G->number_of_vertex; i++) {
        if(G->adjacency_list[i].data != INT_MIN) {
            printf("Vertex %d : ", G->adjacency_list[i].data);

            temp = G->adjacency_list[i].next;

            while(temp != NULL) {
                printf("%d ", temp->data);
                temp = temp->next;
            }

            printf("\n");
        }   
        else {
            continue;
        }
    }

    return;
}
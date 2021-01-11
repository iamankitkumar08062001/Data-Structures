#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long int UINT;
typedef long long int INT;

//Implementation Details
//1. Acyclic Graph
//2. Undirected
//3. Multiple Edges are not allowed

//Type Definitions
struct bool {
    short int v;
};

typedef struct bool bool;

struct Vertex {  
    INT data;
};

typedef struct Vertex Vertex;

struct Graph {
    Vertex **adjacency_matrix;
    INT number_of_edges;
};

typedef struct Graph Graph;

//Bool Methods
bool* new_bool_int(short i);
bool* new_bool_string(char *s);

//Graph Methods
Graph* new_graph(INT v);
bool* add_edge(Graph *G , INT v, INT u);
void delete_graph(Graph *G);
void print_graph_adjacency_list(Graph *G);
void print_graph_adjacency_matrix(Graph *G);

int main() {  

    //Example Usage
    Graph* G = new_graph(5);

    add_edge(G, 1, 2);
    add_edge(G, 1, 4);
    add_edge(G, 2, 3);
    add_edge(G, 2, 4);
    add_edge(G, 3, 4);

    print_graph_adjacency_list(G);

    return 0;
}

/*
    Description - Returns a new Graph with given Size
    Parameters - Number of Vertices 
*/
Graph* new_graph(INT v) {
    Graph *G = (Graph *)malloc(sizeof(Graph)); 

    G->adjacency_matrix = (Vertex **)malloc((v + 1) * sizeof(Vertex *));

    for(INT i = 0; i < v + 1; i++) {
        *(G->adjacency_matrix + i) = (Vertex *)malloc((v + 1) * sizeof(Vertex));
    }

    G->number_of_edges = v + 1;

    for(INT i = 0; i < G->number_of_edges; i++) {
        for(INT j = 0; j < G->number_of_edges; j++) {
            (*(G->adjacency_matrix + i) + j)->data = 0;
        }
    }

    return G; 
}

/*
    Description - Check the validity of Edges and adds an Edge if not already present
    Parameters - Number of Vertices 
*/
bool* add_edge(Graph *G , INT v, INT u) {
    if(G->number_of_edges < v || G->number_of_edges < u) {
        return new_bool_string("false");
    }
    else {
        (*(G->adjacency_matrix + v) + u)->data = 1;
        (*(G->adjacency_matrix + u) + v)->data = 1;
        return new_bool_string("true");
    }
}

void print_graph_adjacency_list(Graph *G) {
    printf("\nThe Graph is as follows...\n");
    bool temp;

    for(INT i = 0; i < G->number_of_edges; i++) {

        temp.v = 0;
        printf("%d is connected to ", i);
        
        for(INT j = 0; j < G->number_of_edges; j++) {
            if((*(G->adjacency_matrix + i) + j)->data == 1) {
                temp.v = 1;
                printf("%d ", j);
            }
        }

        if(temp.v == 0) {
            printf("none");
        }
        
        printf("\n");
    }

    return;
}

void print_graph_adjacency_matrix(Graph *G) {
    printf("\nThe Graph is as follows...\n    ");

    for(INT i = 0; i < G->number_of_edges; i++) {
        printf("%d ", i);
    }

    printf("\n");

    for(INT i = 0; i < G->number_of_edges; i++) {

        printf("%d : ", i);
        
        for(INT j = 0; j < G->number_of_edges; j++) {
            printf("%d ", (*(G->adjacency_matrix + i) + j)->data);
        }
        
        printf("\n");
    }

    return;
}


//Bool Methods
bool* new_bool_int(short i) {
    bool *temp = (bool *)malloc(sizeof(bool));
    if(i == 0) {
        temp->v = 0;
        return temp;
    }
    else {
        temp->v = 1;
        return temp;
    }
}

bool* new_bool_string(char *s) {
    bool *temp = (bool *)malloc(sizeof(bool));
    if(s == "true" || s == "True") {
        temp->v = 1;
        return temp;
    }
    else {
        temp->v = 0;
        return temp;
    }
}
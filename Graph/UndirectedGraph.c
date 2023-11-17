#include <stdio.h>
#include <stdlib.h>

struct vertex {
    int end;
    struct vertex *next;
};

struct graph {
    struct vertex *point[5];
};

struct edge {
    int start, end;
};

struct graph *create_graph(struct edge edges[], int x) {
    int i;
    struct graph *graph = (struct graph*)malloc(sizeof(struct graph));

    for (i = 0; i < 5; i++) {
        graph->point[i] = NULL;
    }

    // Add edges to the graph (undirected)
    for (i = 0; i < x; i++) {
        int start = edges[i].start;
        int end = edges[i].end;

        // Create a vertex for both directions (A->B and B->A)
        struct vertex *v1 = (struct vertex*)malloc(sizeof(struct vertex));
        struct vertex *v2 = (struct vertex*)malloc(sizeof(struct vertex));

        v1->end = end;
        v1->next = graph->point[start];
        graph->point[start] = v1;

        v2->end = start;
        v2->next = graph->point[end];
        graph->point[end] = v2;
    }
    return graph;
}

void print_graph(struct graph *graph) {
    printf("Graph Adjacency Lists:\n");
    for (int i = 0; i < 5; i++) {
        struct vertex *ptr = graph->point[i];
        printf("%d -> ", i);
        while (ptr != NULL) {
            printf("%d ", ptr->end);
            if (ptr->next != NULL) {
                printf("-> ");
            }
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main() {
    struct edge edges[] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 4}, {2, 4}, {2, 3}, {3, 1}};
    int n = sizeof(edges) / sizeof(edges[0]);
    struct graph *graph = create_graph(edges, n);

    print_graph(graph);

    return 0;
}

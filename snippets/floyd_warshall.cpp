int INF = std::numeric_limits<int>::max();

void floydWarshall(Graph *g) {
    int V = g->getV();
    int **dist = new int *[V];
    int **parent = new int *[V];

    for (int i = 0; i < V; i++) {
        dist[i] = new int[V];
        parent[i] = new int[V];
        for (int j = 0; j < V; j++) {
            dist[i][j] = INF;
            parent[i][j] = -1;
        }
        dist[i][i] = 0;
    }

    for (int i = 0; i < V; i++) {
        Iterator<Edge> *it = g->adjacents(i);
        while (it->hasNext()) {
            Edge edge = it->next();
            dist[i][edge.to] = edge.weight;
            parent[i][edge.to] = i;
        }
        delete it;
    }

    // Algoritmo de Floyd-Warshall
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }

    // Liberación de memoria
    for (int i = 0; i < V; i++) {
        delete[] dist[i];
        delete[] parent[i];
    }
    delete[] dist;
    delete[] parent;
}

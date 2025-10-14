class DisjointSet
{
private:
    int *parent;
    int size;

public:
    DisjointSet(int n) {
        this->size = n;
        this->parent = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            this->parent[i] = i;
        }
    }

    int find(int x) {
        if (this->parent[x] == x) {
            return x;
        }
        return find(this->parent[x]);
    }

    void merge(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        // if they are already in the same set
        if (xRoot == yRoot) {
            return;
        }
        
        this->parent[xRoot] = yRoot;
    }
};

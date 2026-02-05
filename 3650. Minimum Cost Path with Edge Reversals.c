#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 50000
#define MAXM 100000
#define INF 1000000000

typedef struct
{
    int to, w, next;
} Edge;

Edge g[4 * MAXM + 5];
int head[MAXN], ec;

static inline void addEdge(int u, int v, int w)
{
    g[ec].to = v;
    g[ec].w = w;
    g[ec].next = head[u];
    head[u] = ec++;
}

/* ---------- Min Heap ---------- */
typedef struct
{
    int node, dist;
} State;

State heap[300000];
int hsz;

static inline void heapPush(State s)
{
    int i = hsz++;
    while (i > 0)
    {
        int p = (i - 1) / 2;
        if (heap[p].dist <= s.dist)
            break;
        heap[i] = heap[p];
        i = p;
    }
    heap[i] = s;
}

static inline State heapPop()
{
    State res = heap[0];
    State last = heap[--hsz];
    int i = 0;

    while (1)
    {
        int l = 2 * i + 1;
        if (l >= hsz)
            break;
        int r = l + 1;
        int s = (r < hsz && heap[r].dist < heap[l].dist) ? r : l;
        if (heap[s].dist >= last.dist)
            break;
        heap[i] = heap[s];
        i = s;
    }
    heap[i] = last;
    return res;
}

/* ---------- Solution ---------- */
int minCost(int n, int **edges, int edgesSize, int *edgesColSize)
{
    (void)edgesColSize;

    ec = 0;
    hsz = 0;
    memset(head, -1, n * sizeof(int));

    for (int i = 0; i < edgesSize; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        addEdge(u, v, w);     // normal
        addEdge(v, u, 2 * w); // reversed using switch
    }

    static int dist[MAXN];
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[0] = 0;
    heapPush((State){0, 0});

    while (hsz)
    {
        State cur = heapPop();
        int u = cur.node;

        if (cur.dist != dist[u])
            continue;
        if (u == n - 1)
            return cur.dist;

        for (int i = head[u]; i != -1; i = g[i].next)
        {
            int v = g[i].to;
            int nd = cur.dist + g[i].w;
            if (nd < dist[v])
            {
                dist[v] = nd;
                heapPush((State){v, nd});
            }
        }
    }

    return -1;
}

int minCost(int n, int **edges, int edgesSize, int *edgesColSize);

int main()
{
    int n = 3;

    /* edges = [[2,1,1],[1,0,1],[2,0,16]] */
    int edgesSize = 3;
    int edgesColSizeArr[3] = {3, 3, 3};

    int **edges = malloc(edgesSize * sizeof(int *));
    for (int i = 0; i < edgesSize; i++)
    {
        edges[i] = malloc(3 * sizeof(int));
    }

    edges[0][0] = 2;
    edges[0][1] = 1;
    edges[0][2] = 1;
    edges[1][0] = 1;
    edges[1][1] = 0;
    edges[1][2] = 1;
    edges[2][0] = 2;
    edges[2][1] = 0;
    edges[2][2] = 16;

    int ans = minCost(n, edges, edgesSize, edgesColSizeArr);
    printf("Answer = %d\n", ans); // Expected: 4

    /* free memory */
    for (int i = 0; i < edgesSize; i++)
    {
        free(edges[i]);
    }
    free(edges);

    return 0;
}
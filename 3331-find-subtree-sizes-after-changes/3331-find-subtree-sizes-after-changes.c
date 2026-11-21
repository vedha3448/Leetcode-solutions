/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <string.h>

#define MAXN 100005

int head[MAXN], to[MAXN], next[MAXN];
int newHead[MAXN], newTo[MAXN], newNext[MAXN];

int edgeCount, newEdgeCount;
int newParent[MAXN];
int answer[MAXN];

int last[26];

void addEdge(int u, int v) {
    to[edgeCount] = v;
    next[edgeCount] = head[u];
    head[u] = edgeCount++;
}

void addNewEdge(int u, int v) {
    newTo[newEdgeCount] = v;
    newNext[newEdgeCount] = newHead[u];
    newHead[u] = newEdgeCount++;
}

// First DFS: Find the closest matching ancestor
void findParent(int node, int parent[], char *s) {
    int c = s[node] - 'a';

    int old = last[c];

    if (node != 0 && old != -1)
        newParent[node] = old;
    else
        newParent[node] = parent[node];

    last[c] = node;

    for (int e = head[node]; e != -1; e = next[e]) {
        findParent(to[e], parent, s);
    }

    last[c] = old;
}

// Second DFS: Calculate subtree sizes
int dfsSize(int node) {
    int size = 1;

    for (int e = newHead[node]; e != -1; e = newNext[e]) {
        size += dfsSize(newTo[e]);
    }

    answer[node] = size;
    return size;
}

int* findSubtreeSizes(int* parent, int n, char* s, int* returnSize) {

    memset(head, -1, sizeof(head));
    memset(newHead, -1, sizeof(newHead));

    edgeCount = 0;
    newEdgeCount = 0;

    for (int i = 0; i < 26; i++)
        last[i] = -1;

    for (int i = 1; i < n; i++) {
        addEdge(parent[i], i);
    }

    findParent(0, parent, s);

    for (int i = 1; i < n; i++) {
        addNewEdge(newParent[i], i);
    }

    dfsSize(0);

    int *result = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        result[i] = answer[i];

    *returnSize = n;

    return result;
}

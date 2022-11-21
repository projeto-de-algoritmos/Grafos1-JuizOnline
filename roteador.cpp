#include <iostream>

using namespace std;

struct s_no
{
    int v;
    int w;
    int p;
} typedef no;

no g[205];
int p[65];

int compare(const void *a, const void *b)
{
    return ((no *)a)->p - ((no *)b)->p;
}

int filho(int i)
{
    if (i == p[i])
        return i;
    return filho(p[i]);
}

int kruskal(int c)
{
    int i, agm, v, w;

    for (i = 0, agm = 0; i < c; i++)
    {
        v = filho(g[i].v);
        w = filho(g[i].w);

        if (v != w)
        {
            p[v] = p[w];
            agm += g[i].p;
        }
    }

    return agm;
}

int main(void)
{

    int r, c, i;

    scanf("%d %d", &r, &c);

    for (i = 0; i < c; i++)
    {
        scanf("%d %d %d", &g[i].v, &g[i].w, &g[i].p);
    }

    qsort(g, c, sizeof(no), compare);
    for (i = 1; i <= r; i++)
        p[i] = i;

    printf("%d\n", kruskal(c));

    return 0;
}

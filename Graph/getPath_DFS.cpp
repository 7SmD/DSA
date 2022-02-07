#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void print(int **edges, int n, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
                continue;
            print(edges, n, i, visited);
        }
    }
}

void printBFS(int **edges, int n, int sv)
{
    queue<int> pendingVertices;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    pendingVertices.push(sv);
    visited[sv] = true;
    while (!pendingVertices.empty())
    {
        int CurrentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << CurrentVertex << endl;
        for (int i = 0; i < n; i++)
        {
            if (i == CurrentVertex)
            {
                continue;
            }
            if (edges[CurrentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> *getPath_DFS(int **edges, int n, int s, int e, bool *visited)
{
    if (s == e)
    {
        vector<int> *output = new vector<int>();
        output->push_back(e);
        return output;
    }
    visited[s] = true;

    for (int i = 0; i < n; i++)
    {
        if (edges[s][i] && !visited[i])
        {
            vector<int> *smallOutput = getPath_DFS(edges, n, i, e, visited);
            if (smallOutput != NULL)
            {
                smallOutput->push_back(s);
                return smallOutput;
            }
        }
    }
    return NULL;
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
            edges[i][j] = 0;
    }
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    int sv, en;
    cin >> sv >> en;

    vector<int> *output = getPath_DFS(edges, n, sv, en, visited);
    if (output != NULL)
    {
        for (int i = 0; i < output->size(); i++)
        {
            cout << output->at(i) << " ";
        }
    }
}
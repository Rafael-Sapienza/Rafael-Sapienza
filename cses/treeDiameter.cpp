#include <iostream>
#include <vector>
using namespace std;

void construaArvore(vector<vector<int>>& nodes)
{
    int node1,node2;
    for (int i = 1; i <= static_cast<int>(nodes.size()) - 2; i++)
    {
        cin >> node1 >> node2;
        nodes[node1].push_back(node2);
        nodes[node2].push_back(node1);
    }
}


vector<int> bfs(int nodeInicial, vector<vector<int>>& nodes)
{
    vector<int> nodesAtuais;
    vector<int> proximosNodes;
    vector<bool> visited(nodes.size());
    for (int i = 0; i < nodes.size(); i++)
    {
        visited[i] = false;
    }
    visited[nodeInicial] = true;

    proximosNodes = {nodeInicial};

    int distance = -1;
    while(proximosNodes.size() != 0)
    {
        nodesAtuais = proximosNodes;
        proximosNodes = {};
        distance++;
        for (int currentNode: nodesAtuais)
        {
            for (int proximoNode : nodes[currentNode])
            {
                if (!visited[proximoNode])
                {
                    visited[proximoNode] = true;
                    proximosNodes.push_back(proximoNode);
                }
            }
        }
    }
    vector<int> result = {distance,nodesAtuais.at(0)};
    return result;
}


int main()
{
    int numeroDeNodulos;
    cin >> numeroDeNodulos;
    vector<vector<int>> nodes(numeroDeNodulos + 1);
    construaArvore(nodes);

    vector<int> resultado1 = bfs(1,nodes);
    int furthestNode = resultado1[1];

    vector<int> resultado2 = bfs(furthestNode,nodes);
    int diameter = resultado2[0];

    cout << diameter;

    return 0;
}

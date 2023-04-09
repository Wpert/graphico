//
// Created by amoik on 09.04.2023.
//

#include "algos.h"

void dfsAlgo::start(size_t vertexIndex, TGraph &graph) {
    // podgotovka
    std::vector<bool> used(graph.GetVertexesSize() + 1);
    std::vector<std::vector<int>> adjacencyList = graph.adjacencyList();

    std::cout << "DFS has started" << std::endl;
    dfs(vertexIndex, graph, used, adjacencyList);

    for (auto i : used) {
        std::cout << i << std::endl;
    }
}

void
dfsAlgo::dfs(size_t vertexIndex, TGraph &graph, std::vector<bool> &used, std::vector<std::vector<int>> &adjacencyList) {
    if (graph.GetVertexesSize() == 0) return;
    used[vertexIndex] = true;
    graph.changeVertexColor(vertexIndex, activeOutlineColor);
    sf::sleep(sf::milliseconds(750));
    for (auto secondVertex : adjacencyList[vertexIndex]) {
        if (!used[secondVertex]) {
            dfs(secondVertex, graph, used, adjacencyList);
        }
    }
}
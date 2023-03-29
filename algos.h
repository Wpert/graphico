#pragma once
#include <vector>

// rename it to algo ?

void DFS(int vertexIndex,
         TGraph &graph,
         std::vector<bool> &used,
         std::vector<std::vector<int>> &adjacencyList) {
    if (vertexSerialNumber == 0) return;
    used[vertexIndex] = true;
    graph.changeVertexColor(vertexIndex, activeOutlineColor);
    sf::sleep(sf::milliseconds(750));
    for (auto secondVertex : adjacencyList[vertexIndex]) {
        if (!used[secondVertex]) {
            DFS(secondVertex, graph, used, adjacencyList);
        }
    }
}

std::vector<bool> StartDFS(int vertexIndex, TGraph &graph) {
    std::vector<bool> used(vertexSerialNumber + 1);
    std::vector<std::vector<int>> adjacencyList = graph.adjacencyList();
    std::cout << "DFS has started" << std::endl;
    DFS(vertexIndex, graph, used, adjacencyList);
    return used;
}

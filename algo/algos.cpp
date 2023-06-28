//
// Created by amoik on 09.04.2023.
//

#include "algos.h"

void dfsAlgo::start(size_t vertexIndex, TGraph &graph) {

    // basics to start algo
    std::vector<bool> used(graph.GetVertexesSize());
    std::vector<std::vector<int>> adjacencyList = graph.adjacencyList();

    std::cout << "DFS has started" << std::endl;

    dfs(vertexIndex,graph,used, adjacencyList);

//    for (auto i : used) {
//        std::cout << i << std::endl;
//    }
}

using namespace std::chrono_literals;

void dfsAlgo::dfs(size_t vertexIndex, TGraph &graph, std::vector<bool> &used,
                  std::vector<std::vector<int>> &adjacencyList) {
    if (graph.GetVertexesSize() == 0) return;

    used[vertexIndex] = true;
    graph.changeVertexColor(vertexIndex, activeOutlineColor);

    std::this_thread::sleep_for(750ms);

    for (auto secondVertex : adjacencyList[vertexIndex]) {
        if (!used[secondVertex]) {
            dfs(secondVertex, graph, used, adjacencyList);
        }
    }
}
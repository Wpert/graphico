#include "algos.h"

void startDFS(TAlgo &alg, size_t vertexIndex, TGraph &graph) {
    graph.CleanGraph();

    // basics to start algo
    alg.used_ = std::vector<bool>(graph.GetVertexesSize(), false);
    alg.adjacencyList_ = graph.adjacencyList();

    std::cout << "DFS has started" << std::endl;

    alg.dfs(vertexIndex,graph);

    for (auto i : alg.used_) {
        std::cout << i << std::endl;
    }

    alg.used_.clear();
    alg.adjacencyList_.clear();
}

void startBFS(TAlgo &alg, size_t vertexIndex, TGraph &graph) {
    graph.CleanGraph();

    // basics to start algo
    alg.used_ = std::vector<bool>(graph.GetVertexesSize(), false);
    alg.adjacencyList_ = graph.adjacencyList();
    alg.parent_ = std::vector<int>(graph.GetVertexesSize(), -1);

    std::cout << "BFS has started" << std::endl;

    alg.bfs(vertexIndex,graph);

    for (auto i : alg.parent_) {
        std::cout << i << std::endl;
    }

    alg.used_.clear();
    alg.adjacencyList_.clear();
    alg.parent_.clear();
}

using namespace std::chrono_literals;

void TAlgo::dfs(size_t vertexIndex, TGraph &graph) {
    if (graph.GetVertexesSize() == 0) return;

    used_[vertexIndex] = true;
    graph.changeVertexColor(vertexIndex, activeOutlineColor);

    std::this_thread::sleep_for(750ms);

    for (auto secondVertex : adjacencyList_[vertexIndex]) {
        if (!used_[secondVertex]) {
            graph.changeEdgeColor(vertexIndex, secondVertex, activeEdgeColor);
            std::this_thread::sleep_for(500ms);
            dfs(secondVertex, graph);
        }
    }
}

void TAlgo::bfs(size_t startVertex, TGraph &graph) {
    if (graph.GetVertexesSize() == 0) return;

    used_[startVertex] = true;
    parent_[startVertex] = startVertex;

    std::queue<int> q;
    q.push(startVertex);

    while(!q.empty()) {
        auto firstVertex = q.front();
        q.pop();

        graph.changeVertexColor(firstVertex, activeOutlineColor);
        std::this_thread::sleep_for(750ms);

        for (auto secondVertex : adjacencyList_[firstVertex]) {
            if (!used_[secondVertex]) {
                std::this_thread::sleep_for(500ms);
                graph.changeEdgeColor(firstVertex, secondVertex, activeEdgeColor);

                parent_[secondVertex] = firstVertex;
                used_[secondVertex] = true;
                q.push(secondVertex);
            }
        }


    }
}
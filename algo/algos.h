#ifndef FAV_ALGOS_H
#define FAV_ALGOS_H

#pragma once
#include <vector>
#include "../graphs/tgraph.h"
#include <thread>
#include <chrono>
#include <queue>

class TAlgo {
public:
    ~TAlgo() = default;

    void dfs(size_t vertexIndex, TGraph &graph);
    void bfs(size_t vertexIndex, TGraph &graph);

    std::vector<bool> used_;
    std::vector<std::vector<int>> adjacencyList_;

    std::vector<int> parent_;
    std::vector<int> dist_;
};

void startDFS(TAlgo &alg, size_t vertexIndex, TGraph &graph);
void startBFS(TAlgo &alg, size_t vertexIndex, TGraph &graph);

#endif //FAV_ALGOS_H

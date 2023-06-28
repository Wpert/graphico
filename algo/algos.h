#ifndef FAV_ALGOS_H
#define FAV_ALGOS_H

#pragma once
#include <vector>
#include "../graphs/tgraph.h"
#include <thread>
#include <chrono>

class dfsAlgo {
public:
    ~dfsAlgo() = default;
    static void dfs(size_t vertexIndex, TGraph &graph,
             std::vector<bool> &used,
             std::vector<std::vector<int>> &adjacencyList);
    void start(size_t vertexIndex, TGraph &graph);
};

#endif //FAV_ALGOS_H

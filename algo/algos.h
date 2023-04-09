//
// Created by amoik on 09.04.2023.
//

#ifndef FAV_ALGOS_H
#define FAV_ALGOS_H

#pragma once
#include <vector>
#include "../graphs/tgraph.h"

class IAlgo {
public:
    virtual ~IAlgo() {}
    virtual void start(size_t vertexIndex, TGraph &graph) = 0;
};

class dfsAlgo : public IAlgo {
public:
    ~dfsAlgo() = default;
    void dfs(size_t vertexIndex, TGraph &graph,
             std::vector<bool> &used,
             std::vector<std::vector<int>> &adjacencyList);
    void start(size_t vertexIndex, TGraph &graph) override;
};

#endif //FAV_ALGOS_H

#ifndef FAV_TSAMPLE_H
#define FAV_TSAMPLE_H

#pragma once
#include "../graphs/tgraph.h"

class TSample {
public:
    TGraph MakeComplex(sf::Font &vertexFont) {
        TGraph complex;
        complex.AddVertex(sf::Vector2f(300, 530), vertexFont, 0);
        complex.AddVertex(sf::Vector2f(300, 230), vertexFont, 1);

        complex.AddVertex(sf::Vector2f(400, 120), vertexFont, 2);

        complex.AddVertex(sf::Vector2f(500, 230), vertexFont, 3);
        complex.AddVertex(sf::Vector2f(500, 430), vertexFont, 4);

        complex.AddVertex(sf::Vector2f(600, 330), vertexFont, 5);
        complex.AddVertex(sf::Vector2f(600, 120), vertexFont, 6);

        complex.AddVertex(sf::Vector2f(700, 230), vertexFont, 7);
        complex.AddVertex(sf::Vector2f(700, 430), vertexFont, 8);

        complex.AddVertex(sf::Vector2f(800, 120), vertexFont, 9);

        complex.AddVertex(sf::Vector2f(900, 230), vertexFont, 10);
        complex.AddVertex(sf::Vector2f(900, 530), vertexFont, 11);

        complex.AddEdge({0, 1});
        complex.AddEdge({0, 4});
        complex.AddEdge({0, 11});
        complex.AddEdge({1, 2});
        complex.AddEdge({1, 3});
        complex.AddEdge({2, 3});
        complex.AddEdge({2, 6});
        complex.AddEdge({3, 4});
        complex.AddEdge({3, 5});
        complex.AddEdge({3, 6});
        complex.AddEdge({4, 5});
        complex.AddEdge({4, 8});
        complex.AddEdge({5, 7});
        complex.AddEdge({6, 7});
        complex.AddEdge({6, 9});
        complex.AddEdge({7, 8});
        complex.AddEdge({7, 9});
        complex.AddEdge({8, 11});
        complex.AddEdge({9, 10});
        complex.AddEdge({10, 11});

        return complex;
    }

    TGraph MakePentaGon(sf::Font &vertexFont) {
        TGraph pentaGon;
        pentaGon.AddVertex(sf::Vector2f(600, 200), vertexFont, 0);
        pentaGon.AddVertex(sf::Vector2f(702, 274), vertexFont, 1);
        pentaGon.AddVertex(sf::Vector2f(663, 394), vertexFont, 2);
        pentaGon.AddVertex(sf::Vector2f(537, 394), vertexFont, 3);
        pentaGon.AddVertex(sf::Vector2f(498, 274), vertexFont, 4);

        pentaGon.AddEdge({0, 1});
        pentaGon.AddEdge({0, 4});
        pentaGon.AddEdge({1, 2});
        pentaGon.AddEdge({2, 3});
        pentaGon.AddEdge({3, 4});
        return pentaGon;
    }

    TGraph MakeBinaryTree(sf::Font &vertexFont) {
        TGraph BinaryTree;
        BinaryTree.AddVertex(sf::Vector2f(512, 100), vertexFont, 0);

        BinaryTree.AddVertex(sf::Vector2f(392, 200), vertexFont, 1);
        BinaryTree.AddVertex(sf::Vector2f(632, 200), vertexFont, 2);

        BinaryTree.AddVertex(sf::Vector2f(332, 300), vertexFont, 3);
        BinaryTree.AddVertex(sf::Vector2f(452, 300), vertexFont, 4);
        BinaryTree.AddVertex(sf::Vector2f(572, 300), vertexFont, 5);
        BinaryTree.AddVertex(sf::Vector2f(692, 300), vertexFont, 6);

        BinaryTree.AddVertex(sf::Vector2f(302, 400), vertexFont, 7);
        BinaryTree.AddVertex(sf::Vector2f(362, 400), vertexFont, 8);
        BinaryTree.AddVertex(sf::Vector2f(422, 400), vertexFont, 9);
        BinaryTree.AddVertex(sf::Vector2f(482, 400), vertexFont, 10);
        BinaryTree.AddVertex(sf::Vector2f(542, 400), vertexFont, 11);
        BinaryTree.AddVertex(sf::Vector2f(602, 400), vertexFont, 12);
        BinaryTree.AddVertex(sf::Vector2f(662, 400), vertexFont, 13);
        BinaryTree.AddVertex(sf::Vector2f(722, 400), vertexFont, 14);

        BinaryTree.AddEdge({0, 1});
        BinaryTree.AddEdge({0, 2});

        BinaryTree.AddEdge({1, 3});
        BinaryTree.AddEdge({1, 4});
        BinaryTree.AddEdge({2, 5});
        BinaryTree.AddEdge({2, 6});

        BinaryTree.AddEdge({3, 7});
        BinaryTree.AddEdge({3, 8});
        BinaryTree.AddEdge({4, 9});
        BinaryTree.AddEdge({4, 10});
        BinaryTree.AddEdge({5, 11});
        BinaryTree.AddEdge({5, 12});
        BinaryTree.AddEdge({6, 13});
        BinaryTree.AddEdge({6, 14});
        return BinaryTree;
    }
};

#endif //FAV_TSAMPLE_H

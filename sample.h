// graphs

TGraph MakePentaGon() {
    TGraph pentaGon;
    pentaGon.AddVertex(sf::Vector2f(600, 200)); // 0
    pentaGon.AddVertex(sf::Vector2f(702, 274)); // 1
    pentaGon.AddVertex(sf::Vector2f(663, 394)); // 2
    pentaGon.AddVertex(sf::Vector2f(537, 394)); // 3
    pentaGon.AddVertex(sf::Vector2f(498, 274)); // 4

    pentaGon.AddEdge(TEdge(0, 1));
    pentaGon.AddEdge(TEdge(0, 4));
    pentaGon.AddEdge(TEdge(1, 2));
    pentaGon.AddEdge(TEdge(2, 3));
    pentaGon.AddEdge(TEdge(3, 4));
    return pentaGon;
}

TGraph MakeBinaryTree() {
    TGraph BinaryTree;
    BinaryTree.AddVertex(sf::Vector2f(512, 100)); // 0

    BinaryTree.AddVertex(sf::Vector2f(392, 200)); // 1
    BinaryTree.AddVertex(sf::Vector2f(632, 200)); // 2

    BinaryTree.AddVertex(sf::Vector2f(332, 300)); // 3
    BinaryTree.AddVertex(sf::Vector2f(452, 300)); // 4
    BinaryTree.AddVertex(sf::Vector2f(572, 300)); // 5
    BinaryTree.AddVertex(sf::Vector2f(692, 300)); // 6

    BinaryTree.AddVertex(sf::Vector2f(302, 400)); // 7
    BinaryTree.AddVertex(sf::Vector2f(362, 400)); // 8
    BinaryTree.AddVertex(sf::Vector2f(422, 400)); // 9
    BinaryTree.AddVertex(sf::Vector2f(482, 400)); // 10
    BinaryTree.AddVertex(sf::Vector2f(542, 400)); // 11
    BinaryTree.AddVertex(sf::Vector2f(602, 400)); // 12
    BinaryTree.AddVertex(sf::Vector2f(662, 400)); // 13
    BinaryTree.AddVertex(sf::Vector2f(722, 400)); // 14

    BinaryTree.AddEdge(TEdge(0, 1));
    BinaryTree.AddEdge(TEdge(0, 2));

    BinaryTree.AddEdge(TEdge(1, 3));
    BinaryTree.AddEdge(TEdge(1, 4));
    BinaryTree.AddEdge(TEdge(2, 5));
    BinaryTree.AddEdge(TEdge(2, 6));

    BinaryTree.AddEdge(TEdge(3, 7));
    BinaryTree.AddEdge(TEdge(3, 8));
    BinaryTree.AddEdge(TEdge(4, 9));
    BinaryTree.AddEdge(TEdge(4, 10));
    BinaryTree.AddEdge(TEdge(5, 11));
    BinaryTree.AddEdge(TEdge(5, 12));
    BinaryTree.AddEdge(TEdge(6, 13));
    BinaryTree.AddEdge(TEdge(6, 14));
    return BinaryTree;
}

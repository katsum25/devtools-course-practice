// Copyright 2021 Pestreev Daniil

#include <gtest/gtest.h>

#include <vector>

#include "include/connectivity_components.h"

TEST(Pestreev_connectivity_components, constructor_1) {
    ASSERT_NO_THROW(Graph g2());
}

TEST(Pestreev_connectivity_components, constructor_2) {
    ASSERT_NO_THROW(Graph g2(10));
}

TEST(Pestreev_connectivity_components, graph_with_one_vertex) {
    int N = 1;
    Graph g2(N);
    for (int i = 0 ; i < N; i++) {
        for (int j = i; j < N; j++) {
            g2.element(i, j) = 0;
            g2.element(j, i) = g2.element(i, j);
            if (i == j) g2.element(i, j) = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << g2.element(i, j) << " ";
        }
        std::cout << std::endl;
    }
    int res = g2.countConectComps();
    ASSERT_EQ(1, res);
}

TEST(Pestreev_connectivity_components, out_of_scope_index) {
    int N = 5;
    Graph g2(N);
    for (int i = 0 ; i < N; i++) {
        for (int j = i; j < N; j++) {
            g2.element(i, j) = i;
            g2.element(j, i) = g2.element(i, j);
            if (i == j) g2.element(i, j) = 0;
        }
    }
    ASSERT_ANY_THROW(g2.element(6, 6));
}

TEST(Pestreev_connectivity_components, out_of_scope_index_2) {
    int N = 5;
    Graph g2(N);
    for (int i = 0 ; i < N; i++) {
        for (int j = i; j < N; j++) {
            g2.element(i, j) = i;
            g2.element(j, i) = g2.element(i, j);
            if (i == j) g2.element(i, j) = 0;
        }
    }
    ASSERT_ANY_THROW(g2.element(-1, 3));
}


TEST(Pestreev_connectivity_components, complete_simple_graph) {
    int N = 10;
    Graph g2(N);
    for (int i = 0 ; i < N; i++) {
        for (int j = i; j < N; j++) {
            g2.element(i, j) = 1;
            g2.element(j, i) = g2.element(i, j);
            if (i == j) g2.element(i, j) = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << g2.element(i, j) << " ";
        }
        std::cout << std::endl;
    }
    int res = g2.countConectComps();
    ASSERT_EQ(1, res);
}

TEST(Pestreev_connectivity_components, empty_graph) {
    int N = 10;
    Graph g2(N);
    for (int i = 0 ; i < N; i++) {
        for (int j = i; j < N; j++) {
            g2.element(i, j) = 0;
            g2.element(j, i) = g2.element(i, j);
            if (i == j) g2.element(i, j) = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << g2.element(i, j) << " ";
        }
        std::cout << std::endl;
    }
    int res = g2.countConectComps();
    ASSERT_EQ(10, res);
}

TEST(Pestreev_connectivity_components, multi_graph) {
    int N = 10;
    Graph g2(N);
    for (int i = 0 ; i < N; i++) {
        for (int j = i; j < N; j++) {
            g2.element(i, j) = i;
            g2.element(j, i) = g2.element(i, j);
            if (i == j) g2.element(i, j) = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << g2.element(i, j) << " ";
        }
        std::cout << std::endl;
    }
    int res = g2.countConectComps();
    ASSERT_EQ(2, res);
}

TEST(Pestreev_connectivity_components, some_simple_graph) {
    int N = 7;
    Graph g2(N);
    std::vector<std::vector<int>> matrix = {
        {0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < N; j++) {
            g2.element(i, j) = matrix[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << g2.element(i, j) << " ";
        }
        std::cout << std::endl;
    }
    int res = g2.countConectComps();
    ASSERT_EQ(3, res);
}

TEST(Pestreev_connectivity_components, some_multi_graph) {
    int N = 8;
    Graph g2(N);
    std::vector<std::vector<int>> matrix = {
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 1, 0, 1, 0}
    };
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < N; j++) {
            g2.element(i, j) = matrix[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << g2.element(i, j) << " ";
        }
        std::cout << std::endl;
    }
    int res = g2.countConectComps();
    ASSERT_EQ(2, res);
}

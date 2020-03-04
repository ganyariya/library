#pragma once

/**
 * @file unionfind.hpp
 * @brief UnionFindTree
 */

#include "../include/include.hpp"

class UnionFind {

public:

    vector<int> par;
    vector<int> sizes;
/**
     * @brief $get\_connectivity()$: return the number of connectivity
     */
    UnionFind(int n)
            : par(n), sizes(n, 1) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    /**
     * @brief $root$\_$of(a)$：頂点$a$を含む連結成分の代表元
     */
    int find(int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }
/**
     * @brief $get\_connectivity()$: return the number of connectivity
     */
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (sizes[x] < sizes[y]) swap(x, y);
        par[y] = x;
        sizes[x] += sizes[y];
        return true;
    }
/**
     * @brief $get\_connectivity()$: return the number of connectivity
     */
    bool same(int x, int y) {
        return find(x) == find(y);
    }
/**
     * @brief $get\_connectivity()$: return the number of connectivity
     */
    int get_size(int x) {
        return sizes[find(x)];
    }
/**
     * @brief $get\_connectivity()$: return the number of connectivity
     */
    bool all_same() {
        bool good = true;
        for (int i = 0, n = par.size(); i < n; i++) if (find(0) != find(i)) good = false;
        return good;
    }

    /**
     * @brief $get\_connectivity()$: return the number of connectivity
     */
    int get_connectivity() {
        set<int> s;
        for (int i = 0, n = par.size(); i < n; i++) s.insert(find(i));
        return s.size();
    }

private:

};



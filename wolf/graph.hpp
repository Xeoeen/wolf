#pragma once

#include <cassert>
#include <queue>
#include <vector>
#include "utils.hpp"

namespace wolf::graph {
    template<typename T>
    struct BaseEdge {
        int from, to;
        T cost;
    };

    template<typename Edge>
    struct Graph {
        Graph(int size):edges(size), size(size) {}
        void addEdge(const Edge& edge) { edges[edge.from].push_back(edge); }
        void addEdgeBiDir(Edge edge) {
            addEdge(edge);
            swap(edge.from, edge.to);
            addEdge(edge);
        }

        template<typename PreV, typename PostV, typename PreE, typename PostE>
        std::vector<bool> dfs(int vertex, PreV prev, PostV postv, PreE pree, PostE poste);
        
        template<typename PreE, typename PostE>
        std::vector<bool> dfs(int vertex, PreE pree, PostE poste) { return dfs(vertex, wolf::neutral(), wolf::neutral(), pree, poste); }
        
        template<typename PreV, typename PostV, typename PreE, typename PostE>
        void implDfs(int vertex, std::vector<bool>& vis, PreV prev, PostV postv, PreE pree, PostE poste);
        
        template<typename F>
        void forAllEdges(F f) const {
            for(auto& pack : edges)
                for(auto& edge : pack)
                    f(edge);
        }

        std::vector<std::vector<Edge>> edges;
        int size;
    };
        
    template<typename Edge> template<typename PreV, typename PostV, typename PreE, typename PostE>
    std::vector<bool> Graph<Edge>::dfs(int vertex, PreV prev, PostV postv, PreE pree, PostE poste) {
        std::vector<bool> vis(size);
        implDfs(vertex, vis, prev, postv, pree, poste);
        return vis;
    }
    
    template<typename Edge> template<typename PreV, typename PostV, typename PreE, typename PostE>
    void Graph<Edge>::implDfs(int vertex, std::vector<bool>& vis, PreV prev, PostV postv, PreE pree, PostE poste) {
        prev(vertex);
        vis[vertex] = true;

        for(auto& edge : edges[vertex]) {
            if(not vis[edge.to]) {
                pree(edge);
                implDfs(edge.to, vis, prev, postv, pree, poste);
                poste(edge);
            }
        }
        postv(vertex);
    }

    template<typename Edge, typename F>
    void toposort(const Graph<Edge>& graph, F f) {
        auto inDegree = std::vector<int>(graph.size);
        graph.forAllEdges([&inDegree](auto& edge) { ++inDegree[edge.to]; });

        std::queue<int> Q;
        for(int idx = 0 ; idx < graph.size ; ++idx)
            if(inDegree[idx] == 0)
                Q.push(idx);
        
        assert(!Q.empty());
        while(not Q.empty()) {
            auto now = Q.front(); Q.pop();
            for(auto& edge : graph.edges[now])
                if(--inDegree[edge.to] == 0)
                    Q.push(edge.to);
            f(now);
        }
    }
}


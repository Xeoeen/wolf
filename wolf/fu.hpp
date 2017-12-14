#pragma once

#include<vector>

namespace wolf::fu{

    struct SmallFindUnion {
        SmallFindUnion(int size):point(size) {
            int counter = -1;
            for(auto& it: point)
                it = ++counter;
        }

        int find(int to) {
            return point[to] == to ? to : point[to] = find(point[to]);
        }

        bool canUnion(int x, int y) {
            return find(x) != find(y);
        }

        bool tryUnion(int x, int y) {
            int p1 = find(x), p2 = find(y);
            if(p1 == p2)
                return false;

            point[p1] = p2;
            return true;
        }

        std::vector<int> point;
    };

    struct FindUnion {
        FindUnion(int size):point(size), rank(size){
            int counter = -1;
            for(auto& it: point)
                it = ++counter;
        }

        int find(int to) {
            return point[to] == to ? to : point[to] = find(point[to]);
        }

        bool canUnion(int x, int y) {
            return find(x) != find(y);
        }

        bool tryUnion(int x, int y) {
            int p1 = find(x), p2 = find(y);
            if(p1 == p2)
                return false;
            if(rank[p1] < rank[p2]) {
                point[p1] = p2;
            }
            else if(rank[p1] == rank[p2]) {
                point[p2] = p1;
                rank[p1]++;
            }
            else {
                point[p1] = p2;
            }

            point[p1] = p2;
            return true;
        }

        std::vector<int> point;
        std::vector<int> rank;
    };

}

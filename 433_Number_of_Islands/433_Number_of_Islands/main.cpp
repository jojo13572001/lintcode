//
//  main.cpp
//  433_Number_of_Islands
//
//  Created by Mac on 2019/9/20.
//  Copyright © 2019年 Mac. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        int rowNum = grid.size();
        int colNum = 0;
        if (rowNum > 0) {
            colNum = grid[0].size();
        }
        //init bfs
        int numIslands = 0;
        
        queue<pair<int,int>> queuedNode;
        set<pair<int,int>> visitedNode;
        
        //Check all nodes that never visited
        for(int i=0; i<rowNum; i++) {
            for(int j=0; j<colNum; j++) {
                auto node = make_pair(i,j);
                if (grid[i][j] && visitedNode.count(node) == 0) {
                    bfs(node, grid, queuedNode, visitedNode);
                    numIslands++;
                }
                else {
                    continue;
                }
            }
        }
        return numIslands;
    }
    
    //bfs search node
    void bfs(pair<int,int> node, const vector<vector<bool>> &grid,
             queue<pair<int,int>> &queuedNode, set<pair<int,int>> &visitedNode) {
        //push node i into queue and set visitedNode
        queuedNode.push(node);
        visitedNode.insert(node);
        while (!queuedNode.empty()) {
            node = queuedNode.front();
            queuedNode.pop();
            insertNeighbor(make_pair(node.first, node.second-1), grid, queuedNode, visitedNode);
            insertNeighbor(make_pair(node.first, node.second+1), grid, queuedNode, visitedNode);
            insertNeighbor(make_pair(node.first-1, node.second), grid, queuedNode, visitedNode);
            insertNeighbor(make_pair(node.first+1, node.second), grid, queuedNode, visitedNode);
        }
    }
    
    void insertNeighbor(pair<int,int> node, const vector<vector<bool>> &grid,
                        queue<pair<int,int>> &queuedNode, set<pair<int,int>> &visitedNode) {
        int rowNum = grid.size();
        int colNum = grid[0].size();
        if (node.first>=0 && node.first<rowNum && node.second>=0 && node.second<colNum) {
            if (grid[node.first][node.second] && visitedNode.count(node) == 0) {
                queuedNode.push(node);
                visitedNode.insert(node);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

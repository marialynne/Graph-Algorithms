#include <vector>
#include <utility>
#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

float findMaxFlow(vector<vector<float>> graph, vector<vector<float>> &auxGraph, int source, int destination);

void maxFlow(vector<vector<float>> graph, int numNodes) // Time: O(1)
{
  vector<vector<float>> auxMatrix = graph;
  int initialNode = 0, finalNode = numNodes - 1;
  float maximumFlow = findMaxFlow(graph, auxMatrix, initialNode, finalNode);
  cout << "\n[Maximum flow]: " << maximumFlow << "\n";
}

float BSF(vector<vector<float>> residualGraph, int source, int destination, vector<int> &prevConnection) // Time: O(n²)
{
  queue<int> bsfQueue;
  fill(prevConnection.begin(), prevConnection.end(), -1);
  prevConnection[source] = -2;
  bsfQueue.push(source);
  float flow = INFINITY;

  while (!bsfQueue.empty())
  {
    int currentNode = bsfQueue.front();
    bsfQueue.pop();

    for (int nextNode = 0; nextNode < residualGraph.size(); nextNode++)
    {
      if (prevConnection[nextNode] == -1 && residualGraph[currentNode][nextNode] > 0)
      {
        prevConnection[nextNode] = currentNode;
        float nextFlow = min(flow, residualGraph[currentNode][nextNode]);
        if (nextNode == destination)
        {
          return nextFlow;
        }
        flow = nextFlow;
        bsfQueue.push(nextNode);
      }
    }
  }
  return -1;
}

float findMaxFlow(vector<vector<float>> graph, vector<vector<float>> &auxGraph, int source, int destination) // Time: O(E*f) Edge * flow
{
  float flow = 0;
  vector<int> prevConnection(graph.size(), -1);
  float newFlow = 0;

  newFlow = BSF(auxGraph, source, destination, prevConnection);
  while (newFlow >= 0)
  {
    flow += newFlow;
    for (int index = destination; index != source; index = prevConnection[index])
    {
      int prevNode = prevConnection[index];
      auxGraph[prevNode][index] -= newFlow;
      auxGraph[index][prevNode] += newFlow;
    }
    newFlow = BSF(auxGraph, source, destination, prevConnection);
  }

  return flow;
}

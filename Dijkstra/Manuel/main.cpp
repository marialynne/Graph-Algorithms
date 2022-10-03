#include <vector>
#include <set>
using namespace std;
vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges);

int main()
{
    int start = 1;
    vector<vector<vector<int>>> edges;

    dijkstrasAlgorithm(start, edges);

    return 0;
}

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges)
{
    int n = edges.size();
    vector<int> dist_ans(n, -1);
    set<pair<int, int>> dist;
    dist_ans[start] = 0;

    while (!dist.empty())
    {
        auto node = dist.begin()->second;
        dist.erase(dist.begin());

        for (int i = 0; i < edges[node].size(); i++)
        {
            int dest = edges[node][i][0];
            int weight = edges[node][i][1];
            int new_weight = dist_ans[node] + weight;

            if (dist_ans[dest] == -1 || (new_weight < dist_ans[dest]))
            {
                dist_ans[dest] = new_weight;
                dist.emplace(new_weight, dest);
            }
        }
    }

    return dist_ans;
}

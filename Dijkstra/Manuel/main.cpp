#include <vector>
#include <set>
#include <iostream>
using namespace std;
vector<vector<vector<int>>> getData();
vector<vector<vector<int>>> convertDataToEdges(vector<vector<int>> data);
void print(vector<vector<int>> data);
vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges);

int main()
{
    int start = 1;
    vector<vector<vector<int>>> edges = getData();

    dijkstrasAlgorithm(start, edges);

    return 0;
}

vector<vector<vector<int>>> getData()
{
    int n, input;
    cout << "Please, enter n: ";
    cin >> n; // Here should go n to verification (positive integer)

    vector<vector<int>> data(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> input;
            data[i][j] = input; // here should go input to verification (integer, input >= -1 )
        }
    }

    print(data);

    return convertDataToEdges(data);
}

vector<vector<vector<int>>> convertDataToEdges(vector<vector<int>> data)
{
    vector<vector<vector<int>>> edges;
    vector<vector<int>> node;
    vector < int >> vertexWeight;

    return edges;
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

void print(vector<vector<int>> data)
{
    for (auto i : data)
    {
        cout << "\t";
        for (auto j : data[0])
            cout << i[j] << " ";
        cout << "\n";
    }
}

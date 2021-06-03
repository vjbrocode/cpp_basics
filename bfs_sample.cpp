#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_set<string> uniqueNodeNames;
unordered_map<string, vector<std::string> > adj;

void addEdge(std::string u, std::string v)
{
    if(adj.find(u) == adj.end()) {
        adj[u] = vector<std::string>();
    }
    adj[u].push_back(v);
}

void printGraph()
{
    std::cout << "Printing entire graph:\n";
    for (std::unordered_map<string, vector<std::string> >::iterator it=adj.begin(); it!=adj.end(); ++it){
            std::string key = it->first;
            vector<std::string> value = it->second;
            std::cout << key << "->";
            for(std::size_t i = 0; i < value.size(); i++) {
                std::cout << value[i] << " ";
            }
            std::cout << "\n";
    }
}

void bfs(std::string fromNode, unordered_map<string, bool> visited) {
    vector<std::string> result;

    queue<std::string> queue;

    queue.push(fromNode);

    while(!queue.empty()) {
        std::string node = queue.front();
        queue.pop();

        result.push_back(node);

        vector<std::string> connectedNodes = adj[node];

        for(std::size_t i = 0; i < connectedNodes.size(); i++) {
            std::string n = connectedNodes[i];
            if(visited.find(n) == visited.end()) {
                visited[n] = true;
                if(n != "None") {
                    queue.push(n);
                }
            }
        }
           
    }

    std::cout << "Reading result now...\n";
    std::cout << "Nodes from " + fromNode + " = ";
    for(std::size_t i = 0; i < result.size(); i++) {
        std::string node = result[i];
        
        std::cout << " -> " + node + " ";
    }
    std::cout << "\n\n\n";
}

void findReachableNodes(std::string fromNode) {
    int numOfNodes = uniqueNodeNames.size();
    std::cout << "Num of nodes = " << numOfNodes << "\n";

    unordered_map<string, bool> visited;

    if(visited.find(fromNode) == visited.end()) {
        visited[fromNode] = true;
    }

    bfs(fromNode, visited);
}

int main()
{
    std::cout << "PROGRAM START...\n";
    std::string fileName = "/inputfiles/GraphInputFile.CSV";
    ifstream in(fileName);
    vector<vector<std::string> > fields;
    std::cout << "Reading csv file...\n";
    if (in) {
        string line;

        while (getline(in, line)) {
            stringstream sep(line);
            string field;
            std::cout<< "line = " + line << "\n";
            fields.push_back(vector<std::string>());

            while (getline(sep, field, ',')) {
                //std::cout<< "field = " + field << "\n";
                fields.back().push_back(field);
            }
        }
    }

    std::cout << "Reading vector now...\n";
    for(std::size_t i = 1; i < fields.size(); i++) {
        vector<std::string> v = fields[i];
        
        uniqueNodeNames.insert(v[1]);
        uniqueNodeNames.insert(v[2]);
        addEdge(v[1], v[2]);
        
        std::cout << "Adding Edge: " + v[1] + " -> " + v[2] + "\n";
    }
    
    printGraph();

    findReachableNodes("A");
    findReachableNodes("B");
    findReachableNodes("C");
    findReachableNodes("D");
    findReachableNodes("E");
    findReachableNodes("F");

    std::cout << "PROGRAM END...\n";
}

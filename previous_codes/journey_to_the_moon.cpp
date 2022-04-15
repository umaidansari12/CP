int dfs(int node, vector<int> graph[], bool *visited)
{
    int count = 1;
    visited[node] = true;
    for (auto neighbour : graph[node])
        if (!visited[neighbour])
            count += dfs(neighbour, graph, visited);
    return count;
}
long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<int> graph[n];
    int m = astronaut.size();
    for (int i = 0; i < m; i++)
    {
        graph[astronaut[i][0]].push_back(astronaut[i][1]);
        graph[astronaut[i][1]].push_back(astronaut[i][0]);
    }
    bool visited[n] = {false};
    vector<int> components;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            components.push_back(dfs(i, graph, visited));
        }
    }
    int size = components.size();
    long long int ans = 0;
    // vector<int> prefix(size,0);
    // prefix[size-1]=components[size-1];
    // for(int i=size-2;i>=0;i--)
    // {
    //     prefix[i]=components[i]+prefix[i+1];
    // }
    // for(int i=0;i<size-1;i++)
    // {
    //         ans+=(components[i]*prefix[i+1]);
    // }
    long long int sum = 0, result = 0;
    for (int size : components)
    {
        result += sum * size;
        sum += size;
    }
    return result;
    //return ans;





}

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the journeyToMoon function below.
long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<int>graph[n];
    int m=astronaut.size();
    for(int i=0;i<m;i++)
    {
        graph[astronaut[i][0]].push_back(astronaut[i][1]);
        graph[astronaut[i][1]].push_back(astronaut[i][0]);
    }
    int arr[n]={0},visited[n]={0};
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(visited[i])
            continue;
        q.push(i);
        visited[i]=1;
        arr[i]++;
        while(!q.empty())
        {
            int ver=q.front();
            q.pop();
            for(int j=0;j<graph[ver].size();j++)
            {
                if(!visited[graph[ver][j]])
                {
                    arr[i]++;      
                    visited[graph[ver][j]]=1;
                    q.push(graph[ver][j]);
                }
            }
        }
    }
    long long sqsum=0,sumsq=0;
    for(int i=0;i<n;i++)
    {
        sumsq+=arr[i]*arr[i];
        sqsum+=arr[i];
    }
    sqsum*=sqsum;
    return (sqsum-sumsq)/2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

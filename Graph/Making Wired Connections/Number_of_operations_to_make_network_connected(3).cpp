class Solution {
public:
    
    void make_set(int parent[],int rank[],int n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }

    int find_set(int parent[],int ver)
    {
        if(ver==parent[ver])
            return ver;
        return parent[ver]=find_set(parent,parent[ver]);
    }

    int numConnectedComp(vector<vector<int>>v,int n)
    {
        int rank[n],parent[n];
        make_set(parent,rank,n);
        int e=v.size();
        for(int i=0;i<e;i++)
        {
            int s=v[i][0],d=v[i][1],a=find_set(parent,s),b=find_set(parent,d);
            if(a!=b)
            {
                if(rank[a]<rank[b])
                    swap(a,b);
                parent[b]=a;
                if(rank[a]==rank[b])
                    rank[a]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
                ans++;
        }
        return ans;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        if(m<n-1)
            return -1;
        return numConnectedComp(connections,n)-1;
    }
};
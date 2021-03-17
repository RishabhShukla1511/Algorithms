class Solution {
public:
    
    void fillim(vector<vector<int>>&image,int x,int y,int c)
    {
        int n=image.size(),m=image[0].size();
        vector<vector<int>>visited;
        vector<int>temp;
        for(int i=0;i<m;i++)
            temp.push_back(0);
        for(int i=0;i<n;i++)
            visited.push_back(temp);
        queue<pair<int,int>>q;
        q.push({x,y});
        int reqc=image[x][y];
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            if(p.first>=0 && p.first<n && p.second>=0 && p.second<m && visited[p.first][p.second]==0 && image[p.first][p.second]==reqc)
            {    
                visited[p.first][p.second]=1;
                image[p.first][p.second]=c;
                for(int i=0;i<4;i++)
                    q.push({p.first+dx[i],p.second+dy[i]});
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)     {
        fillim(image,sr,sc,newColor);
        return image;
    }
};
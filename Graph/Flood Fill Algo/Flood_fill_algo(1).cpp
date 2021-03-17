class Solution {
public:
    
    bool isSafe(int x,int y,int reqc,vector<vector<int>>&image,vector<vector<int>>&visited)
    {
        int n=image.size(),m=image[0].size();
        return (x>=0 && x<n && y>=0 && y<m && image[x][y]==reqc && visited[x][y]==0);
    }
    
    void fill(vector<vector<int>>&image,int x,int y,int c,int reqc,vector<vector<int>>&visited)
    {
        image[x][y]=c;
        visited[x][y]=1;
        if(isSafe(x-1,y,reqc,image,visited))
            fill(image,x-1,y,c,reqc,visited);
        if(isSafe(x+1,y,reqc,image,visited))
            fill(image,x+1,y,c,reqc,visited);
        if(isSafe(x,y+1,reqc,image,visited))
            fill(image,x,y+1,c,reqc,visited);
        if(isSafe(x,y-1,reqc,image,visited))
            fill(image,x,y-1,c,reqc,visited);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)         {
        vector<vector<int>>visited;
        int n=image.size(),m=image[0].size();
        vector<int>temp;
        for(int j=0;j<m;j++)
            temp.push_back(0);
        for(int i=0;i<n;i++)
            visited.push_back(temp);
        fill(image,sr,sc,newColor,image[sr][sc],visited);
        return image;
    }
};
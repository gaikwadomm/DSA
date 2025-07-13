#include<iostream>
#include<vector>
using namespace std;
//LRUD
int row[] = {-1,1,0,0};
int col[] = {0,0,-1,1};
string dir = "UDLR";

bool isValid(int i, int j, int n){
    return i>=0 && j>=0 && i<n && j<n;
}

void ratMaze(vector<vector<int>>& maze, int i, int j, int n, string path, vector<string>& ans, vector<vector<int>>& visited){
    if((i==n-1 && j == n-1)){
        ans.push_back(path);
        return;
    }
    visited[i][j] = 1;
    for(int k=0;k<4;k++){
        if(isValid(i+row[k], j+col[k], n) && maze[i+row[k]][j+col[k]] && !visited[i+row[k]][j+col[k]]){
            path.push_back(dir[k]);
            ratMaze(maze, i+row[k], j+col[k], n, path, ans, visited);
            path.pop_back();
        }
    }
    visited[i][j] = 0;
}

int main(){
    vector<vector<int>> maze = {{1,0,0,0}, {1,1,0,1}, {1,1,1,1}, {1,1,1,1}};
    vector<string> ans;
    int n = maze[0].size();
    vector<vector<int>> visited(n ,vector<int>(n,0));
    string path = "";
    ratMaze(maze, 0, 0, n, path, ans, visited);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}

//left
    // if(j-1>=0){
    //     if(maze[i][j-1]!=0){
    //         if(visited[i][j-1]!=1){
    //             path.push_back('L');
    //             ratMaze(maze, i, j-1, n, path, ans, visited);
    //         }
    //     }
    // }
    // //Up
    // if(i-1>=0){
    //     if(maze[i-1][j]!=0){
    //         if(visited[i-1][j]!=1){
    //             path.push_back('U');
    //             ratMaze(maze, i-1, j, n, path, ans, visited);
    //         }
    //     }
    // }

    // //Right
    // if(j+1<n){
    //     if(maze[i][j+1]!=0){
    //         if(visited[i][j+1]!=1){
    //             path.push_back('R');
    //             ratMaze(maze, i, j+1, n, path, ans, visited);
    //         }
    //     }
    // }

    // //Down
    // if(i+1<n){
    //     if(maze[i+1][j]!=0){
    //         if(visited[i+1][j]!=1){
    //             path.push_back('D');
    //             ratMaze(maze, i+1, j, n, path, ans, visited);
    //         }
    //     }
    // }
    
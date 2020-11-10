//Q: https://www.chegg.com/homework-help/questions-and-answers/atlassian-university-software-x-h-hacker-rank-ha-h-ackerrankcom-test-51013iphbgr-questions-q43765379

#include <bits/stdc++.h>
using namespace std;


int cnt = 0;

void dfs(int node,vector<vector<int>>&grid,vector<bool>&vis)
{
    vis[node]=true;
    cnt++;
  
      for(int i=0;i<grid[node].size();i++)
      {
        int u = grid[node][i];
           if(vis[u]==false)
           {
               dfs(u,grid,vis);
           }
      }
}

int find_component_val(vector<vector<int>>&comp,int nodes)
{
    vector<vector<int>>grid(1000);
    
    for(auto &x : comp)
    {
        grid[x[0]].push_back(x[1]);
        grid[x[1]].push_back(x[0]);
    }
    //cout<<1<<endl;
    vector<bool>vis(nodes+1,false);
    vector<int>res;

    for(int i=1;i<=nodes;i++)
    {
        if(vis[i]==false)
        {
          dfs(i,grid,vis);
          res.push_back(cnt);
          cnt=0;
        }
    }
    int sum=0;
    for(int i=0;i<res.size();i++)
    {
        sum+=ceil(sqrt(res[i]));
    }
    
    return sum;
    
}


int main()
{
   vector<vector<int>>comp;
   comp.push_back({1,2});
   comp.push_back({1,3});
   comp.push_back({2,4});
   comp.push_back({3,5});
   comp.push_back({7,8});
   int n=10;
   
   cout<<find_component_val(comp,n)<<endl;
	return 0;
}

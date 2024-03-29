
/*We define the following:

There are friends_nodes friends numbered from 1 to friends_nodes.
There are friends_edges pairs of friends, where each (xi, yi) pair of friends is connected by a shared integer Interest described by friends_weighti.
Any two friends, xi and yi, can be connected by zero or more Interest because if friends xi and yi
share Interest ti and friends yi and zi also share Interest ti, then xi and zi are also said to share Interest ti.

Find the maximal product of xi and yi for any directly or indirectly connected (xi, yi) pair of
friends such that xi and yi share the maximal number of Interest with each other.

Name Type Description
friends_nodes integer The number of friends.
friends_from integer array Each friends_from[i] (where 0 ≤ i < friends_edges) denotes the first friend in pair (friends_from[i], friends_to[i]).
friends_to integer array Each friends_to[i] (where 0 ≤ i < friends_edges) denotes the second friend in pair (friends_from[i], friends_to[i]).
friends_weight integer array Each friends_weight[i] (where 0 ≤ i < friends_edges) denotes the ID number of a Interest shared by both friends_from[i] and friends_to[i].
Note: friends_edges is the number of pairs of friends that directly share a Interest.

The function must return an integer denoting the maximal product of xi and yi such that xi and yi are a pair of 
friends that share the maximal number of Interest with each other.

Input Format
The first line contains two space-separated integers describing the respective values of friends_nodes and friends_edges.
Each line i of the friends_edges subsequent lines (where 0 ≤ i < friends_edges) contains three space-separated
integers describing the respective values of friends_fromi, friends_toi, and friends_weighti.

Constraints

2 ≤ friends_nodes ≤ 100
1 ≤ friends_edges ≤ min(200, (friends_nodes × (friends_nodes − 1)) / 2)
1 ≤ friends_weighti ≤ 100
1 ≤ friends_fromi, friends_toi ≤ friends_nodes
1≤ friends_weighti ≤ friends_edges
friends_fromi ≠ friends_toi
Each pair of friends can be connected by zero or more types of Interest.

Output Format
Return an integer denoting the maximal product of xi and yi such
that xi and yi are a pair of friends that share the maximal number of Interest with each other.

Sample Input 0
4 5
1 2 1
1 2 2
2 3 1
2 3 3
2 4 3

Sample Output 0
6

Explanation 0
Each pair of n = 4 friends is connected by the following Interest:

Pair (1, 2) shares 2 Interest (i.e., Interest 1 and 2)
Pair (1, 3) shares 1 Interest (i.e., Interest 1)
Pair (1, 4) shares 0 Interest
Pair (2, 3) shares 2 Interest (i.e., Interest 1 and 3)
Pair (2, 4) shares 1 Interest (i.e., Interest 3)
Pair (3, 4) shares 1 Interest (i.e., Interest 3)

The pairs connected by the maximal number of Interest are (1, 2) and (2, 3). 
Their respective products are 1 × 2 = 2 and 2 × 3 = 6. We then return the largest of these values as our answer, which is 6.

*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<int,vector<vector<int>>>parent;        //stores adj list of each interest
vector<vector<int>>arr;                      // arr[i][j] stores the no of interests bw i and j
void combin(vector<int>&a);                  //finds all combinations of size 2 of elements in a and updates
                                                      //that index in arr. For each i,j in a(i!=j), arr[i][j]++ (means one more common  interest of i and j)
vector<int> bfs(int interest, int node, vector<bool>&visited);         //bfs on graph of 'interest'
                                                    //starting from vertex 'node' and returns the vertices in the connected component

int main() {
	
	int v,e;
	cin>>v>>e;
	arr.resize(v+1,vector<int>(v+1,0));
	for(int i=0;i<e;i++)
	{
		int a,b,in;
		cin>>a>>b>>in;
		if(parent.find(in)==parent.end())
			parent[in] = vector<vector<int>>(v+1,vector<int>());
		parent[in][a].push_back(b); //adding an edge to the graph of 'in'
	}
	
	for(auto it:parent)
	{
		vector<bool>visited(v+1,false);
		for(int i=1;i<=v;i++)
		{
			if(!visited[i]&&it.second[i].size()>0) //new connected component
			{
				vector<int>comp = bfs(it.first,i,visited);
				combin(comp);
			}
		}
	}
	//now we need to find max(i*j) such that arr[i][j] is maximal
        int ans = 0;
	int maximal = 0;
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
			if(arr[i][j]>maximal)
			{
				maximal = arr[i][j];
				ans = i*j;
			}
			else if (arr[i][j]==maximal)
			{
				ans = max(ans,i*j);
			}
		}
	}

	cout<<ans<<"\n";
}

//bfs on graph of interest starting from vertex 'node' 
// and return the vertices in the connected component
vector<int> bfs(int interest, int node, vector<bool>&visited)
{
	vector<int>ans;
	vector<vector<int>>adj = parent[interest];
	queue<int>Q;
	Q.push(node);
	while(Q.size())
	{
		int p = Q.front();
		Q.pop();
		if(visited[p])
			continue;
		visited[p] = true;
		ans.push_back(p);
		for(int i: adj[p])
		{
			if(!visited[i])
			{
				Q.push(i);
			}
		}
	}
	return ans;
}

//finds all combinations of size 2 of elements in a and updates that index in arr.
// For each i,j in a(i!=j), arr[i][j]++; //means one more common interest of i and j
void combin(vector<int>&a)
{
	for(int i=0;i<a.size()-1;i++)
	{
		for(int j=i+1;j<a.size();j++)
		{
			arr[a[i]][a[j]]++;
		}
	}
}

/*
There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
 

Constraints:

The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
The size of flights will be in range [0, n * (n - 1) / 2].
The format of each flight will be (src, dst, price).
The price of each flight will be in the range [1, 10000].
k is in the range of [0, n - 1].
There will not be any duplicated flights or self cycles.
*/

typedef pair <int, int> P;
typedef tuple <int, int, int> T;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        unordered_map <int, vector <P> > adj;
        int u, v, w, result, k;
        for (const auto& flight: flights){
            tie(u, v, w) = make_tuple(flight[0], flight[1], flight[2]);
            adj[u].emplace_back(v, w);
        }
        
        unordered_map <int, unordered_map <int, int> > best;
        priority_queue <T, vector <T>, greater<T> > minheap;
        
        minheap.emplace(0, src, K+1);
        while (!minheap.empty()){
            tie(result, u, k) = minheap.top();
            minheap.pop();
            
            if (k < 0 || (best.count(u) && best[u].count(k) && best[u][k] < result)){
                continue;
            }
            
            if (u == dst){
                return result;
            }
            
            for (const auto& i : adj[u]){
                tie(v, w) = i;
                if (!best.count(v) || !best[v].count(k-1) || result + w < best[v][k-1]){
                    best[v][k-1] = result + w;
                    minheap.emplace(result + w, v, k-1);
                }
            }
        }
        return -1;
    }
};
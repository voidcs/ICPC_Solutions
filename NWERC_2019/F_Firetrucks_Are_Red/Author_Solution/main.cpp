#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct UnionFind {
	vector<int> par, rank, size; int c;
	UnionFind(int n) : par(n), rank(n,0), size(n,1), c(n) {
		for (int i = 0; i < n; ++i) par[i] = i;
	}
	int find(int i) { return (par[i] == i ? i : (par[i] = find(par[i]))); }
	bool same(int i, int j) { return find(i) == find(j); }
	int get_size(int i) { return size[find(i)]; }
	int count() { return c; }
	int merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return -1; else --c;
        i = find(i), j = find(j);
        if(i == j)
            return -1;
		//if (rank[i] > rank[j]) swap(i, j);
		par[i] = j;
		//if (rank[i] == rank[j]) rank[j]++;
		//return j;
	}
};

struct S{int i, j, n;};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n; cin >> n;
	UnionFind uf(n);
	map<int, int> root;
	vector<S> ans;
	for(int i = 0; i < n; ++i){
		int m; cin >> m;
		while(m--){
		int x; cin >> x;
            int r;
            if(root.count(x)){
                r = root[x];
                if(!uf.same(i, r)){
                    uf.merge(i, r);
                    ans.push_back({i, r, x});
                }
            }
            else{
                root[x] = i;
            }
			//auto r = root.insert({x, i}).first->second;
            
		}
	}
    
	if(ans.size() == n-1)
		for(auto p : ans) cout << p.i+1 << ' ' << p.j+1 << ' ' << p.n << endl;
	else cout << "impossible" << endl;
}

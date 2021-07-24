    #include "bits/stdc++.h"
    using namespace std;
    const int N = 2e5 + 5;
    const int SN = 1 << 19;
    const long long inf = 5e17 + 17;
    struct data{
    	long long dist[6][6];
    	long long lazy[6][6];
    };
    /*
    0   |   3     ||      6   |   9           
    1   |   4     ||      7   |   10
    2   |   5     ||      8   |   11
    */
    int m , n , q;
    long long dwn[N][3];
    long long rgt[N][3];
    long long arr[N][3];
    data segtree[SN];
    int lftend[SN];
    int rgtend[SN];
     
    long long graph[12][12];
    void combine(int node , int mid){
    	for(int i = 0 ; i < 12 ; ++i){
    		for(int j = 0 ; j < 12 ; ++j){
    			graph[i][j] = inf;
    		}
    	}
    	for(int i = 0 ; i < 6 ; ++i){
    		for(int j = 0 ; j < 6 ; ++j){
    			graph[i][j] = segtree[node + node].dist[i][j];
    		}
    	}
    	for(int i = 0 ; i < 6 ; ++i){
    		for(int j = 0 ; j < 6 ; ++j){
    			graph[i + 6][j + 6] = segtree[node + node + 1].dist[i][j];
    		}
    	}
    	graph[3][6] = graph[6][3] = rgt[mid][0];
    	graph[4][7] = graph[7][4] = rgt[mid][1];
    	graph[5][8] = graph[8][5] = rgt[mid][2];
    	for(int k = 0 ; k < 12 ; ++k){
    		for(int i = 0 ; i < 12 ; ++i){
    			for(int j = 0 ; j < 12 ; ++j){
    				graph[i][j] = min(graph[i][j] , graph[i][k] + graph[k][j]);
    			}
    		}
    	}
    	for(int i = 0 ; i < 3 ; ++i){
    		for(int j = 0 ; j < 3 ; ++j){
    			segtree[node].dist[i][j] = min(inf , graph[i][j]);
    		}
    	}
    	for(int i = 3 ; i < 6 ; ++i){
    		for(int j = 3 ; j < 6 ; ++j){
    			segtree[node].dist[i][j] = min(inf , graph[i + 6][j + 6]);
    		}
    	}
    	for(int i = 0 ; i < 3 ; ++i){
    		for(int j = 3 ; j < 6 ; ++j){
    			segtree[node].dist[i][j] = segtree[node].dist[j][i] = min(inf , graph[i][j + 6]);
    		}
    	}
    }
     
    /*
    long long ddiisstt[N][3];
    long long dijkstra(int l , int r1 , int r , int r2 , int ql , int qr){
    	for(int i = ql ; i <= qr ; ++i){
    		ddiisstt[i][0] = ddiisstt[i][1] = ddiisstt[i][2] = inf;
    	}
    	priority_queue < pair < long long , pair < int , int > > > pq;
    	while(!pq.empty()){
    		pq.pop();
    	}
    	ddiisstt[l][r1] = 0;
    	pq.push({0 , {l , r1}});
    	while(!pq.empty()){
    		int col = pq.top().second.first;
    		int row = pq.top().second.second;
    		long long dist = ddiisstt[col][row];
    		pq.pop();
    		if(col < qr && ddiisstt[col + 1][row] > dist + rgt[col][row]){
    			ddiisstt[col + 1][row] = dist + rgt[col][row];
    			pq.push({-ddiisstt[col + 1][row] , {col + 1 , row}});
    		}
    		if(col > ql && ddiisstt[col - 1][row] > dist + rgt[col - 1][row]){
    			ddiisstt[col - 1][row] = dist + rgt[col - 1][row];
    			pq.push({-ddiisstt[col - 1][row] , {col - 1 , row}});
    		}
    		if(row && ddiisstt[col][row - 1] > dist + dwn[col][row - 1]){
    			ddiisstt[col][row - 1] = dist + dwn[col][row - 1];
    			pq.push({-ddiisstt[col][row - 1] , {col , row - 1}});
    		}
    		if(row < 2 && ddiisstt[col][row + 1] > dist + dwn[col][row]){
    			ddiisstt[col][row + 1] = dist + dwn[col][row];
    			pq.push({-ddiisstt[col][row + 1] , {col , row + 1}});
    		}
    	}
    	return ddiisstt[r][r2];
    }
     */
    void build(int l , int r , int node){
    	lftend[node] = l;
    	rgtend[node] = r;
    	if(l == r){
    		segtree[node].dist[0][0] = 0;
    		segtree[node].dist[1][1] = 0;
    		segtree[node].dist[2][2] = 0;
    		segtree[node].dist[0][1] = segtree[node].dist[1][0] = dwn[l][0];
    		segtree[node].dist[1][2] = segtree[node].dist[2][1] = dwn[r][1];
    		segtree[node].dist[0][2] = segtree[node].dist[2][0] = min(inf , dwn[l][0] + dwn[r][1]);
    		for(int i = 0 ; i < 6 ; ++i){
    			for(int j = 0 ; j < 6 ; ++j){
    				segtree[node].dist[i][j] = segtree[node].dist[i % 3][j % 3];
    			}
    		}
    	}
    	else{
    		int mid = l + r >> 1;
    		build(l , mid , node + node);
    		build(mid + 1 , r , node + node + 1);
    		combine(node , mid);
    	}
    }
     
    const int S = 2005;
    long long dist[S];
    priority_queue < pair < long long , int > > pq;
    int parent[S];
    const int perms[6][3] = {{0 , 1 , 2} , {0 , 2 , 1} , {1 , 0 , 2} , {1 , 2 , 0} , {2 , 0 , 1} , {2 , 1 , 0}};
    void push(int l , int r , int node){
    	if(l == r){
    		return;
    	}
    	int mid = l + r >> 1;
    	int lnode = node + node;
    	int rnode = node + node + 1;
    	for(int i = 0 ; i < 6 ; ++i){
    		if(i < 3){
    			segtree[lnode].lazy[i][i] += segtree[node].lazy[i][i];
    		}
    		else{
    			segtree[rnode].lazy[i][i] += segtree[node].lazy[i][i];
    		}
    		segtree[node].lazy[i][i] = 0;
    	}
    	for(int i = 0 ; i < 3 ; ++i){
    		for(int j = 0 ; j < 3 ; ++j){
    			if(i == j || !segtree[node].lazy[i][j] || segtree[node].dist[i][j] >= inf){
    				continue;
    			}
    			long long res = inf;
    			int save1 , save2;
    			for(int k = 0 ; k < 3 ; ++k){
    				for(int l = 0 ; l < 3 ; ++l){
    					if(k == l){
    						continue;
    					}
    					long long tmp = segtree[lnode].dist[i][k + 3] + rgt[mid][k] + segtree[rnode].dist[k][l] + rgt[mid][l] + segtree[lnode].dist[l + 3][j];
    					if(tmp < res){
    						res = tmp;
    						save1 = k;
    						save2 = l;
    					}
    				}
    			}
    			if(res == segtree[node].dist[i][j]){
    				segtree[lnode].lazy[i][save1 + 3] += segtree[node].lazy[i][j];
    				segtree[rnode].lazy[save1][save2] += segtree[node].lazy[i][j];
    				segtree[lnode].lazy[save2 + 3][j] += segtree[node].lazy[i][j];
    			}
    			else{
    				segtree[lnode].lazy[i][j] += segtree[node].lazy[i][j];
    				assert(segtree[lnode].dist[i][j] = segtree[node].dist[i][j]);
    			}
    			segtree[node].lazy[i][j] = 0;
    		}
    	}
    	for(int i = 3 ; i < 6 ; ++i){
    		for(int j = 3 ; j < 6 ; ++j){
    			if(i == j || !segtree[node].lazy[i][j] || segtree[node].dist[i][j] >= inf){
    				continue;
    			}
    			long long res = inf;
    			int save1 , save2;
    			for(int k = 0 ; k < 3 ; ++k){
    				for(int l = 0 ; l < 3 ; ++l){
    					if(k == l){
    						continue;
    					}
    					long long tmp = segtree[rnode].dist[i][k] + rgt[mid][k] + segtree[lnode].dist[k + 3][l + 3] + rgt[mid][l] + segtree[rnode].dist[l][j];
    					if(tmp < res){
    						res = tmp;
    						save1 = k;
    						save2 = l;
    					}
    				}
    			}
    			if(res == segtree[node].dist[i][j]){
    				segtree[rnode].lazy[i][save1] += segtree[node].lazy[i][j];
    				segtree[lnode].lazy[save1 + 3][save2 + 3] += segtree[node].lazy[i][j];
    				segtree[rnode].lazy[save2][j] += segtree[node].lazy[i][j];
    			}
    			else{
    				assert(segtree[rnode].dist[i][j] == segtree[node].dist[i][j]);
    				segtree[rnode].lazy[i][j] += segtree[node].lazy[i][j];
    			}
    			segtree[node].lazy[i][j] = 0;
    		}
    	}
    	for(int i = 0 ; i < 3 ; ++i){
    		for(int j = 3 ; j < 6 ; ++j){
    			segtree[node].lazy[i][j] += segtree[node].lazy[j][i];
    			segtree[node].lazy[j][i] = 0;
    			if(!segtree[node].lazy[i][j] || segtree[node].dist[i][j] >= inf){
    				continue;
    			}
    			long long res = inf;
    			int save = -1;
    			for(int k = 0 ; k < 3 ; ++k){
    				long long tmp = segtree[lnode].dist[i][k + 3] + rgt[mid][k] + segtree[rnode].dist[k][j];
    				if(tmp < res){
    					res = tmp;
    					save = k;
    				}
    			}
    			if(res == segtree[node].dist[i][j]){
    				segtree[lnode].lazy[i][save + 3] += segtree[node].lazy[i][j];
    				segtree[rnode].lazy[save][j] += segtree[node].lazy[i][j];
    				segtree[node].lazy[i][j] = 0;
    				continue;
    			}
    			res = inf;
    			save = -1;
    			for(int k = 0 ; k < 6 ; ++k){
    				int x = perms[k][0];
    				int y = perms[k][1];
    				int z = perms[k][2];
    				long long tmp = 0;
    				tmp += segtree[lnode].dist[i][x + 3];
    				tmp += rgt[mid][x];
    				tmp += segtree[rnode].dist[x][y];
    				tmp += rgt[mid][y];
    				tmp += segtree[lnode].dist[y + 3][z + 3];
    				tmp += rgt[mid][z];
    				tmp += segtree[rnode].dist[z][j];
    				if(tmp < res){
    					res = tmp;
    					save = k;
    				}
    			}
    			int x = perms[save][0];
    			int y = perms[save][1];
    			int z = perms[save][2];
    			/*assert(dijkstra(l , i , r , j % 3 , l , r) == segtree[node].dist[i][j]);
    			assert(dijkstra(l , i , mid , x , l , mid) == segtree[lnode].dist[i][x + 3]);
    			assert(dijkstra(mid + 1 , x , mid + 1 , y , mid + 1 , r) == segtree[rnode].dist[x][y]);
    			assert(dijkstra(mid , y , mid , z , l , mid) == segtree[lnode].dist[y + 3][z + 3]);
    			assert(dijkstra(mid + 1 , z , r , j % 3 , mid + 1 , r) == segtree[rnode].dist[z][j]);*/
    			segtree[lnode].lazy[i][x + 3] += segtree[node].lazy[i][j];
    			segtree[rnode].lazy[x][y] += segtree[node].lazy[i][j];
    			segtree[lnode].lazy[y + 3][z + 3] += segtree[node].lazy[i][j];
    			segtree[rnode].lazy[z][j] += segtree[node].lazy[i][j];
    			segtree[node].lazy[i][j] = 0;
    		}
    	}
    }
     
    long long query(int l , int r , int node , int idx , int row){
    	push(l , r , node);
    	if(l == r){
    		long long res = 0;
    		for(int i = 0 ; i < 6 ; ++i){
    			for(int j = 0 ; j < 6 ; ++j){
    				if((i % 3) == row || (j % 3) == row){
    					res += segtree[node].lazy[i][j];
    				}
    			}
    		}
    		if(row == 1){
    			res += segtree[node].lazy[0][2];
    			res += segtree[node].lazy[2][0];
    			res += segtree[node].lazy[0][5];
    			res += segtree[node].lazy[2][3];
    			res += segtree[node].lazy[3][2];
    			res += segtree[node].lazy[5][0];
    			res += segtree[node].lazy[3][5];
    			res += segtree[node].lazy[5][3];
    		}
    		return res;
    	}
    	int mid = l + r >> 1;
    	if(idx <= mid){
    		return query(l , mid , node + node , idx , row);
    	}
    	else{
    		return query(mid + 1 , r , node + node + 1 , idx , row);
    	}
    }
    vector < int > ranges;
    void go(int l , int r , int node , int ql , int qr){
    	if(ql > qr || l > qr || r < ql){
    		return;
    	}
    	if(l >= ql && r <= qr){
    		//cout << ql << " " << qr << " " << l << " " << r << " " << node << endl;
    		ranges.emplace_back(node);
    		return;
    	}
    	int mid = l + r >> 1;
    	go(l , mid , node + node , ql , qr);
    	go(mid + 1 , r , node + node + 1 , ql , qr);
    }
    void update(int row1 , int ql , int row2 , int qr , long long add){
    	ranges.clear();
    	go(1 , n , 1 , 1 , ql - 1);
    	int start = ranges.size();
    	go(1 , n , 1 , ql , qr);
    	int finish = ranges.size() - 1;
    	go(1 , n , 1 , qr + 1 , n);
    	int siz = ranges.size() * 6;
    	for(int i = 0 ; i < siz ; ++i){
    		dist[i] = inf;
    		parent[i] = -1;
    	}
    	while(!pq.empty()){
    		pq.pop();
    	}
    	dist[start * 6 + row1] = 0;
    	pq.push({0 , start * 6 + row1});
    	while(!pq.empty()){
    		int node = pq.top().second;
    		long long cost = -pq.top().first;
    		pq.pop();
    		if(dist[node] < cost){
    			continue;
    		}
    		int who = node % 6;
    		int grp = ranges[node / 6];
    		//cout << node << " " << grp << " " << lftend[grp] << " " << rgtend[grp] << " " << cost << endl;
    		for(int i = 0 ; i < 6 ; ++i){
    			int next = (node / 6) * 6 + i;
    			long long weight = cost + segtree[grp].dist[who][i];
    			if(weight < dist[next]){
    				dist[next] = weight;
    				pq.push({-dist[next] , next});
    				parent[next] = node;
    			}
    		}
    		if(who < 3 && node > 2){
    			if(cost + rgt[lftend[grp] - 1][who] < dist[node - 3]){
    				dist[node - 3] = cost + rgt[lftend[grp] - 1][who];
    				pq.push({-dist[node - 3] , node - 3});
    				parent[node - 3] = node;
    			}
    		}
    		if(who > 2 && node + 3 < siz){
    			if(cost + rgt[rgtend[grp]][who - 3] < dist[node + 3]){
    				dist[node + 3] = cost + rgt[rgtend[grp]][who - 3];
    				pq.push({-dist[node + 3] , node + 3});
    				parent[node + 3] = node;
    			}
    		}
    	}
    	int t = finish * 6 + row2 + 3;
    	//assert(dist[t] <= brute(row1 , ql , row2 , qr));
    	//cout << dist[t] << " " << brute(row1 , ql , row2 , qr) << endl;
    	int s = start * 6 + row1;
    	arr[qr][row2] += add;
    	while(t != s){
    		int prv = parent[t];
    		int cur = ranges[t / 6];
    		int nxt = ranges[prv / 6];
    		if(cur == nxt){
    			if((t % 3) != (prv % 3) || lftend[cur] < rgtend[cur]){
    				segtree[cur].lazy[t % 6][prv % 6] += add;
    				arr[((t % 6) < 3) ? lftend[cur] : rgtend[cur]][t % 3] -= add;
    			}
    		}
    		else{
    			arr[((prv % 6) < 3) ? lftend[nxt] : rgtend[nxt]][prv % 3] += add;
    		}
    		t = prv;
    	}
    }
     
    void query(int row , int col){
    	printf("%lld\n" , query(1 , n , 1 , col , row) + arr[col][row]);
    }
    int main(){
    	scanf("%d %d %d" , &m , &n , &q);
    	for(int i = 0 ; i < 3 ; ++i){
    		for(int j = 0 ; j <= n ; ++j){
    			dwn[j][i] = inf;
    		}
    	}
    	for(int i = 0 ; i < m - 1 ; ++i){
    		for(int j = 1 ; j <= n ; ++j){
    			scanf("%lld" , &dwn[j][i]);
    		}
    	}
    	for(int i = 0 ; i < 3 ; ++i){
    		for(int j = 0 ; j <= n ; ++j){
    			rgt[j][i] = inf;
    		}
    	}
    	for(int i = 0 ; i < m ; ++i){
    		for(int j = 1 ; j < n ; ++j){
    			scanf("%lld" , &rgt[j][i]);
    		}
    	}
    	build(1 , n , 1);
    	while(q--){
    		int type;
    		scanf("%d" , &type);
    		if(type == 1){
    			int x1 , y1;
    			int x2 , y2;
    			long long c;
    			scanf("%d %d %d %d %lld" , &x1 , &y1 , &x2 , &y2 , &c);
    			if(y1 > y2){
    				swap(y1 , y2);
    				swap(x1 , x2);
    			}
    			--x1;
    			--x2;
    			update(x1 , y1 , x2 , y2 , c);
    		}
    		else{
    			int x , y;
    			scanf("%d %d" , &x , &y);
    			--x;
    			query(x , y);
    		}
    	}
    }
class disjointset{
    public:
    vector<int> parent, rank;
    disjointset(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }
    int findparent(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=findparent(parent[u]);
    }
    void unionbyrank(int u, int v){
        int pu = findparent(u);
        int pv = findparent(v);
        if(pu==pv)return;
        if(rank[pu]==rank[pv]){
            parent[pv]=pu;
            rank[pu]++;
        }
        else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else{
            parent[pv]=pu;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // Map the emails with their owner using map datastructure
        unordered_map<string, int> ownermapmail;
        int size = accounts.size();
        disjointset ds(size);
        for(int i=0; i<size; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(ownermapmail.find(mail)==ownermapmail.end()){
                    ownermapmail[mail]=i;
                }
                else{
                    ds.unionbyrank(i, ownermapmail[mail]);
                }
            }
        }
        // Now merge the mail based upon their owner
        vector<vector<string>> mergedaccounts(size);
        for(auto acc:ownermapmail){
            int owner = ds.findparent(acc.second);
            string mail = acc.first;
            mergedaccounts[owner].push_back(mail);
        }
        // Now generate the final merged account details
        vector<vector<string>> result;
        for(int i=0; i<size; i++){
            if(mergedaccounts[i].empty())continue;
            sort(mergedaccounts[i].begin(), mergedaccounts[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(string s:mergedaccounts[i]){
                temp.push_back(s);
            }
            result.push_back(temp);
        }
        // Return the final result
        return result;
    }
};
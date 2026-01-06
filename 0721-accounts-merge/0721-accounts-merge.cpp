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
        unordered_map<string, int> nodemapmail;
        disjointset ds(accounts.size());
        // Create a disjointset mapping the mails with their corresponding owner
        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(nodemapmail.find(mail)==nodemapmail.end()){
                    nodemapmail[mail]=i;
                }
                else{
                    ds.unionbyrank(i, nodemapmail[mail]);
                }
            }
        }
        // Create a list of mails with corresponding owner
        vector<vector<string>> mergeaccounts(accounts.size());
        for(auto acc:nodemapmail){
            int owner = ds.findparent(acc.second);
            string ownermail = acc.first;
            mergeaccounts[owner].push_back(ownermail);
        }
        vector<vector<string>> result;
        // Create the final merged accounts
        for(int i=0; i<accounts.size(); i++){
            if(mergeaccounts[i].empty())continue;
            sort(mergeaccounts[i].begin(), mergeaccounts[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(string s:mergeaccounts[i]){
                temp.push_back(s);
            }
            result.push_back(temp);
        }
        return result;
    }
};
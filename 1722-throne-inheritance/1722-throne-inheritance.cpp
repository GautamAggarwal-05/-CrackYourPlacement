class ThroneInheritance {
public:
    unordered_map<string,vector<string>>adj;
    unordered_map<string,bool>marked;
    string king;
    ThroneInheritance(string kingName) {
        king = kingName;
        marked[king]=true;
    }

    void birth(string parentName, string childName) {
        adj[parentName].push_back(childName);
        marked[childName]=true;
    }
    // if dead mark that as true;
    void death(string name) {
        marked[name]=false;
    }
    void dfs(string src,vector<string> &ans){
        if(marked[src])
            ans.push_back(src);
        for(auto neigh:adj[src]){
            dfs(neigh,ans);
        }
    }
    vector<string> getInheritanceOrder() {
        vector<string>ans;
        dfs(king,ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
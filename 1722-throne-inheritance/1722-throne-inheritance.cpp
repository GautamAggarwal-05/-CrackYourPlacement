class ThroneInheritance {
public:
    unordered_map<string,int>nametonumber;
    unordered_map<int,string>numbertoname;
    unordered_map<int,list<int>>adj;
    unordered_map<string,bool>marked;
    ThroneInheritance(string kingName) {
        nametonumber[kingName]=0;
        numbertoname[0]=kingName;
        marked[kingName]=true;
    }
    int i=1;
    void birth(string parentName, string childName) {
        nametonumber[childName]=i;
        numbertoname[i]=childName;
        marked[childName]=true;
        i++;
        adj[nametonumber[parentName]].push_back(nametonumber[childName]);
    }
    // if dead mark that as true;
    void death(string name) {
        marked[name]=false;
    }
    void dfs(int src,vector<string> &ans){
        if(marked[numbertoname[src]])
            ans.push_back(numbertoname[src]);
        for(auto neigh:adj[src]){
            dfs(neigh,ans);
        }
    }
    vector<string> getInheritanceOrder() {
        vector<string>ans;
        dfs(0,ans);
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
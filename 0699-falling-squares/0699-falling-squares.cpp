class Solution {
public:
    struct Node {
        Node *l = nullptr, *r = nullptr;
        int mx = 0;
        int lazy = 0;
    };
    class SegTree {
        Node* root;
        int MINX, MAXX;

    public:
        SegTree(int mn, int mx) : MINX(mn), MAXX(mx) { root = new Node(); }
        void apply(Node* nd, int val) {
            nd->mx = max(nd->mx, val);
            nd->lazy = max(nd->lazy, val);
        }

        void push(Node* nd) {
            if (!nd->l)
                nd->l = new Node();
            if (!nd->r)
                nd->r = new Node();
            if (nd->lazy) {
                apply(nd->l, nd->lazy);
                apply(nd->r, nd->lazy);
                nd->lazy = 0;
            }
        }

        
        void update(Node* nd, int l, int r, int L, int R, int h) {
            if (R < l || r < L)
                return;
            if (L <= l && r <= R) {
                apply(nd, h);
                return;
            }
            push(nd);
            int mid = l + (r - l) / 2;
            update(nd->l, l, mid, L, R, h);
            update(nd->r, mid + 1, r, L, R, h);
            nd->mx = max(nd->l->mx, nd->r->mx);
        }

        
        int query(Node* nd, int l, int r, int L, int R) {
            if (!nd || R < l || r < L)
                return 0;
            if (L <= l && r <= R)
                return nd->mx;
            push(nd);
            int mid = l + (r - l) / 2;
            return max(query(nd->l, l, mid, L, R),
                       query(nd->r, mid + 1, r, L, R));
        }

        
        void update(int L, int R, int h) { update(root, MINX, MAXX, L, R, h); }
        int query(int L, int R) { return query(root, MINX, MAXX, L, R); }
    };
    
    vector<int> fallingSquares(vector<vector<int>>& pos) {
        
        int globalMaxX = 0;
        for (auto& p : pos)
            globalMaxX = max(globalMaxX, p[0] + p[1]);
        SegTree st(0, globalMaxX);

        vector<int> ans;
        int runningMax = 0;
        for (auto& p : pos) {
            int L = p[0];
            int R = p[0] + p[1] - 1; 
            int side = p[1];

            int base = st.query(L, R);
            int top = base + side;
            st.update(L, R, top);

            runningMax = max(runningMax, top);
            ans.push_back(runningMax);
        }
        return ans;
    }
};
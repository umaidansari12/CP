class TreeAncestor {
public:
    vector<int> par;
    TreeAncestor(int n, vector<int>& parent) {
        par = parent;
    }

    int getKthAncestor(int node, int k) {
        if (k == 0)
            return node;
        return getKthAncestor(par[node], k - 1);

    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

//This technique is known as binary lifting

class TreeAncestor {
public:
    vector<vector<int>> par;
    TreeAncestor(int n, vector<int>& parent) {
        par.resize(20, vector<int>(parent.size(), -1));
        for (int i = 0; i < parent.size(); i++) {
            par[0][i] = parent[i];
        }
        for (int i = 1; i < 20; i++) {
            for (int node = 0; node < parent.size(); node++) {
                int nodep = par[i - 1][node];
                if (nodep != -1)
                    par[i][node] = par[i - 1][nodep];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 20; i++) {
            if (k & (1 << i))
            {
                node = par[i][node];
                if (node == -1)
                    return -1;
            }
        }
        return node;

    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
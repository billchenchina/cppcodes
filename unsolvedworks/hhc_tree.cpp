#include <algorithm>
#include <limits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class segment_tree
{
private:
    struct segment_tree_node
    {
        int sum;
        int max;

        segment_tree_node() {}

        segment_tree_node(int value)
            : sum(value),
            max(value)
        {}

        segment_tree_node(int sum, int max)
            : sum(sum),
            max(max)
        {}
    };

public:
    inline segment_tree(const vector<int> &vec)
        : count_(vec.size()),
        storage(new segment_tree_node[storage_size_(count())])
    {
        vector<int>::const_iterator iter = vec.begin();
        construct(0, 0, count() - 1, iter);
    }

    ~segment_tree()
    {
        delete[] storage;
    }

    inline void modify(int index, int value)
    {
        modify_(0, 0, count() - 1, index, value);
    }

    inline int query_sum(int first, int last) const
    {
        return query_sum_(0, 0, count() - 1, first, last);
    }

    inline int query_max(int first, int last) const
    {
        return query_max_(0, 0, count() - 1, first, last);
    }

    inline int count() const
    {
        return count_;
    }

private:
    int count_;
    segment_tree_node *storage;

    void construct(int index, int first, int last, vector<int>::const_iterator &iter)
    {
        if (first == last)
        {
            storage[index] = segment_tree_node(*iter);
            ++iter;
        }
        else
        {
            const int mid = first + ((last - first) >> 1);
            construct((index << 1) + 1, first, mid, iter);
            construct((index << 1) + 2, mid + 1, last, iter);
            storage[index] = segment_tree_node(storage[(index << 1) + 1].sum + storage[(index << 1) + 2].sum, max(storage[(index << 1) + 1].max, storage[(index << 1) + 2].max));
        }
    }

    void modify_(int index, int first, int last, int modify_index, int value)
    {
        if (first == last)
        {
            storage[index].sum = value;
            storage[index].max = value;
        }
        else
        {
            const int mid = first + ((last - first) >> 1);
            if (modify_index <= mid)
            {
                modify_((index << 1) + 1, first, mid, modify_index, value);
            }
            else
            {
                modify_((index << 1) + 2, mid + 1, last, modify_index, value);
            }
            storage[index].sum = storage[(index << 1) + 1].sum + storage[(index << 1) + 2].sum;
            storage[index].max = max(storage[(index << 1) + 1].max, storage[(index << 1) + 2].max);
        }
    }

    int query_sum_(int index, int first, int last, int query_first, int query_last) const
    {
        if (query_first == first && query_last == last)
        {
            return storage[index].sum;
        }
        const int mid = first + ((last - first) >> 1);
        if (query_last <= mid)
        {
            return query_sum_((index << 1) + 1, first, mid, query_first, query_last);
        }
        if (query_first >= mid + 1)
        {
            return query_sum_((index << 1) + 2, mid + 1, last, query_first, query_last);
        }
        return query_sum_((index << 1) + 1, first, mid, query_first, mid) + query_sum_((index << 1) + 2, mid + 1, last, mid + 1, query_last);
    }

    int query_max_(int index, int first, int last, int query_first, int query_last) const
    {
        if (query_first == first && query_last == last)
        {
            return storage[index].max;
        }
        const int mid = first + ((last - first) >> 1);
        if (query_last <= mid)
        {
            return query_max_((index << 1) + 1, first, mid, query_first, query_last);
        }
        if (query_first >= mid + 1)
        {
            return query_max_((index << 1) + 2, mid + 1, last, query_first, query_last);
        }
        return max(query_max_((index << 1) + 1, first, mid, query_first, mid), query_max_((index << 1) + 2, mid + 1, last, mid + 1, query_last));
    }

    static int storage_size_(int count)
    {
        int rs = 1;
        while (rs < count)
        {
            rs <<= 1;
        }
        return (rs << 1) - 1;
    }
};

void _heavy_light_decomposition_dfs1(int cur, int cur_parent, int cur_depth, const vector<vector<int> > &unrooted_tree, vector<int> &parent, vector<int> &depth, vector<int> &subtree_vertices_num, vector<int> &heavy_child)
{
    parent[cur] = cur_parent;
    depth[cur] = cur_depth;
    subtree_vertices_num[cur] = 1;
    for (vector<int>::const_iterator it = unrooted_tree[cur].begin(); it != unrooted_tree[cur].end(); ++it)
    {
        if (*it != cur_parent)
        {
            _heavy_light_decomposition_dfs1(*it, cur, cur_depth + 1, unrooted_tree, parent, depth, subtree_vertices_num, heavy_child);
            subtree_vertices_num[cur] += subtree_vertices_num[*it];
            if (heavy_child[cur] == -1 || subtree_vertices_num[*it] > subtree_vertices_num[heavy_child[cur]])
            {
                heavy_child[cur] = *it;
            }
        }
    }
}

void _heavy_light_decomposition_dfs2(int cur, int cur_top, int &cnt, const vector<vector<int> > &unrooted_tree, const vector<int> &parent, const vector<int> &heavy_child, vector<int> &top, vector<int> &identifier)
{
    top[cur] = cur_top;
    identifier[cur] = cnt;
    ++cnt;
    if (heavy_child[cur] != -1)
    {
        _heavy_light_decomposition_dfs2(heavy_child[cur], cur_top, cnt, unrooted_tree, parent, heavy_child, top, identifier);
    }
    for (vector<int>::const_iterator it = unrooted_tree[cur].begin(); it != unrooted_tree[cur].end(); ++it)
    {
        if (*it != heavy_child[cur] && *it != parent[cur])
        {
            _heavy_light_decomposition_dfs2(*it, *it, cnt, unrooted_tree, parent, heavy_child, top, identifier);
        }
    }
}

void heavy_light_decomposition(const vector<vector<int> > &unrooted_tree, vector<int> &parent, vector<int> &depth, vector<int> &top, vector<int> &identifier)
{
    const int vertices_num = unrooted_tree.size();
    parent.resize(vertices_num);
    depth.resize(vertices_num);
    top.resize(vertices_num);
    identifier.resize(vertices_num);
    vector<int> subtree_vertices_num(vertices_num);
    vector<int> heavy_child(vertices_num, -1);
    _heavy_light_decomposition_dfs1(0, 0, 0, unrooted_tree, parent, depth, subtree_vertices_num, heavy_child);
    int cnt = 0;
    _heavy_light_decomposition_dfs2(0, 0, cnt, unrooted_tree, parent, heavy_child, top, identifier);
}

int get_max(int src, int dest, const vector<int> &parent, const vector<int> &depth, const vector<int> &top, const vector<int> &identifier, const segment_tree &seg_tree)
{
    int ans = numeric_limits<int>::min();
    while (top[src] != top[dest])
    {
        if (depth[top[src]] < depth[top[dest]])
        {
            swap(src, dest);
        }
        ans = max(seg_tree.query_max(identifier[top[src]], identifier[src]), ans);
        src = parent[top[src]];
    }
    if (depth[src] > depth[dest])
    {
        swap(src, dest);
    }
    ans = max(seg_tree.query_max(identifier[src], identifier[dest]), ans);
    return ans;
}

int get_sum(int src, int dest, const vector<int> &parent, const vector<int> &depth, const vector<int> &top, const vector<int> &identifier, const segment_tree &seg_tree)
{
    int ans = 0;
    while (top[src] != top[dest])
    {
        if (depth[top[src]] < depth[top[dest]])
        {
            swap(src, dest);
        }
        ans += seg_tree.query_sum(identifier[top[src]], identifier[src]);
        src = parent[top[src]];
    }
    if (depth[src] > depth[dest])
    {
        swap(src, dest);
    }
    ans += seg_tree.query_sum(identifier[src], identifier[dest]);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > unrooted_tree(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        unrooted_tree[a - 1].push_back(b - 1);
        unrooted_tree[b - 1].push_back(a - 1);
    }
    vector<int> vertices_weight(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vertices_weight[i];
    }
    vector<int> depth;
    vector<int> parent;
    vector<int> top;
    vector<int> identifier;
    heavy_light_decomposition(unrooted_tree, parent, depth, top, identifier);
    vector<int> identifier_vertices_weight(n);
    for (int i = 0; i < n; ++i)
    {
        identifier_vertices_weight[identifier[i]] = vertices_weight[i];
    }
    segment_tree seg_tree(identifier_vertices_weight);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        string op;
        cin >> op;
        if (op == "CHANGE")
        {
            int u;
            int t;
            cin >> u >> t;
            seg_tree.modify(identifier[u - 1], t);
        }
        else if (op == "QMAX")
        {
            int u, v;
            cin >> u >> v;
            cout << get_max(u - 1, v - 1, parent, depth, top, identifier, seg_tree) << endl;
        }
        else if (op == "QSUM")
        {
            int u, v;
            cin >> u >> v;
            cout << get_sum(u - 1, v - 1, parent, depth, top, identifier, seg_tree) << endl;
        }
    }
    
    return 0;
}
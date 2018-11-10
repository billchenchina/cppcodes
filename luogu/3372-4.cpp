#include <bits/stdc++.h>
using namespace std;

bool verbose_mode = false;

struct SegTree
{
    SegTree *left_sub_tree;
    SegTree *right_sub_tree;
    int left_range;
    int right_range;
    long long sum;
    int lazy_tag;
    SegTree(int _left_range, int _right_range):left_range(_left_range), right_range(_right_range)
    {
        sum = lazy_tag = 0;
        if(verbose_mode)
        {
            cout << "SegTree(" << _left_range
                 << ", " << _right_range << ")" << endl;
        }
        if(_left_range == _right_range)
        {
            left_sub_tree = right_sub_tree = NULL;
        }
        else
        {
#define mid _left_range + ((_right_range - _left_range)>>1)
            left_sub_tree = new SegTree(left_range, mid);
            right_sub_tree = new SegTree(mid+1, right_range);
#undef mid
        }
    }
    void add(int _left_range, int _right_range, int value)
    {
        if(verbose_mode)
        {
            cout << "SegTree::add(" << _left_range
                 << ", " << _right_range
                 << ", " << value << ")" << endl;
            cout << "Current Node status:" << endl
                 << left_range << ", " << right_range << endl;
            cout << "Before sum: " << sum << endl;
        }
        if(left_range == right_range)
        {
            sum += value;
            if(verbose_mode)
            {
                cout << "Now sum: " << sum << endl;
            }
            return;
        }
        if(_left_range == left_range && _right_range == right_range)
        {
            lazy_tag += value;
            if(verbose_mode)
            {
                cout << "Adding " << value << " to lazytag, terminate here." << endl;
            }
            return;
        }
        sum += 1ll*(_right_range - _left_range +1)*value;
        if(verbose_mode)
        {
            cout << "Now sum: " << sum << endl;
        }
        if(_left_range == _right_range && left_range == right_range)
        {
            return;
        }
        if(_left_range > left_range + ((right_range - left_range)>>1))
        {
            right_sub_tree->add(_left_range, _right_range, value);
        }
        else if(_right_range <= left_range + ((right_range - left_range)>>1))
        {
            left_sub_tree->add(_left_range, _right_range, value);
        }
        else
        {
            left_sub_tree->add(_left_range, left_range + ((right_range - left_range)>>1), value);
            right_sub_tree->add(left_range + ((right_range - left_range)>>1)+1, _right_range, value);
        }
    }
    long long query(int _left_range, int _right_range)
    {
        if(verbose_mode)
        {

            cout << "Current Node status:" << endl
                 << left_range << ", " << right_range << endl;
            cout << "SegTree::query(" << _left_range
                 << ", " << _right_range << ")" << endl;


        }
        long long ans;
        if(_left_range == left_range && _right_range == right_range)
        {
            ans = sum + 1ll * lazy_tag *(right_range - left_range +1);
        }
        else
        {
            if(lazy_tag != 0)
            {
                if(verbose_mode) {
                    cout << "Pushing down, lazy_tag: " << lazy_tag << endl;
                }
                left_sub_tree -> add(left_range, left_range + ((right_range - left_range)>>1), lazy_tag);
                right_sub_tree -> add(left_range + ((right_range - left_range)>>1) + 1, right_range, lazy_tag);
                sum += 1ll * (right_range - left_range + 1) * lazy_tag;
                lazy_tag = 0;
            }
            if(_left_range > left_range + ((right_range - left_range)>>1))
            {
                ans =  right_sub_tree -> query(_left_range, _right_range);
            }
            else if(_right_range <= left_range + ((right_range - left_range)>>1))
            {
                ans =  left_sub_tree -> query(_left_range, _right_range);
            }
            else
            {
                ans = left_sub_tree -> query(_left_range, left_range + ((right_range - left_range)>>1))
                      + right_sub_tree -> query(left_range + ((right_range - left_range)>>1)+1, _right_range);
            }
        }
        if(verbose_mode)
        {
            cout << "returns " << ans << endl;
        }
        return ans;

    }
};


int main(int argc, char **argv)
{
    if(argc == 2 && strcmp(argv[1], "verbose") == 0)
    {
        verbose_mode = true;
        cout << "verbose mode on" << endl;
    }
    int N, M;
    cin >> N >> M;
    SegTree *root = new SegTree(1, N);
    for(int i = 1; i <= N; ++i)
    {
        int x;
        cin >> x;
        root->add(i, i, x);
    }
    for(int i = 0; i < M; ++i)
    {
        if(verbose_mode)
        {
            cout << "Waiting user input" << endl;
        }
        int op;
        cin >> op;
        if(op == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            root->add(x, y, k);
        }
        else if(op == 2)
        {
            int x, y;
            cin >> x >> y;
            cout << root->query(x, y) << endl;
        }
    }
}


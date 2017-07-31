# Splay 学习笔记

**本笔记多数内容来自 Patchuli_go 2017 夏令营课件**


>Tarjan 发明了以旋转来保证复杂度的 BST（Binery Search Tree），称为 Splay。
>
>核心操作是 Splay 操作，即将一个任意的结点通过旋转移动到根。
>
>—— Patchuli_go

## 操作

### 旋转

>以左旋（Zig操作）为例，其目标是将一个结点的左儿子移动到它的位置。
>
>我们将它安放到左儿子的右儿子上，而那个原本的右儿子则变成它现在的左儿子。

说起来有点难懂，看看代码吧：
```cpp
/**
  * Edited by billchenchina<billchenchina2001@gmail.com> on 31/07/2017
  * @author Patchuli_go
  **/

struct node {
    node *son[2],*father;
    int v;
    node(int _v) {
        this->v=_v;
    }
    /**
      * if father exist:
      *     @return 1 if this is father's left child
      *     @return 0 if this is father's right child
      *     else no father:
      *     @return -1
      **/
    int dir() {
        return father!=NULL?this==father->son[1]:-1;
    }
    /**
      * "ZIG" && "ZAG"
      *
      **/
    void rotate() {
        int k=dir();
        // if k == -1 (no father)
        // return
        if(!~k) {
            return;
        }
        // switch father to son[k^1]
        // 
        node *o=father;
        node *y=son[k^1];
        son[k^1]=o;
        o->son[k]=y;
        if(~(k=o->dir())) {
            o->father->son[k]=this;
        }
        father=o->father;
        o->father=this;
        if(y) {
            y->father=o;
        }
    }

    void splay() {
        while(father!=NULL)
            (dir()==father->dir()?father:this)->rotate(),rotate();
    }
};
class splay_tree {
private:
    node *rt;
    static node *&find(node *&x,int v) {
        if(!x||v==x->v) return x;
        return find(x->son[x->v<v],v);
    }
    void root(node *x) {
        x->splay();
        rt=x;
    }
public:
    splay_tree() {}
    void insert(int v) {
        node *&o=find(rt,v);
        if(!o) {
            o=new node(v);
            root(o);
        }
    }
    void erase(int v) {
        node *o=find(rt,v);
        if(o) {
            root(o);
            if(!rt->son[0]||!rt->son[1]) {
                int k=(!rt->son[0]);
                if(rt->son[k]) rt->son[k]->father=0;
                rt=rt->son[k];
            } else {
                rt->son[0]->father=rt->son[1]->father=0;
                node *x=rt->son[0];
                while(x->son[1]) x=x->son[1];
                x->splay();
                x->son[1]=rt->son[1];
                if(rt->son[1]) rt->son[1]->father=x;
                rt=x;
            }
            delete o;
        }
    }
};
	rt=x;
	}
public:
	splay_tree(){}
	void insert(int v){
		node *&o=find(rt,v);
		if(!o){
			o=new node(v);
			root(o);
		}
	}
	void erase(int v){
		node *o=find(rt,v);
		if(o){
			root(o);
			if(!rt->son[0]||!rt->son[1]){
				int k=(!rt->son[0]);
				if(rt->son[k]) rt->son[k]->father=0;
				rt=rt->son[k];
			}
			else{
				rt->son[0]->father=rt->son[1]->father=0;
				node *x=rt->son[0];
				while(x->son[1]) x=x->son[1];
				x->splay(); x->son[1]=rt->son[1];
				if(rt->son[1]) rt->son[1]->father=x; rt=x;
			}
			delete o;
		}
	}
};
```
（代码衍生于 Patchuli_go 2017 夏令营课件）

这里的图解可以到[参考资料2]查找，[参考资料1]里面图片有问题。


留坑

参考资料：

1.[数据结构之伸展树 作者:Dong](http://dongxicheng.org/structure/splay-tree/)（使用[CC BY 2.5 CN](https://creativecommons.org/licenses/by/2.5/cn/)发布）

2.伸展树的基本操作与应用-IOI2004 国家集训队论文 杨思雨

3.[Splay Tree - NOCOW](http://www.nocow.cn/index.php/Splay_Tree)

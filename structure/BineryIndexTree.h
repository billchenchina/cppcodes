#include <vector>
using namespace std;
#ifndef bitree
#define bitree BineryIndexTree
#endif // bitree
/*
 * BineryIndexTree
 * @auther billchenchina
 * update time : 2017/5/5 20:27 UTF +8
 */
template <typename _T>
class BineryIndexTree{
private:
    vector<_T>v;
    int length;
public:
    /*
     * Constract Method
     * @param length
     * @return BineryIndexTree
     */
    BineryIndexTree(int _length){
        v=vector<_T>(_length,0);
        length=_length;
    }
    /*
     * lowBit
     * @param position
     * @return position
     */
    int lowBit(int _pos){
        return _pos&(-_pos);
    }
    /*
     * changeValue
     * @param position,value
     * @return null
     */
    void changeValue(int _pos,int _value){
        while(_pos<length){
            v[_pos]+=_value;
            _pos+=lowBit(_pos);
        }
    }
    /*
     * getFrontValue
     * @param endposition
     * @return Type
     */
    _T getFrontValue(int _endpos){
        _endpos--;
        _T sum=0;
        while(_endpos>0){
            sum+=v[_endpos];
            _endpos-=lowBit(_endpos);
        }
        return sum;
    }
    /*
     * getLength
     * @param null
     * @return int
     */
    int getLength(){
        return length;
    }
};

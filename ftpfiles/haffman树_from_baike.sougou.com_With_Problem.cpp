#include<iostream>
#include<stdlib.h>
using namespace std;
const int MaxValue=10000;//��ʼ�趨��Ȩֵ���ֵ
const int MaxBit=4;//��ʼ�趨��������λ��
const int MaxN=10;//��ʼ�趨����������
struct HaffNode { //���������Ľ��ṹ
    int weight;//Ȩֵ
    int flag;//���
    int parent;//˫�׽���±�
    int leftChild;//�����±�
    int rightChild;//�Һ����±�
};
struct Code//��Ź��������������Ԫ�ؽṹ
{
    int bit[MaxBit];//����
    int start;//�������ʼ�±�
    int weight;//�ַ���Ȩֵ
};
void Haffman(int weight[],int n,HaffNode haffTree[])
//����Ҷ������ΪnȨֵΪweight�Ĺ�������haffTree
{
    int j,m1,m2,x1,x2;
//��������haffTree��ʼ����n��Ҷ���Ĺ�����������2n-1�����
    for(int i=0; i<2*n-1; i++)
    {
        if(i<n)
            haffTree[i].weight=weight[i];
        else
            haffTree[i].weight=0;
//ע������û��else��{}����������n��Ҷ�ӽڵ㻹��n-1����Ҷ�ӽڵ㶼���������4���ĳ�ʼ��
        haffTree[i].parent=0;
        haffTree[i].flag=0;
        haffTree[i].leftChild=-1;
        haffTree[i].rightChild=-1;
    }
//�����������haffTree��n-1����Ҷ���
    for(int i=0; i<n-1; i++)
    {
        m1=m2=MaxValue;//Maxvalue=10000;(����һ���൱�����)
        x1=x2=0;//x1��x2������������С������ֵ�������Ӧ���±�
        for(j=i; j<n+i; j++) //ѭ���ҳ�����Ȩ���У���С�Ķ���ֵ--morgan
        {
            if(haffTree[j].weight<m1&&haffTree[j].flag==0)
            {
                m2=m1;
                x2=x1;
                m1=haffTree[j].weight;
                x1=j;
            }
            else if(haffTree[j].weight<m2&&haffTree[j].flag==0)
            {
                m2=haffTree[j].weight;
                x2=j;
            }
        }
//���ҳ�������Ȩֵ��С�������ϲ�Ϊһ������
        haffTree[x1].parent=n+i;
        haffTree[x2].parent=n+i;
        haffTree[x1].flag=1;
        haffTree[x2].flag=1;
        haffTree[n+i].weight=haffTree[x1].weight+haffTree[x2].weight;
        haffTree[n+i].leftChild=x1;
        haffTree[n+i].rightChild=x2;
    }
}
void HaffmanCode(HaffNode haffTree[],int n,Code haffCode[])
//��n�����Ĺ�������haffTree�������������haffCode
{
    Code*cd=newCode;
    int child,parent;
//��n��Ҷ���Ĺ���������
    for(int i=0; i<n; i++)
    {
//cd->start=n-1;//���ȳ���������һλΪn-1,
        cd->start=0;//,----�޸Ĵ�0��ʼ����--morgan
        cd->weight=haffTree[i].weight;//ȡ�ñ����ӦȨֵ���ַ�
        child=i;
        parent=haffTree[child].parent;
//��Ҷ�������ֱ�������
        while(parent!=0)
        {
            if(haffTree[parent].leftChild==child)
                cd->bit[cd->start]=0;//���ӽ�����0
            else
                cd->bit[cd->start]=1;//�Һ��ӽ�����1
//cd->start--;
            cd->start++;//�ĳɱ�������--morgan
            child=parent;
            parent=haffTree[child].parent;
        }
//����Ҷ���ı���Ͳ��ȳ��������ʼλ
//for(intj=cd->start+1;j<n;j++)
        for(intj=cd->start-1; j>=0; j--) //�����޸ı��룬�Ӹ��ڵ㿪ʼ����--morgan
            haffCode[i].bit[cd->start-j-1]=cd->bit[j];
        haffCode[i].start=cd->start;
        haffCode[i].weight=cd->weight;//��������Ӧ��Ȩֵ
    }
}
int main()
{
    int i,j,n=4,m=0;
    int weight[]= {2,4,5,7};
    HaffNode*myHaffTree=newHaffNode[2*n-1];
    Code*myHaffCode=newCode[n];
    if(n>MaxN)
    {
        cout<<"�����nԽ�磬�޸�MaxN!"<<endl;
        exit(0);
    }
    Haffman(weight,n,myHaffTree);
    HaffmanCode(myHaffTree,n,myHaffCode);
//���ÿ��Ҷ���Ĺ���������
    for(i=0; i<n; i++)
    {
        cout<<"Weight="<<myHaffCode[i].weight<<"Code=";
//for(j=myHaffCode[i].start+1;j<n;j++)
        for(j=0; j<myHaffCode[i].start; j++)
            cout<<myHaffCode[i].bit[j];
        m=m+myHaffCode[i].weight*myHaffCode[i].start;
        cout<<endl;
    }
    cout<<"huffman'sWPLis:";
    cout<<m;
    cout<<endl;
    return0;
}

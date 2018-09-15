#include<iostream>
using namespace std;

#define EH 0                //等高
#define LH 1                //左高
#define RH -1               //右高

struct BinaryNode
{
    int bf;
    int value;
    BinaryNode *lch;
    BinaryNode *rch;
};

void LRotate(BinaryNode *pRoot)                             //RR型，左旋
{
    BinaryNode *pNewRoot = pRoot->rch;
    pRoot->rch = pNewRoot->lch;
    pNewRoot->lch = pRoot;
    pRoot = pNewRoot;
}

void RRotate(BinaryNode *pRoot)                             //LL型，右旋
{
    BinaryNode *pNewRoot = pRoot->lch;
    pRoot->lch = pNewRoot->rch;
    pNewRoot->rch = pRoot;
    pRoot = pNewRoot;
}

void LeftBalance(BinaryNode *pRoot)                         //左子树高于右子树，判断左-左还是左-右
{
    BinaryNode *lch, *lch_rch;                              //左孩子，左孩子的右孩子
    lch = pRoot->lch;
    lch_rch = lch->rch;

    switch(lch->bf)
    {
        case LH:
            lch->bf = pRoot->bf = EH;
            RRotate(pRoot);
            break;
        case RH:                                            //根据3种不同的情况，调整旋转后各子树的bf值
            switch(lch_rch->bf)
            {
                case LH:
                    pRoot->bf = RH;
                    lch->bf = EH;
                    break;
                case RH:
                    pRoot->bf = EH;
                    lch->bf = LH;
                    break;
                case EH:
                    pRoot->bf = EH;
                    lch->bf = EH;
                    break;
                default:
                    break;
            }
            lch_rch->bf = EH;
            LRotate(lch);
            RRotate(pRoot);
            break;
        default:
            break;
    }
}

void RightBalance(BinaryNode *pRoot)
{
    BinaryNode *rch, *rch_lch;
    rch = pRoot->rch;
    rch_lch = rch->lch;
    switch(rch->bf)
    {
        case RH:
            pRoot->bf = EH;
            rch->bf = EH;
            break;
        case LH:
            switch(rch_lch->bf)
            {
                case LH:
                    pRoot->bf = EH;
                    rch->bf = RH;
                    break;
                case RH:
                    pRoot->bf = LH;
                    rch->bf = EH;
                    break;
                case EH:
                    pRoot->bf = EH;
                    rch->bf = EH;
                    break;
                default:
                    break;
            }
            rch_lch->bf=EH;
            RRotate(rch);
            LRotate(pRoot);
            break;
    }
}

bool Insert(BinaryNode *&pRoot, int x, bool &Istaller)
{
    if(pRoot == nullptr)
    {
        pRoot = new BinaryNode;
        pRoot->bf = EH;
        pRoot->value = x;
        pRoot->lch = nullptr;
        pRoot->rch = nullptr;
        Istaller = true;
        return true;
    }
    else
    {
        if(pRoot->value == x)
        {
            Istaller = false;
            return false;
        }
        if(pRoot->value > x){
            if(!Insert(pRoot->lch, x, Istaller)){
                Istaller = false;
                return false;
            }
            if(Istaller){
                switch(pRoot->bf){
                    case LH:
                        LeftBalance(pRoot);
                        Istaller = false;
                        break;
                    case RH:
                        pRoot->bf = EH;
                        Istaller = false;
                        break;
                    case EH:
                        pRoot->bf = LH;
                        Istaller = true;
                        break;
                }
            }
        }
        else{
            if(!Insert(pRoot->rch, x, Istaller)){
                Istaller = false;
                return false;
            }
            if(Istaller){
                switch(pRoot->bf){
                    case LH:
                        pRoot->bf = EH;
                        Istaller = false;
                        break;
                    case RH:
                        RightBalance(pRoot);
                        Istaller = false;
                        break;
                    case EH:
                        pRoot->bf = RH;
                        Istaller = true;
                        break;
                }
            }
        }
    }
}

void InOrderTraverse(BinaryNode *pRoot)
{
    if(pRoot==nullptr)
        return;
    InOrderTraverse(pRoot->lch);
    cout<<pRoot->value<<"\t";
    InOrderTraverse(pRoot->rch);
}

int GetHeight(BinaryNode *pRoot)
{
    if(pRoot==nullptr)
        return 0;
    int leftHeight = GetHeight(pRoot->lch);
    int rightHeight = GetHeight(pRoot->rch);
    return leftHeight>rightHeight? leftHeight+1 : rightHeight+1;
}

int main(int argc, char *argv[])
{
    int arr[32] = {18,19,20,22,23,21,24,25,26,27,29,28,30,31,32,13,4,3,17,2,7,1,6,9,14,15,8,11,12,5,10,16};
    BinaryNode *pTree = nullptr;
    bool isTaller = false;

    for(int i=0; i<32; i++)
        Insert(pTree, arr[i], isTaller);

    cout<<"\n平衡二叉树建立完毕";
    cout<<"\n树的高度为："<<GetHeight(pTree)<<"\n中跟遍历平衡二叉树";
    InOrderTraverse(pTree);
    return 0;
}

//C++ file
/*=============================================
*
*      Filename: Leetcode/707.cpp
*
*        Author: Joe_CAO - flyinghrhino@163.com
*   Description: LeetCode 707
*        Create: 2018-08-28 14:34:11
# Last Modified: 2018-08-28 14:34:25
=============================================*/

using namespace std;
struct node
{
    int val;
    node *next;
};
class MyLinkedList {
private:
    node *Head;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
            Head = new node;
            Head->val = -1;
            Head->next =nullptr;
        }
    ~MyLinkedList(){
            node *p = Head->next;
            while(p!= nullptr)
            {
                    node *q = p;
                    p = p->next;
                    delete q;
                    }
            delete Head;
        }
    
    /** Get the value of the index-th node in the linked list. If the index is
     * invalid, return -1. */
    int get(int index) {
        if(index < 0)
            return -1;
        node *p = Head->next;
        int vv = 0;
        while(p != nullptr)
        {
            if (vv == index)
                return p->val;
            else
            {
                vv++;
                p=p->next;
            }
        }
            return -1;
        }
        
        /** Add a node of value val before the first element of the linked list.
         * After the insertion, the new node will be the first node of the
         * linked list. */
        void addAtHead(int val) {
                node *p = new node;
                p->val = val;
                p->next = Head->next;
                Head->next = p;
                
            }
            
            /** Append a node of value val to the last element of the linked
             * list. */
            void addAtTail(int val) {
                    node *p = new node;
                    node *q = Head->next;
                    p->val = val;
                    while(q->next != nullptr)
                        q = q->next;
                    q->next = p;
                }
            void addAtIndex(int index, int val) {
                node *p = new node;
                node *q = Head;
                node *t = q->next;
                p->val = val;
                int i = 0;
                while( i<index && t!= nullptr)
                {
                    q = q->next;
                    t = t->next;
                    i++;
                }
                if( i == index)
                {
                    p->next = q->next;
                    q->next = p;
                }
                }
                void deleteAtIndex(int index) {
                    node *q = Head;
                    node *t = q->next;
                    int i = 0;
                    while( i<index && t!= nullptr)
                    {
                        q = q->next;
                        t = t->next;
                        i++;
                    }
                    if( i == index && t!= nullptr)
                    {
                        q->next = t->next;
                        delete t;
                    }
                    }
};

int main(int argc, char* argv[])
{
    MyLinkedList linkedlist;
    linkedlist.addAtHead(1);
//    cout<<linkedlist.get(0)<<endl;
    linkedlist.addAtTail(3);
    linkedlist.addAtTail(4);
//    cout<<linkedlist.get(1)<<endl;
    linkedlist.addAtIndex(1,2);
    cout<<linkedlist.get(0)<<endl;
    cout<<linkedlist.get(1)<<endl;
    cout<<linkedlist.get(2)<<endl;
//    cout<<linkedlist.get(3)<<endl;
    linkedlist.deleteAtIndex(1);
    cout<<linkedlist.get(0)<<endl;
    cout<<linkedlist.get(1)<<endl;
    cout<<linkedlist.get(2)<<endl;
    return 0;
}

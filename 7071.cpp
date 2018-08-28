//C++ file
/*=============================================
*
*      Filename: Leetcode/7071.cpp
*
*        Author: Joe_CAO - flyinghrhino@163.com
*   Description: LeetCode 7071
*        Create: 2018-08-28 14:38:31
# Last Modified: 2018-08-28 14:38:46
=============================================*/

using namespace std; 
struct node
{ 
    int val; 
    node *next; 
}; 
class MyLinkedList { 
private: node *Head; 
public: /** Initialize your data structure here. */ 
         MyLinkedList() 
         { 
             Head = new node; 
             Head->val = -1; 
             Head->next =NULL; 
         } ~MyLinkedList(){ 
             node *p = Head->next; 
             while(p!= NULL) { 
                 node *q = p; 
                 p = p->next; 
                 delete q;
            }
            delete Head;
        }
        int get(int index) {
            if(index < 0)
                return -1;
            node *p = Head->next;
            node *q;
            int vv = 0;
            while(p!=NULL)
            {
                if (vv == index)
                {
                    return p->val;
                }
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
            while(q != NULL)
                q = q->next;
            q = p;
        }

        /** Add a node of value val before the index-th node in the
         * linked list. If index equals to the length of linked list,
         * the node will be appended to the end of linked list. If index
         * is greater than the length, the node will not be inserted. */
        void addAtIndex(int index, int val) {
            node *p = new node;
            node *q = Head;
            node *t = q->next;
            p->val = val;
            int i = 0;
            while( i<index && t!= NULL)
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

        /** Delete the index-th node in the linked list, if the
         * index is valid. */
        void deleteAtIndex(int index) {
            node *q = Head;
            node *t = q->next;
            int i = 0;
            while( i<index && t!= NULL)
            {
                q = q->next;
                t = t->next;
                i++;
            }
            if( i == index && t!= NULL)
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

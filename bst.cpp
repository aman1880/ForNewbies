#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
}*root=NULL;

void insert(int key){
    struct node *t,*p;
    struct node *r;
    t=root;

    if(root==NULL){
        p=new struct node;
        p->data=key;
        p->lchild=NULL;
        p->rchild=NULL;
        root=p;
        return;
    }
    
        
        while(t!=NULL){
            r=t;
            // if(t->data==key){
            //     cout<<"Element already exists!"<<endl;
            //     return;
            // }
            if(key>t->data){
                t=t->rchild;
            }
            else if(key<t->data){
                t=t->lchild;
            }
            else{
                return;
            }
        }
        //struct node *p;
        p=new struct node;
        p->lchild=NULL;
        p->rchild=NULL;
        p->data=key;

        if(key>r->data){
            r->rchild=p;
        }
        else{
            r->lchild=p;
        }

}

void search(int key){
    struct node *t;
    t=root;
     while(t!=NULL){
            if(t->data==key){
                cout<<"Element found!"<<endl;
                return;
            }
            else if(key>t->data){
                t=t->rchild;
            }
            else{
                t=t->lchild;
            }
        }
        cout<<"Element not found!"<<endl;
}

void inorder(struct node *t){
    if(t!=NULL){
        inorder(t->lchild);
        cout<<t->data<<" ";
        inorder(t->rchild);
    }
}

void preorder(struct node *t){
    if(t){
        cout<<t->data<<" ";
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void postorder(struct node *t){
    if(t){
        postorder(t->lchild);
        postorder(t->rchild);
        cout<<t->data<<" ";
    }
}

struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    while (current && current->lchild != NULL)
        current = current->lchild;
 
    return current;
}

struct node* del(struct node *root,int key){
    if(root=NULL){
        return root;
    }
    if(key<root->data){
        root->lchild=del(root->lchild,key);
    }
    else if(key>root->data){
        root->rchild=del(root->rchild,key);
    }
    else{
        if(root->lchild==NULL && root->rchild==NULL){
            return NULL;
        }
        else if(root->rchild==NULL){
            struct node *temp;
            temp=root->lchild;
            free(root);
            return temp;
        }
        else if(root->lchild==NULL){
            struct node *temp;
            temp=root->rchild;
            free(root);
            return temp;
        }

    }
}


int main(){
    insert(29);
   // insert(30);
   // insert(31);
    insert(30);
    insert(25);
    insert(300);
    insert(3000);
    //insert(28);
  //  search(29);
  //  search(28);
    inorder(root);
    preorder(root);
    postorder(root);
}

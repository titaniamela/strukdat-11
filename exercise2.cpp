/*
Nama        : Shania Salsabila
NPM         : 140810180004
Kelas       : B
Deskripsi   : Exercise2 (Soal 2)
*/


#include <iostream>

using namespace std;

struct simpul{
    int info;
    simpul* left;
    simpul* right;
};

typedef simpul* pointer;
typedef pointer tree;

void createSimpul (pointer& pBaru){
    pBaru = new simpul;

    cout<<"Masukkan satu angka: "; cin>> pBaru->info;
    pBaru->left = NULL;
    pBaru->right = NULL;
}

void insertBST (tree& root, pointer pBaru){
    if (root == NULL){
        root = pBaru;
    }
    else if (pBaru->info < root->info){
        insertBST(root->left, pBaru);
    }
    else if (pBaru->info >= root->info){
        insertBST(root->right, pBaru);
    }
}

void preOrder (tree root){
    if (root != NULL){
        cout<<root->info<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder (tree root){
    if (root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->info<<" ";
    }
}

void inOrder (tree root){
    if (root != NULL){
        inOrder(root->left);
        cout<<root->info<<" ";
        inOrder(root->right);
    }
}

int kedalaman (tree root){
    if(root==NULL){
        return 0;
    }
    else{
        int tleft = kedalaman(root->left);
        int tright = kedalaman(root->right);
        if (tleft > tright) return (tleft+1);
        else return (tright+1);
    }
}

void givenLevel(tree root, int level){
    if (root==NULL)
        return;
    if (level==1)
        cout<<root->info<<" ";
    else if (level>1){
        givenLevel(root->left,level-1);
        givenLevel(root->right,level-1);
    }
}

void levelOrder(tree root){
    int h = kedalaman(root);
    for (int i=1; i<=h; i++){
        cout<<i<<": ";
        givenLevel(root,i);
        cout<<endl;
    }
}

void printChildren(tree root, pointer pBaru){
    pBaru = root;
    if(pBaru != NULL){
        cout<<"Orang Tua : "<<pBaru->info<<endl;
        cout<<"Anak : "<<endl;
        if(pBaru->left==NULL)
            cout<<"Kiri : Tidak Ada"<<endl;
        else
            cout<<"Kiri : "<<pBaru->left->info<<endl;
        if(pBaru->right==NULL)
            cout<<"Kanan : Tidak Ada"<<endl;
        else
            cout<<"Kanan : "<<pBaru->right->info<<endl;
        cout<<endl;
        printChildren(root->left, pBaru);
        printChildren(root->right, pBaru);
    }
}


int main() {
    pointer p;
    tree t;
    int pil;
    int level;

    while(1){
    	cout<<"|---------------|"<<endl
        cout<<"|      Menu     |"<<endl;
        cout<<"|1. insertBS    |"<<endl;
        cout<<"|2. preorder    |"<<endl;
        cout<<"|3. inorder     |"<<endl;
        cout<<"|4. postorder   |"<<endl;
        cout<<"|5. kedalaman   |"<<endl;
        cout<<"|6. level       |"<<endl;
        cout<<"|7. anak        |"<<endl;
        cout<<"|8. exit        |"<<endl;
        cout<<"|---------------|"<<endl;
        cout<<"Pilihan: "; cin>>pil;
        cout<<endl;

        switch(pil){
            case 1:
                cout<<"Input Data"<<endl;
                createSimpul(p);
                insertBST(t, p);
                cout<<endl;
                break;

            case 2:
                cout<<"Pre-Order Traversal"<<endl;
                preOrder(t);
                cout<<endl;
                break;

            case 3:
                cout<<"In-Order Traversal"<<endl;
                inOrder(t);
                cout<<endl;
                break;

            case 4:
                cout<<"Post-Order Traversal"<<endl;
                postOrder(t);
                cout<<endl;
                break;

            case 5:
                cout<<"Depth of Tree"<<endl;
                kedalaman(t);
                cout<<kedalaman(t);
                cout<<endl;
                break;

            case 6:
                cout<<"Level of Tree"<<endl;
                level = kedalaman(t)+1;
                cout<<level;
                cout<<endl;
                break;

            case 7:
                cout<<"Tree's Child"<<endl;
                printChildren(t,p);
                cout<<endl;
                break;

            case 8:
                return 0;
                break;
        }
    }
    return 0;
}

#include <iostream>
using namespace std;
typedef int element_type;
typedef struct node
{
    element_type element;
    struct node*light,*right;
}NODE;
NODE*root;
void khoi_tao_cay(NODE*root)
{
    root = NULL;
}
void insert(NODE*temp, NODE*node)
{
    if(temp->element < (*root)->element)
      if((*root)->left)
        insert(temp, &(*root)->left);
      else
        (*root)->left = temp;
      else if (root->right)
         insert(temp, &root->right);
    else
       root->right = temp;
}
void insert_node(element_type e, NODE*root)
{
    NODE*temp;
    temp = (NODE*)malloc(sizeof(NODE));
    temp->element = e;
    temp->left = NULL;
    temp->right = NULL;
    if(*root!==NULL)
        *root = temp;
    else
      insert(temp, root);
}
void nhap_cay(NODE*root)
{
element_type e;
do
  {
    cout<<"\n Nhap element (-1 de ket thuc):"; cin>>e;
    if(e != -1)
       insert_node(e, root);
  }
  while (e != -1);

}
int dem_nut(NODE*root)
{if (root==NULL) return 0;
else return dem_nut(root->left) + dem_nut(root->right)+1;
}
int dem_nut_rong(NODE*root)
{if (NULL==root) return 1;
else 
    return dem_nut_rong(root-> left) + dem_nut_rong(root-> right);
}
void main()
{
    clrscr; 
    int tong_nut, tong_nut_trong;
    khoi_tao_cay(&root);
    nhap_cay(&root);
    tong_nut=dem_nut(root);
    tong_nut_rong=dem_nut_rong(root);
    cout<<"\nTong so nut cua cay ="<<tong_nut;
    cout<<"\nTong so nut rong="<<tong_nut_rong;
}
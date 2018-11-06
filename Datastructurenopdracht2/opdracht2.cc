
struct node {

  int data;
  node* left;
  node* right;

}


void PreOrder (node *root){

  cout << root->data << ;
  if (root->left != NULL)
    PreOrder(root->left);
  if (root->right != NULL)
    PreOrder(root->right);

}

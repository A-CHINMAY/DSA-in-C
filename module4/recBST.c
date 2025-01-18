tree_pointer search(tree_pointer root, int key)
{
    if (!root)
        return NULL;
    if (key == root->data)
        return root;
    if (key < root->data)
        return search(root->left_child, key);
    return search(root->right_child, key);
}
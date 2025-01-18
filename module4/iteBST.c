
tree_pointer search2(tree_pointer tree, int key) {
    while (tree) {
        if (key == tree->data)
            return tree;
        if (key < tree->data)
            tree = tree->left_child;
        else
            tree = tree->right_child;
    }
    return NULL;
}

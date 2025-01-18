void insert_node(TreePointer *node, int num) {
    
    TreePointer ptr, temp = modified_search(*node, num);

    if (temp || !(*node)) {
        ptr = (TreePointer)malloc(sizeof(TreeNode));

        if (ptr == NULL) {
            fprintf(stderr, "The memory is full\n");
            exit(1);
        }
        ptr->data = num;
        ptr->left = NULL;
        ptr->right = NULL;

        if (*node) {
            /* insert as child of temp */
            if (num < temp->data)
                temp->left = ptr;
            else
                temp->right = ptr;
        }
        else {
            *node = ptr;
        }
    }
}

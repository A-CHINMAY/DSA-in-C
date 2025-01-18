void insert_node(TreePointer *node, int num) {
    
    TreePointer ptr, temp = modified_search(*node, num);

    if (temp || !(*node)) {
        ptr = (TreePointer)malloc(sizeof(TreeNode));

        if (ptr == NULL) {
            printf("The memory not allocated\n");
            exit(1);
        }
        ptr->data = num;
        ptr->left = NULL;
        ptr->right = NULL;

        if (*node) {
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


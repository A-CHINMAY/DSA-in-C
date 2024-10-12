#include <stdio.h>
#include <stdlib.h>
int a[20];
int n, val, i, pos;
int main() {
    int choice;
    while (choice) {
        printf("\n\n--------MENU-----------\n");
        printf("1.CREATE\n");
        printf("2.DISPLAY\n");
        printf("3.INSERT\n");
        printf("4.DELETE\n");
        printf("5.EXIT\n");
        printf("-----------------------");
        printf("\nENTER YOUR CHOICE:\t");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete ();
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid choice:\n");
            break;
        }
    }
}
// creating an array
void create() {
    printf("\nEnter the size of the array elements:\t");
        scanf("%d", &n);
    printf("\nEnter the elements for the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

}
// displaying an array elements
void display() {
    int i;
    printf("\nThe array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
}
// inserting an element into an array
void insert() {
    printf("\nEnter the position for the new element:\t");
    scanf("%d", &pos);
    printf("\nEnter the element to be inserted :\t");
    scanf("%d", &val);
    for (i = n - 1; i >= pos; i--) {
        a[i + 1] = a[i];
    }
    a[pos] = val;
    n = n + 1;
}
// deleting an array element
void delete() {
    printf("\nEnter the position of the element to be deleted:\t");
    scanf("%d", &pos);
    val = a[pos];
    for (i = pos; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n = n - 1;
    printf("\nThe deleted element is =%d", val);
}
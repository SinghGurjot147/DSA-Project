#include <stdio.h>
#include <string.h>

#define MAX 100

struct Item {
    char name[50];
    int quantity;
    float price;
};

struct Item stack[MAX];
int top = -1;

void push(struct Item item) {
    if (top >= MAX - 1) {
        printf("Cart is full!\n");
        return;
    }
    stack[++top] = item;
}

struct Item pop() {
    if (top < 0) {
        printf("Cart is empty!\n");
        struct Item empty = {"", 0, 0.0};
        return empty;
    }
    return stack[top--];
}

void displayCart() {
    if (top == -1) {
        printf("Cart is empty!\n");
        return;
    }
    printf("Items in cart:\n");
    for (int i = 0; i <= top; i++) {
        printf("%s x%d - %.2f\n", stack[i].name, stack[i].quantity, stack[i].price);
    }
}

void generateBill() {
    float total = 0;
    printf("\nGenerating Bill:\n");
    for (int i = 0; i <= top; i++) {
        printf("%s x%d = %.2f\n", stack[i].name, stack[i].quantity, stack[i].price * stack[i].quantity);
        total += stack[i].price * stack[i].quantity;
    }
    printf("Total Amount: %.2f\n", total);
}

int main() {
    int choice;
    struct Item item;

    do {
        printf("\n1. Add Item\n2. Remove Last Item\n3. View Cart\n4. Generate Bill\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item name, quantity and price: ");
                scanf("%s %d %f", item.name, &item.quantity, &item.price);
                push(item);
                break;
            case 2:
                item = pop();
                if (strlen(item.name) > 0)
                    printf("Removed: %s\n", item.name);
                break;
            case 3:
                displayCart();
                break;
            case 4:
                generateBill();
                break;
        }
    } while (choice != 5);

    return 0;
}

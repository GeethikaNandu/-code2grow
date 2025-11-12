#include <stdio.h>

int main() {
    int price[5] = {50, 30, 80, 120, 60};
    char item[5][10] = {"Coffee", "Tea", "Sandwich", "Burger", "Pastry"};
    int cust, i, j, n, itemNo, qty;
    int qtySold[5] = {0}, totalRevenue = 0;

    printf("Enter total number of customers (max 10): ");
    scanf("%d", &cust);

    for(i = 1; i <= cust; i++) {
        int total = 0;
        printf("Customer %d \n", i);
        printf("Enter number of items: ");
        scanf("%d", &n);

        for(j = 0; j < n; j++) {
            printf("Enter item number and quantity: ");
            scanf("%d %d", &itemNo, &qty);
            total += price[itemNo - 1] * qty;
            qtySold[itemNo - 1] += qty;
        }

        printf("Total Bill for Customer %d = Rs.%d\n", i, total);
        totalRevenue += total;
    }

    int most = 0, totalItems = 0;
    for(i = 0; i < 5; i++) {
        totalItems += qtySold[i];
        if(qtySold[i] > qtySold[most])
            most = i;
    }

    printf(" Cafe Summary\n");
    printf("Total Revenue: ₹%d\n", totalRevenue);
    printf("Total Items Sold: %d\n", totalItems);
    printf("Most Ordered Item: %s\n", item[most]);

    return 0;
}
/* Q10. ATM Transaction System

• Create a menu-driven program to check balance, deposit money,
  withdraw money, and exit.
• Prevent a withdrawal when the balance is insufficient.
• Maintain and display the last five transactions. */
#include <stdio.h>

int main() {
    float balance = 10000;
    float transactions[5];
    float amount;

    int count = 0;
    int choice, i;

    do {

        printf("\n\n--- ATM Menu ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Last Five Transactions\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1) {

            printf("Current balance = %.2f", balance);
        }

        else if(choice == 2) {

            printf("Enter deposit amount: ");
            scanf("%f", &amount);

            if(amount > 0) {

                balance += amount;

                if(count < 5) {
                    transactions[count] = amount;
                    count++;
                }
                else {
                    for(i = 0; i < 4; i++)
                        transactions[i] = transactions[i + 1];

                    transactions[4] = amount;
                }

                printf("Amount deposited successfully.");
            }
        }

        else if(choice == 3) {

            printf("Enter withdrawal amount: ");
            scanf("%f", &amount);

            if(amount > balance) {
                printf("Insufficient balance.");
            }
            else if(amount > 0) {

                balance -= amount;

                if(count < 5) {
                    transactions[count] = -amount;
                    count++;
                }
                else {
                    for(i = 0; i < 4; i++)
                        transactions[i] = transactions[i + 1];

                    transactions[4] = -amount;
                }

                printf("Amount withdrawn successfully.");
            }
        }

        else if(choice == 4) {

            printf("\nLast five transactions:\n");

            for(i = 0; i < count; i++) {

                if(transactions[i] > 0)
                    printf("Deposit: +%.2f\n", transactions[i]);
                else
                    printf("Withdrawal: %.2f\n", transactions[i]);
            }
        }

    } while(choice != 5);

    printf("Thank you for using ATM.");

    return 0;
}

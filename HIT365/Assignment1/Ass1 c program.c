#include <stdio.h>

int main(void) {
    int pay_code, employee_count = 0;
    float total_pay = 0, employee_pay;
    printf("Enter the pay code for the employee (1 for manager, 2 for hourly worker, 3 for commission worker, 4 for pieceworker): ");
    scanf_s("%d", &pay_code);
    while (pay_code >= 1 && pay_code <= 4) {
        employee_count++;
        switch(pay_code) {
            case 1:
                employee_pay = calculate_manager_pay();
                break;
            case 2:
                employee_pay = calculate_hourly_pay();
                break;
            case 3:
                employee_pay = calculate_commission_pay();
                break;
            case 4:
                employee_pay = calculate_pieceworker_pay();
                break;
            printf("The weekly pay for this employee is: $%10.2f\n", employee_pay);
            default:
                printf("Invalid pay code.\n");
}

// Function to calculate the pay for managers
float calculate_manager_pay() {
    float weekly_salary;
    printf("Enter the weekly salary for the manager: ");
    scanf_s("%f", &weekly_salary);
    return weekly_salary;
}

// Function to calculate the pay for hourly workers
float calculate_hourly_pay() {
    float hourly_wage, hours_worked, overtime_pay;
    printf("Enter the hourly wage for the hourly worker: ");
    scanf_s("%f", &hourly_wage);
    printf("Enter the number of hours worked by the hourly worker: ");
    scanf_s("%f", &hours_worked);
    if (hours_worked <= 40) {
        return hourly_wage * hours_worked;
    } else {
        overtime_pay = (hours_worked - 40) * 1.5 * hourly_wage;
        return (hourly_wage * 40) + overtime_pay;
    }
}

// Function to calculate the pay for commission workers
float calculate_commission_pay() {
    float sales_item_a, sales_item_b, sales_item_c, commission_rate_a, commission_rate_b, commission_rate_c;
    printf("Enter the gross weekly sales for Item A: ");
    scanf_s("%d", &sales_item_a);
    printf("Enter the gross weekly sales for Item B: ");
    scanf_s("%d", &sales_item_b);
    printf("Enter the gross weekly sales for Item C: ");
    scanf_s("%f", &sales_item_c);
    commission_rate_a = 0.057;
    commission_rate_b = 0.064;
    commission_rate_c = 0.072;
    return 250 + (sales_item_a * commission_rate_a) + (sales_item_b * commission_rate_b) + (sales_item_c * commission_rate_c);
}

// Function to calculate the pay for pieceworkers
float calculate_pieceworker_pay() {
    float item1_pay, item2_pay, item3_pay, total_pay;
    int item1_qty, item2_qty, item3_qty;
    printf("Enter the number of Item 1 produced by the pieceworker: ");
    scanf_s("%f", &item1_qty);
    printf("Enter the number of Item 2 produced by the pieceworker: ");
    scanf_s("%f", &item2_qty);
    printf("Enter the number of Item 3 produced by the pieceworker: ");
    scanf_s("%f", &item3_qty);
    item1_pay = 22.5 * item1_qty;
    item2_pay = 24.5 * item2_qty;
    item3_pay = 26.0 * item3_qty;
    total_pay = item1_pay + item2_pay + item3_pay;
    return total_pay;
}

  
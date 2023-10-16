#include <stdio.h>
#define length 12
/* Author: Humza Qureshi
    creation date: 10-15-2023
    */

void print_array(double sales_array[], const char* months[]){
    printf("                              \n");
    printf("Monthly Sales report for 2022\n");
    printf("                               \n");
    printf("Month         Sales\n");
    for (int i = 0; i < length; i++ ){
        printf("%-12s $%lf\n", months[i], sales_array[i]);
    }
}

double get_min(double sales_array[]){
    double min = sales_array[0];
    for (int i = 0; i < length; i ++ ){
        if (sales_array[i] < min){
            min = sales_array[i];
        }
    }
    return min;
}

double get_max(double sales_array[]){
    double max = sales_array[0];
    for (int i = 0; i < length; i++){
        if (sales_array[i] > max){
            max = sales_array[i];

        }
    }
    return max;

}

double get_average(double sales_array[]){
    double sum = 0;
    for (int i = 0; i < length; i++){
        sum = sum + sales_array[i];
    }
    return sum / length;
}

void six_average(double sales_array[], const char* months[]){
    double average_array[length];
    double sum = 0;
    for (int i = 0; i < 7; i++){
         for (int j = 0; j < 6; j++){
        sum = sum + sales_array[i+j];
        average_array[i] = sum/6;
        
        }
        sum = 0;// reset the sum back to 0 after each iteration of the first for loop
        printf("%-11s - %-11s $%11lf\n", months[i], months[i + 5], average_array[i]);
    }
}

void high_to_low(double sales_array[], const char* months[] ){
    double a;
    double must_sort[length]= {23458.01, 40112.00,  56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    for (int i = 0; i < length; ++i){
      for (int j = i + 1; j < length; ++j){    
        //Here I am implementing selection sort for the high to low sales report             
         if (must_sort[i] < must_sort[j]){
            a = must_sort[i];
            must_sort[i] = must_sort[j];
            must_sort[j] = a;
            }
        }
    }
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
            if (must_sort[i] == sales_array[j]){
                printf("%-11s $%lf\n", months[j], must_sort[i]);
            }
        }
    }


}
int main(){
    double sales_array[length]= {23458.01, 40112.00,  56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    const char* months[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    print_array(sales_array, months);
    printf("\n");
    printf("Sales summary: ");
    printf("\n");
    printf("Min: $%-11lf  (%s)\n",get_min(sales_array), months[0]);
    printf("Max: $%-11lf  (%s)\n", get_max(sales_array), months[11]);
    printf("Average: $%-11lf\n", get_average(sales_array));
    printf("\n");
    printf("Six-month Moving Average Report: \n");
    six_average(sales_array, months);
    printf("\n");
    printf("High-to-Low Sales summary: \n");
    high_to_low(sales_array, months);

    return 0;
}
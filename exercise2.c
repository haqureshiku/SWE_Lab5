#include <stdio.h>
#include <stdbool.h>
/* Author: Humza Qureshi
    creation date: 10-15-2023
    */

int main(){

    bool x = true;
    while (x){
    int score;
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &score);
    if (score <=1){
        x = false;
    }
    
    else{
        int score_total;
        for (int td_2 = 0; td_2 *8 <= score; td_2++){
            for (int td_1 = 0; td_1*7 <=score; td_1++){
                for (int td = 0; td *6 <= score; td++){
                    for (int fg = 0; fg *3 <= score; fg++){
                        for (int safety = 0; safety * 2 <= score; safety++){
                            score_total = (td_2*8) + (td_1 *7) + (td*6) + (fg*3) + (safety*2);
                            if (score == score_total){
                                printf("%d TD + 2pt, %d TD+ FG, %d TD, %d 3pt FG, %d Safety\n", td_2, td_1, td, fg, safety);
                            }
                            

                        }

                    }
                }
            }
        }
        

    }
    }

    return 0;
}
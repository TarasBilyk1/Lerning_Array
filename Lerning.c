#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void fifty_fifty(int array_random[], int arry_size);

int main(void) {
    srand((unsigned int)time(NULL));

    int Array_NUM[8];
    int arry_for_guess[3];
    int chek_stop = 0;
    short win = 0;
    short loss = 0;
    short game = 0;
    bool Stop = false;

    FILE* file;
    errno_t err = fopen_s(&file, "stats.txt", "a");

    if (err != 0) {
        printf("Помилка при відкритті файлу!\n");
        return 1;
    }

    do {
        game++;

        printf("Guess a number from 1 to 100: ");
        fifty_fifty(Array_NUM, 8);
        scanf_s("%d %d %d", &arry_for_guess[0], &arry_for_guess[1], &arry_for_guess[2]);

        int max = Array_NUM[0];
        for (short i = 0; i < 8; i++) {
            if (Array_NUM[i] > max) {
                max = Array_NUM[i];
            }
        }
        printf("Your max number in the array = %d\n", max);

        if (arry_for_guess[0] == max || arry_for_guess[1] == max || arry_for_guess[2] == max) {
            printf("You Win! :)\nArr = ");
            win++;
        }
        else {
            printf("You Lose! :(\nArr = ");
            loss++;
        }

        for (short i = 0; i < 8; i++) {
            printf("%d, ", Array_NUM[i]);
        }

        printf("\n\nIf you want to continue the game, press 0; if you want to end it, press 1: ");
        scanf_s("%d", &chek_stop);

        if (chek_stop == 1) {
            Stop = true;
        }
        else if (chek_stop != 0) {
            printf("You entered the wrong number.\n");
        }

        printf("\nYou Win %d, You Lose %d\n", win, loss);

    } while (!Stop);


    fprintf(file, "Some info!!!\nYou all game! %d\nYour win %d\nYour loss %d\n", game, win, loss);

    fclose(file);

    return 0;
}

void fifty_fifty(int array_random[], int arry_size) {
    for (short i = 0; i < arry_size; i++)
        array_random[i] = rand() % 100 + 1;
}

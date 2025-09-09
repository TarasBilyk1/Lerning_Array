#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <setjmp.h>

jmp_buf buf_return_to_write;
jmp_buf buf_check;

void fifty_fifty(int array_random[], int arry_size);
void return_to_Writhe_Fan(int arry_for_guess[], int arry_size);
void throw_exc(error_code);
void check_Fan(chek_stop);
void T_throw_exc(error_code);
bool check_input_valid(num_read, expected_num);
void throw_guess_exc(error_code);
void next_game_exc(error_code);

int main(void) {
    srand((unsigned int)time(NULL));

    int Array_NUM[8];
    int arry_for_guess[3];
    int chek_stop = 0;
    short win = 0;
    short loss = 0;
    short game = 0;
    bool Stop = false;
    bool S_return_to_write = false;
    bool S_check = false;


    FILE* files;
    errno_t prev = fopen_s(&files, "Preview.txt", "r");

    if (prev != 0){
        printf("File not found !");
        return 1;
    }

    int character;
    while ((character = fgetc(files)) != EOF) {
        printf("%c", character);
    }

    FILE* file;
    errno_t err = fopen_s(&file, "stats.txt", "a");

    if (err != 0) {
        printf("File not found !\n");
        return 1;
    }

    do {
        game++;

        printf("\n\n\nGuess a number from 1 to 100: ");
        fifty_fifty(Array_NUM, 8);

        // Тут ввід чисел для вгадування та перевірка на помилку 
        do {
            int return_to_write = setjmp(buf_return_to_write);

            if(return_to_write != 0) {  
                printf("Error to writhe ! \nEntered another num ! --> ");
            }
            int num_read = scanf_s("%d %d %d", &arry_for_guess[0], &arry_for_guess[1], &arry_for_guess[2]);

            if (!check_input_valid(num_read, 3)) {
                throw_guess_exc(1); 
            }

            return_to_Writhe_Fan(arry_for_guess,3); 

            S_return_to_write = true;

        } while (!S_return_to_write);
        // Пошук максимального числа масиву
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
        // Робота з продовженням гри чи ні і перевірка на помилки  
        do {
            int check = setjmp(buf_check);

            if (check != 0) {
                printf("Error to writhe !");
            }
            printf("\n\nIf you want to continue the game, press 0; if you want to end it, press 1: ");
            int next_game = scanf_s("%d", &chek_stop);

            if (!check_input_valid(next_game, 1)) {
                next_game_exc(1);
            }

            check_Fan(chek_stop);

            S_check = true;

        } while (!S_check);
        
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

// Функація випаткового вводу чисел в масив 
void fifty_fifty(int array_random[], int arry_size) {
    for (short i = 0; i < arry_size; i++)
        array_random[i] = rand() % 100 + 1;
}
// Функія знаходження виннятку в вводі чисел для угадування 
void return_to_Writhe_Fan(int arry_for_guess[], int arry_size) {
    for (int p = 0; p < arry_size ;p++ ) {
        if (arry_for_guess[p] < 0 || arry_for_guess[p]> 100) {
            throw_exc(1);
        }
    }
}

void check_Fan(int chek_stop) {
    if(chek_stop < 0 || chek_stop > 1) {
        T_throw_exc(1);
    }
}
// Функції повернення коду помилки
void throw_exc(int error_code) {
    longjmp(buf_return_to_write, error_code);
}

void T_throw_exc(int error_code) {
    longjmp(buf_check, error_code);
}

bool check_input_valid(int num_read, int expected_num) {
    if (num_read != expected_num) {
        while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
        return false;
    }
    return true;
}

void throw_guess_exc(int error_code) {
    longjmp(buf_return_to_write, error_code);
}

void next_game_exc(int error_code) {
    longjmp(buf_check, error_code);
}
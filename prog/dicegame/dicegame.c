#include <starlib.h>
#include <kernel.h>
#include <monitor_mode_txt.h>
#include <pit.h>

#include "dicegame.h"

bool loop_game = true;
int score = 0;

void show_title() {
    set_foreground_colour(11);
    print_at("Dice Game!", 35, 0);
}

void game() {
    while (loop_game) {
        int dice_one = rand_range(1, 6);
        int dice_two = rand_range(1, 6);
        srand(get_ticks());

        set_foreground_colour(14);
        print("You rolled a ");
        print_n(dice_one);
        print(" and a ");
        print_n(dice_two);
        print("\n");

        if (dice_one == dice_two) {
            set_foreground_colour(4);
            print("Both your dice were the same! You lose!\n");
            read();
            loop_game = false;
        } else {
            score = score + dice_one + dice_two;
            set_foreground_colour(10);
            print("You rolled different dice! Your score is now ");
            print_n(score);
            print("\n");
            print("Keep playing? (Y/N): ");
            set_foreground_colour(15);
            char *choice = read();
            if (choice[0] != 'Y' && choice[0] != 'y') loop_game = false;
            print("\n");
        }
    }
}

void play_game() {
    while(true) {
        clear_screen();
        show_title();
        print("\n");
        loop_game = true;
        score = 0;
        game();
        print("Game over! Your final score is ");
        print_n(score);
        sleep(1000);
    }
}

void run_game() {
    sleep(10);
    play_game();
}
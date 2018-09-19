#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

void start_game();
void reset_game();
void move_left();
void move_right();
void move_up();
void move_down();

void refresh_show();
void add_rand_num();
void check_game_over();
int get_null_count();

int board[4][4];
int score;
int best;
int if_need_add_num;
int if_game_over;

int main() {
    start_game();
}

void start_game() {
    reset_game();
    char cmd;

    while (1) {
        cmd = getch();

        if (if_game_over) {
            if (cmd == 'y' || cmd == 'Y') {
                reset_game();
                continue;
            } else if (cmd == 'n' || cmd == 'N') {
                return;
            } else {
                continue;
            }
        }

        if_need_add_num = 0;

        switch (cmd) {
        case 'a':
        case 'A':
        case 75 :
            move_left();
            break;

        case 's':
        case 'S':
        case 80 :
            move_down();
            break;

        case 'w':
        case 'W':
        case 72 :
            move_up();
            break;

        case 'd':
        case 'D':
        case 77 :
            move_right();
            break;
        }

        score > best ? best = score : 1;

        if (if_need_add_num) {
            add_rand_num();
            refresh_show();
        }
    }
}
void reset_game() {
    score = 0;
    if_need_add_num = 1;
    if_game_over = 0;
    int n = rand() % 16;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = (n-- == 0 ? 2 : 0);
        }
    }

    add_rand_num();
    system("cls");
    refresh_show();
}
void add_rand_num() {
    srand(time(0));
    int n = rand() % get_null_count();

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0 && n-- == 0) {
                board[i][j] = (rand() % 3 ? 2 : 4);
                return;
            }
        }
    }
}
int get_null_count() {
    int n = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] == 0 ? n++ : 1;
        }
    }

    return n;
}
void check_game_over() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == board[i][j+1] || board[j][i] == board[j+1][i]) {
                if_game_over = 0;
                return;
            }
        }
    }

    if_game_over = 1;
}
void move_left() {
    for (int i = 0; i < 4; i++) {
        for (int j = 1, k = 0; j < 4; j++) {
            if (board[i][j] > 0) {
                if (board[i][k] == board[i][j]) {
                    score += board[i][k++] <<= 1;
                    board[i][j] = 0;
                    if_need_add_num = 1;
                } else if (board[i][k] == 0) {
                    board[i][k] = board[i][j];
                    board[i][j] = 0;
                    if_need_add_num = 1;
                } else {
                    board[i][++k] = board[i][j];

                    if (j != k) {
                        board[i][j] = 0;
                        if_need_add_num = 1;
                    }
                }
            }
        }
    }
}
void move_right() {
    for (int i = 0; i < 4; i++) {
        for (int j = 2, k = 3; j >= 0; j--) {
            if (board[i][j] > 0) {
                if (board[i][k] == board[i][j]) {
                    score += board[i][k--] <<= 1;
                    board[i][j] = 0;
                    if_need_add_num = 1;
                } else if (board[i][k] == 0) {
                    board[i][k] = board[i][j];
                    board[i][j] = 0;
                    if_need_add_num = 1;
                } else {
                    board[i][--k] = board[i][j];

                    if (j != k) {
                        board[i][j] = 0;
                        if_need_add_num = 1;
                    }
                }
            }
        }
    }
}
void move_up() {
    for (int i = 0; i < 4; i++) {
        for (int j = 1, k = 0; j < 4; j++) {
            if (board[j][i] > 0) {
                if (board[k][i] == board[j][i]) {
                    score += board[k++][i] <<= 1;
                    board[j][i] = 0;
                    if_need_add_num = 1;
                } else if (board[k][i] == 0) {
                    board[k][i] = board[j][i];
                    board[j][i] = 0;
                    if_need_add_num = 1;
                } else {
                    board[++k][i] = board[j][i];

                    if (j != k) {
                        board[j][i] = 0;
                        if_need_add_num = 1;
                    }
                }
            }
        }
    }
}
void move_down() {
    for (int i = 0; i < 4; i++) {
        for (int j = 2, k = 3; j >= 0; j--) {
            if (board[j][i] > 0) {
                if (board[k][i] == board[j][i]) {
                    score += board[k--][i] <<= 1;
                    board[j][i] = 0;
                    if_need_add_num = 1;
                } else if (board[k][i] == 0) {
                    board[k][i] = board[j][i];
                    board[j][i] = 0;
                    if_need_add_num = 1;
                } else {
                    board[--k][i] = board[j][i];

                    if (j != k) {
                        board[j][i] = 0;
                        if_need_add_num = 1;
                    }
                }
            }
        }
    }
}
void refresh_show() {
    COORD pos = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

    printf("\n\n\n\n");
    printf(" GAME: 2048 SCORE: %06d BEST: %06d\n", score, best);
    printf(" --------------------------------------------------\n\n");
    printf(" ©°©¤©¤©Ð©¤©¤©Ð©¤©¤©Ð©¤©¤©´\n");

    for (int i = 0; i < 4; i++) {
        printf(" ©¦");

        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 0) {
                if (board[i][j] < 10) {
                    printf(" %d ©¦", board[i][j]);
                } else if (board[i][j] < 100) {
                    printf(" %d ©¦", board[i][j]);
                } else if (board[i][j] < 1000) {
                    printf(" %d©¦", board[i][j]);
                } else if (board[i][j] < 10000) {
                    printf("%4d©¦", board[i][j]);
                } else {
                    int n = board[i][j];

                    for (int k = 1; k < 20; k++) {
                        n >>= 1;

                        if (n == 1) {
                            printf("2^%02d©¦", k);
                            break;
                        }
                    }
                }
            } else printf(" ©¦");
        }

        if (i < 3) {
            printf("\n ©À©¤©¤©à©¤©¤©à©¤©¤©à©¤©¤©È\n");
        } else {
            printf("\n ©¸©¤©¤©Ø©¤©¤©Ø©¤©¤©Ø©¤©¤©¼\n");
        }
    }

    printf("\n");
    printf(" --------------------------------------------------\n");
    printf(" W¡ü A¡û D¡ú ¡ýS");

    if (get_null_count() == 0) {
        check_game_over();

        if (if_game_over) {
            printf("\r GAME OVER! TRY THE GAME AGAIN? [Y/N]");
        }
    }
}


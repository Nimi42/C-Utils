#include "str-int-dict.h"

int main(void) {
    struct Dict *chess_board = dict_create_str_int(5);
/*
     56 57 58 59 60 61 62 63     A8 B8 C8 D8 E8 F8 G8 H8 
     48 49 50 51 52 53 54 55     A7 B7 C7 D7 E7 F7 G7 H7
     40 41 42 43 44 45 46 47     A6 B6 C6 D6 E6 F6 G6 H6
     32 33 34 35 36 37 38 39     A5 B5 C5 D5 E5 F5 G5 H5
     24 25 26 27 28 29 30 31     A4 B4 C4 D4 E4 F4 G4 H4
     16 17 18 19 20 21 22 23     A3 B3 C3 D3 E3 F3 G3 H3
      8  9 10 11 12 13 14 15     A2 B2 C2 D2 E2 F2 G2 H2
      0  1  2  3  4  5  6  7     A1 B1 C1 D1 E1 F1 G1 H1
*/

    char *broken_key = NULL;
    int *broken_val = NULL;

    // King Pawn White
    char *e4_key = strdup("e4");
    int *e4_val = malloc(sizeof(int));
    *e4_val = 28;

    // Sicilian Black
    char *c5_key = strdup("c5");
    int *c5_val = malloc(sizeof(int));
    *c5_val = 34;

    // King Knight White
    char *f3_key = strdup("Nf3");
    int *f3_val = malloc(sizeof(int));
    *f3_val = 21;

    // Accelerated Dragon Black
    char *g6_key = strdup("g6");
    int *g6_val = malloc(sizeof(int));
    *g6_val = 46;

    // Queen Pawn White
    char *d4_key = strdup("d4");
    int *d4_val = malloc(sizeof(int));
    *d4_val = 27;

    // Pawn Trade Black
    char *cxd4_key = strdup("cxd4");
    int *cxd4_val = malloc(sizeof(int));
    *cxd4_val = 27;

    // Pawn Trade White
    char *nxd4_key = strdup("Nxd4");
    int *nxd4_val = malloc(sizeof(int));
    *nxd4_val = 27;

    dict_put_str_int(chess_board, e4_key, e4_val);
    dict_put_str_int(chess_board, c5_key, c5_val);
    dict_put_str_int(chess_board, f3_key, f3_val);
    dict_put_str_int(chess_board, g6_key, g6_val);
    dict_put_str_int(chess_board, d4_key, d4_val);
    dict_put_str_int(chess_board, broken_key, cxd4_val);
    dict_put_str_int(chess_board, cxd4_key, broken_val);
    dict_put_str_int(chess_board, cxd4_key, cxd4_val);
    dict_put_str_int(chess_board, nxd4_key, nxd4_val);

    dict_print_str_int(chess_board);

    printf("\n");
    printf("C5 %d\n", *dict_get_str_int(chess_board, c5_key));
    printf("Is Null? %d\n", dict_get_str_int(chess_board, broken_key) == NULL);
    printf("cxd4 %d\n", *dict_get_str_int(chess_board, cxd4_key));

    dict_destroy_str_int(chess_board);

    return 0;
}
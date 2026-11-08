#include<stdio.h>
#include<stdlib.h>

char board[3][3];
char currentplayer;

void initializeBoard(){
  int i, j;
  for(i = 0; i < 3; i++){
    for (j = 0; j < 3; j++){
        board[i][j] = ' ';
    }
  }
  currentplayer = 'X';
}
void printBoard(){
  printf("\n");
  printf(" 1 2 3\n");
  printf("1 %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
  printf("---+---+---\n");
  printf("2 %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
  printf("\n");
}

 char checkwinner(){
  int i;
  for (i = 0; i < 3; i++){
    if (board[i][0] == board[i][1] && board[i][1] == board[1][2] && board[i][0] != ' ')
        return board[i][0];
  }
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    return board[0][0];
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    return board[0][2];

  return ' ';
 }
 int isBoardFull(){
    int i, j;
    for(i = 0; i < 3; j++){
        if(board[i][j] == ' ') return 0;
    }
    return 1;
 }
 int main(){
     int row, col;
     char winner;
     int moves = 0;

     initializeBoard();

     printf("=== TIC TAC TOE ===");
     printf("Player 1 (X) - player 2 (0)\n");

     while(1){
        printBoard();
        printf("player %c, enter row and column(e.g, 1 2): ", currentplayer);

    if(scanf("%d %d, &row, &col") != 2 ){
        printf("Invalid input. Enter numbers only.\n");
        while(getchar() != '\n');
        continue;
    }
    row--;
    col--;

    if(row < 0 || row > 2 || col < 0 || col > 2){
        printf("Out of bounds! choose 1, 2, or 3.\n");
        continue;
    }
    if (board[row][col] != ' '){
        printf("That spot is arleady taken! Try again.\n");
        continue;
    }
    board[row][col] = currentplayer;
    moves++;
    winner = checkwinner();
    if(winner != ' '){
        printBoard();
        printf("player %c wins!\n", winner);
        break;
    }
    if(isBoardFull()){
        printBoard();
        printf("It's a TIE! nobody wins.\n");
        break;
    }
    if(currentplayer == 'X'){
        currentplayer = '0';
    }else{
        currentplayer = 'X';}
     }
     return 0;



 }

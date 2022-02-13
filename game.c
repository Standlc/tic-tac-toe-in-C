#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
const char PLAYER = 'X';
const char COMPUTER = 'O';
char winner = ' ';

void drawBoard()
{
    printf("\n");
    printf(" -----------\n");
    for (int i = 0; i < 3; i++)
    {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        if (i == 2)
            break;
        printf("|---|---|---|\n");
    }
    printf(" -----------\n");
    printf("\n");
}

void updateBoard(int selectedColumn, int selectedRow, char player)
{
    board[selectedRow][selectedColumn] = player;
}

void computerMove()
{
    srand(time(0));
    int selectedColumn;
    int selectedRow;
    do
    {
        selectedColumn = rand() % 3;
        selectedRow = rand() % 3;
    } while (board[selectedRow][selectedColumn] != ' ');

    updateBoard(selectedColumn, selectedRow, COMPUTER);
}

void playerMove()
{
    int selectedColumn;
    int selectedRow;
    do
    {
        printf("Select a column : ");
        scanf("%d", &selectedColumn);
        printf("Select a row : ");
        scanf("%d", &selectedRow);
        selectedColumn--;
        selectedRow--;
    } while (board[selectedRow][selectedColumn] != ' ');

    updateBoard(selectedColumn, selectedRow, PLAYER);
}

bool spaceLeft()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return true;
            }
        }
    }
    return false;
}

void checkingColumns()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            winner = board[i][0];
        }
    }
}
void checkingRows()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            winner = board[0][i];
        }
    }
}
void checkingDiagonals()
{
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        winner = board[0][0];
    }
    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        winner = board[0][2];
    }
}

void checkForWinner()
{
    checkingColumns();
    checkingRows();
    checkingDiagonals();
}

int main()
{
    // fgets(name, 20, stdin);
    // name[strlen(name) - 1] = '\0';
    // char cars[][10] = {"tesla", "toyota"};
    drawBoard();
    do
    {
        playerMove();
        drawBoard();
        checkForWinner();
        if (!spaceLeft() || winner != ' ')
        {
            break;
        }
        computerMove();
        drawBoard();
        checkForWinner();
        if (!spaceLeft() || winner != ' ')
        {
            break;
        }
    } while (true);

    if (!spaceLeft() && winner == ' ')
        printf("No more space left !\n");

    if (winner != ' ')
        printf("%c won !\n", winner);

    return 0;
}

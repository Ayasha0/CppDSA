#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

// -------------
// |   |   |   |
// -------------
// |   |   |   |
// -------------
// |   |   |   |
// -------------

void add(char a[3][3], char inp, char ch)
{
    int num = inp - 49, row, col;
    row = num / 3, col = num % 3;
    a[row][col] = ch;
}

// INITIAL LOOK OF disp()
//  -------------
//  | a | a | a |
//  -------------
//  | a | a | a |
//  -------------
//  | a | a | a |
//  -------------

void disp(char a[3][3])
{
    cout << "\n\t\tPress Esc anytime to quit the game\n\n\n\n";
    int i, j;
    for (i = 0; i < 3; i++)
    {
        cout << "\t\t\t\t-------------\n\t\t\t\t";
        for (j = 0; j < 3; j++)
        {
            if (a[i][j] == 'a')
                cout << "|   ";
            else
                cout << "| " << a[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "\t\t\t\t-------------\n";
}

// OPERATION OF CHECK()
//  suppose
//  char inp = 1
//  converting to ascii decimal number from 1 to 9
//  ascii value for 1 is 49

// int num = inp - 48
// int num = ascii(1) - 48
// int num = 49 - 48
// int num = 1 -> value is evaluated

// num-- = 0

// row = 0 / 3 = 0
// col = 0 % 3 = 0

// if(a[0][0] == 'a') then return 1
// since if cell contains 'a' that means no players have played that cell yet
// otherwise we will be returning 0

int check(char a[3][3], char inp)
{
    int num = inp - 48, row, col;
    if (num <= 0 || num >= 10)
        return 0;
    num--;
    row = num / 3;
    col = num % 3;
    if (a[row][col] == 'a')
        return 1;
    else
        return 0;
}

// checking for winner
char gameover(char a[3][3])
{
    char winner = 'a';
    if (a[0][0] == a[0][1] && a[0][0] == a[0][2] && a[0][0] != 'a')
        winner = a[0][0];
    if (a[1][0] == a[1][1] && a[1][0] == a[1][2] && a[1][0] != 'a')
        winner = a[1][0];
    if (a[2][0] == a[2][1] && a[2][0] == a[2][2] && a[2][0] != 'a')
        winner = a[2][0];
    if (a[0][0] == a[1][0] && a[0][0] == a[2][0] && a[0][0] != 'a')
        winner = a[0][0];
    if (a[0][1] == a[1][1] && a[0][1] == a[2][1] && a[0][1] != 'a')
        winner = a[0][1];
    if (a[0][2] == a[1][2] && a[0][2] == a[2][2] && a[0][2] != 'a')
        winner = a[0][2];
    if (a[0][0] == a[1][1] && a[0][0] == a[2][2] && a[0][0] != 'a')
        winner = a[0][0];
    if (a[0][2] == a[1][1] && a[0][2] == a[2][0] && a[0][2] != 'a')
        winner = a[0][2];
    return winner;
}

// checking for draw conditions
int draw(char a[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (a[i][j] == 'a')
                return 0;
    return 1;
}

int main()
{
    cout << "\n\n\n\n\t\t\tTic Tac Toe\n\n\n\t\tPress any key to continue";
    getch();
    char a[3][3], turn[2] = {'X', 'O'}, ch = 'X', inp, winner, res;
    do
    {
        a[0][0] = a[0][1] = a[0][2] = a[1][0] = a[1][1] = a[1][2] = a[2][0] = a[2][1] = a[2][2] = 'a';
        system("cls");
        disp(a);
        cout << "\n\n\t\t\t" << ch << "'s Turn\n\n";
        int count = 0;
        while (1)
        {
            inp = getch();
            system("cls");
            if (inp <= 48 || inp >= 58 || !check(a, inp))
            {
                disp(a);
                cout << "\n\n\t\t\t" << ch << "'s Turn\n\n";
                cout << "INVALID MOVE!!\n\n";
            }
            else
            {
                add(a, inp, ch);
                disp(a);
                winner = gameover(a);
                if (winner == 'a')
                {
                    if (draw(a))
                    {
                        cout << "\n\n\t\t\tMatch Drawn !!\n";
                        break;
                    }
                    ch = turn[(++count) % 2];
                    cout << "\n\n\t\t\t" << ch << "'s Turn\n\n";
                }
                else
                {
                    cout << "\n\n\t\t\t" << winner << " Won !!\n";
                    break;
                }
            }
        }
        getch();
        system("cls");
        cout << "\n\n\n\n\t\t\tWant to play more ? (Y/N) : ";
        cin >> res;
    } while (res == 'y' || res == 'Y');
}
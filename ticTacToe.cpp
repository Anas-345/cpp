#include <iostream>
using namespace std;

class Board
{
private:
    char board[3][3];

public:
    Board()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = '_';
            }
        }
    }

    void displayPosition() const
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 1; j < 4; j++)
            {
                cout << (i * 3) + j << "\t";
            }
            cout << endl;
        }
    }

    void displayBoard() const
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void updateBoard(char symbol, int cell)
    {
        board[row(cell)][col(cell)] = symbol;
    }

    bool isCellEmpty(int cell)
    {
        if (board[row(cell)][col(cell)] == '_')
        {
            return true;
        }
        return false;
    }

    int row(int cell) { return (cell - 1) / 3; }
    int col(int cell) { return (cell - 1) % 3; }

    bool checkWin()
    {
        for (int i = 0; i < 3; i++)
        {
            if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && board[i][0] != '_')
            {
                return true;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && board[0][i] != '_')
            {
                return true;
            }
        }
        if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[0][0] != '_')
        {
            return true;
        }
        if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && board[0][2] != '_')
        {
            return true;
        }
        return false;
    }
};

class Player
{
private:
    char symbol;

public:
    Player(char _symbol)
    {
        symbol = _symbol;
    }
    void makeMove(Board &obj)
    {
        int cell;
        do
        {
            cout << "Enter cell no. for your move(1-9): ";
            cin >> cell;
            if (!(obj.isCellEmpty(cell)))
            {
                cout << "Please select an empty cell" << endl;
                cell = -1;
            }

        } while (!(cell > 0 && cell < 10));

        obj.updateBoard(symbol, cell);
    }
};

class Game
{
    Board boardObj;
    Player PX, PO;
    int moveCount = 1;
    bool exit;

public:
    Game() : PX('X'), PO('O') {}
    void start()
    {
        cout << "Game positioning is in given order" << endl;
        boardObj.displayPosition();
        cout << "Game Begin" << endl;
        boardObj.displayBoard();
        do
        {
            switchTurn();
            boardObj.displayBoard();
            exit = boardObj.checkWin();
            if (exit)
            {
                cout << ((moveCount % 2) ? "Player X" : "Player O");
                cout << " won the game" << endl;
                return;
            }
            if (moveCount == 9)
            {
                cout << "Game Draw" << endl;
                exit = true;
            }

            moveCount++;
        } while (!exit);
    }

    void switchTurn()
    {
        if (moveCount % 2)
        {
            PX.makeMove(boardObj);
        }
        else
        {
            PO.makeMove(boardObj);
        }
    }
};

int main()
{
    Game gameObj;
    gameObj.start();
    return 0;
}
#include <iostream>

using namespace std;

class TicTaToe
{
public:
	TicTaToe(void);
	int HaveWinner(void);
	int Play(int x);
	void SetTurn(int player);
	char GetTurn();

private:
	int cell[3][3];
	void ShowBoard(void);
	int turn;
};

TicTaToe::TicTaToe(void)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cell[i][j] = 0;

	ShowBoard();
}

int TicTaToe::Play(int x)
{
	x--;
	if (x >= 0 && x <= 8 && (!cell[x / 3][x % 3]))
	{
		cell[x / 3][x % 3] = turn;
		turn == 1 ? turn = 2 : turn = 1;
		system("clear");
		ShowBoard();
		return 1;
	}

	system("clear");
	ShowBoard();
	return 0;
}
int TicTaToe::HaveWinner(void)
{
	for (int i = 0; i < 3; i++)
		if (cell[i][0] != 0 && cell[i][0] == cell[i][1] && cell[i][1] == cell[i][2])
			return cell[i][0];

	for (int i = 0; i < 3; i++)
		if (cell[0][i] != 0 && cell[0][i] == cell[1][i] && cell[2][i] == cell[1][i])
			return cell[0][i];

	if (cell[0][0] != 0 && cell[0][0] == cell[1][1] && cell[1][1] == cell[2][2])
		return cell[0][0];

	if (cell[0][2] != 0 && cell[0][2] == cell[1][1] && cell[2][0] == cell[1][1])
		return cell[1][1];

	int tie = -1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (cell[i][j] == 0)
				tie = 0;
	return tie;
}

void TicTaToe::SetTurn(int player)
{
	turn = player;
}

char TicTaToe::GetTurn()
{
	return (turn == 1 ? 'X' : 'O');
}

void TicTaToe::ShowBoard(void)
{
	cout << "\n\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "\t     |     |     \n\t";

		for (int j = 0; j < 3; j++)
		{
			if (cell[i][j] == 1)
				cout << "  X  ";
			else if (cell[i][j] == 2)
				cout << "  O  ";
			else
				cout << "  " << j + 1 + (i * 3) << "  ";
			if (j != 2)
				cout << "|";
		}

		if (i != 2)
			cout << "\n\t_____|_____|_____\n";
		else
			cout << "\n\t     |     |     \n";

	}
}

int main()
{
	TicTaToe board;
	int x;
	char starter;

	cout << "\n\n   Who starts (X/O) ? ";
	cin >> starter;
	board.SetTurn(((starter == 'X' || starter == 'x') ? 1 : 2));

	while (!board.HaveWinner())
	{
		cout << "\n     Player " << board.GetTurn() << " : ";
		cin >> x;
		if (!board.Play(x))
			cout << "\n   Illegal Move ! Try again player " << board.GetTurn() << "\n";
	}

	if (board.HaveWinner() > 0)
		cout << "\n\nWoww... the winner is " << (board.HaveWinner() == 1 ? "X" : "O") << "\n";
	else
		cout << "\n\nA tie ! \n";

	return 0;
}
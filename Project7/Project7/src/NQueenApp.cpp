#include "NQueenApp.h"
#include <stack>

NQueenApp::NQueenApp()
{

}
void NQueenApp::Clean()
{

}
void NQueenApp::Restart()
{

}
void NQueenApp::Run()
{
	std::system("cls");
	std::cout << "\n\t3> N-Queens Problem (backtracking)";
	std::cout << "\n\t" << std::string(96, 196);

	// ask the user for the first queen placement
	int size =  Input::inputInteger("\n\tEnter the number (1..100) of queens: ", 1, 100);
	int startColumn = Input::inputInteger("\n\tEnter the column (1.." + std::to_string(size) + ") to place the first queen: ", 1, size);
	m_Board.setQueen(1, startColumn);

	if (canSolve())
		m_Board.displayBoard();
	else
		std::cout << "\n\tNo solution to the board.\n";
	std::system("pause");
}

bool NQueenApp::canSolve()
{
	std::stack<NQueen> m_Moves;
	std::stack<int> column;
	bool success = false;
	m_Moves.push(m_Board);

	int startingColumn = 1;
	while (!success && !m_Moves.empty())
	{
		int startingRow = m_Moves.size() + 1;

		// reinitialize the temporary board
		NQueen temp = m_Moves.top();

		// invalid move
		if (!temp.setQueen(startingRow, startingColumn))
		{
			// pop the latest move
			m_Moves.pop();

			// try the previous move on a different column
			startingColumn++;
		}

		// valid move and board is solved
		else if (temp.setQueen(startingRow, startingColumn) && temp.isSolved())
		{
			// initialize the board with the solved board
			m_Board = temp;
			return true;
		}
		else if (temp.setQueen(startingRow, startingColumn) && !temp.isSolved())
		{
			// push the move onto the stack
			m_Moves.push(temp);

			// reinitialize the column back to the first column
			startingColumn = 1;
		}
	}
	return false;
}

void NQueenApp::HandleInput(char m_Input)
{

}

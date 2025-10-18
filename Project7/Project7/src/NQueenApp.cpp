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
	std::stack<int> columns;
	bool success = false;

	m_Moves.push(m_Board);
	columns.push(1);

	while (!success && !m_Moves.empty())
	{
		int row = m_Moves.size() + 1;
		int col = columns.top();
		NQueen temp = m_Moves.top();
		bool placed = temp.setQueen(row, col);

		// invalid move
		if (!placed)
		{
			// pop the latest move
			m_Moves.pop();
			columns.pop();

			while (!columns.empty())
			{
				int prevCol = columns.top();
				// pop the column that was just used
				columns.pop();

				if (prevCol + 1 <= m_Board.getSize())
				{
					// push the column that is one more than the last 
					columns.push(prevCol + 1);
					break;
				}
				else
				{
					// pop the move
					m_Moves.pop();
				}
			}

		}

		// valid move and board is solved
		else if (placed && temp.isSolved())
		{
			// initialize the board with the solved board
			m_Board = temp;
			success = true;
		}

		// valid move and solved
		else if (placed && !temp.isSolved())
		{
			// push the move onto the stack
			m_Moves.push(temp);
			columns.push(1);
		}
	}
	return success;
}

void NQueenApp::HandleInput(char m_Input)
{

}

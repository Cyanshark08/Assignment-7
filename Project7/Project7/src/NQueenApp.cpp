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
    m_Board = NQueen(size);
    m_Board.setQueen(1, startColumn);

    // board size 1
    if (size == 1)
    {
        std::cout << "\n\t" << size << "-Queen Solution";
        m_Board.displayBoard();
        std::cout << "\n";
    }
    // solve the board
    else if (canSolve())
    {
        std::cout << "\n\t" << size << "-Queen Solution";
        m_Board.displayBoard();
        std::cout << "\n";
    }
    // no solution
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
        
        // columns exceed board size
        if (col > m_Board.getSize())
        {
            m_Moves.pop();
            columns.pop();
            if (!columns.empty())
            {
                // move to next column in previous row
                int prevCol = columns.top() + 1;
                columns.pop();
                columns.push(prevCol);
            }
            continue;
        }

        NQueen temp = m_Moves.top();
        if (temp.setQueen(row, col))
        {
            // reinitialize board to the solved board if all moves are made
            if (row == m_Board.getSize())
            {
                m_Board = temp;
                success = true;
            }

            // push the move onto the stack
            m_Moves.push(temp);
            columns.push(1);
        }
        else
        {
            // try next column in the same row
            columns.pop();
            columns.push(col + 1);
        }
    }
    return success;
}

void NQueenApp::HandleInput(char m_Input)
{

}

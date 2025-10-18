#include "NQueen.h"
#include <sstream>
#include <iomanip>

NQueen::NQueen()
{
	m_BoardSize = 4;
	m_Board.resize(m_BoardSize);

	for (size_t i = 0; i < m_BoardSize; i++)
	{
		m_Board[i].resize(m_BoardSize, false);
	}
}

NQueen::NQueen(size_t newSize)
{
    m_BoardSize = newSize;
    m_Board.resize(m_BoardSize);

    for (size_t i = 0; i < m_BoardSize; i++)
    {
        m_Board[i].resize(m_BoardSize, false);
    }
}

NQueen::NQueen(const NQueen &obj)
{
    this->m_BoardSize = obj.m_BoardSize;
    this->m_Board = obj.m_Board;
}

bool NQueen::setQueen(size_t row, size_t column)
{
	int r = row - 1;
	int c = column - 1;

	// columns
	for (int i = 0; i < r; i++)
	{
		if (m_Board[i][c] == true)
			return false;
	}
	
	// left diagonal
	for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (m_Board[i][j] == true)
			return false;
	}

	// right diagonal
	for (int i = r - 1, j = c + 1; i >= 0 && j < m_BoardSize; i--, j++)
	{
		if (m_Board[i][j] == true)
			return false;
	}

	// set the queen if the space is available
	m_Board[r][c] = true;
	return true;
}

void NQueen::removeQueen(size_t row, size_t column)
{
    m_Board[row - 1][column - 1] = false;
}

bool NQueen::isSolved() const
{
    // Check rows
    for (size_t i = 0; i < m_BoardSize; i++)
    {
        int queenCount = 0;
        for (size_t j = 0; j < m_BoardSize; j++)
        {
            if (m_Board[i][j] == true) 
                queenCount++;
        }
        if (queenCount > 1) 
            return false;
    }

    // Check columns
    for (size_t j = 0; j < m_BoardSize; j++)
    {
        int queenCount = 0;
        for (size_t i = 0; i < m_BoardSize; i++)
        {
            if (m_Board[i][j] == true) 
                queenCount++;
        }
        if (queenCount > 1) 
            return false;
    }

    // Check diagonals
    for (size_t i = 0; i < m_BoardSize; i++)
    {
        for (size_t j = 0; j < m_BoardSize; j++)
        {
            if (m_Board[i][j] == true)
            {
                // check upper left diagonal
                for (size_t k = 1; i >= k && j >= k; k++)
                {
                    if (m_Board[i - k][j - k] == true) 
                        return false;
                }

                // check upper right diagonal
                for (size_t k = 1; i >= k && j + k < m_BoardSize; k++)
                {
                    if (m_Board[i - k][j + k] == true) 
                        return false;
                }

                // check lower left diagonal
                for (size_t k = 1; i + k < m_BoardSize && j >= k; k++)
                {
                    if (m_Board[i + k][j - k] == true) 
                        return false;
                }

                // check lower right diagonal
                for (size_t k = 1; i + k < m_BoardSize && j + k < m_BoardSize; k++)
                {
                    if (m_Board[i + k][j + k] == true) 
                        return false;
                }
            }
        }
    }

    return true;
}

void NQueen::displayBoard() const
{
    std::stringstream ss;
    size_t rowWidth = m_BoardSize * 2 + 1;

    ss << "\n\n\t" << std::string(1, 201) << std::string(rowWidth - 2, 205) << std::string(1, 187);

    size_t rowIter{ 0 }, columnIter{ 0 };

    for (size_t i = 1; i < m_BoardSize * 2; i++)
    {
        ss << "\n\t" << std::string(1, 186);
        for (size_t j = 1; j < m_BoardSize * 2; j++)
        {
            if (i % 2)
            {
                if (j % 2)
                {
                    ss << (m_Board[rowIter][columnIter] ? 'Q' : ' ');
                    columnIter++;
                }
                else
                    ss << std::string(1, 179);

            }
            else
            {
                if (j % 2)
                    ss << '_';
                else
                    ss << std::string(1, 179);
            }

        }


        columnIter = 0;

        if (i % 2)
            rowIter++;

        ss << std::string(1, 186);
    }

    ss << "\n\t" << std::string(1, 200) << std::string(rowWidth - 2, 205) << std::string(1, 188);

    printf("%s", ss.str().c_str());
}
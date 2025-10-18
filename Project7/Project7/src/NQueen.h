#pragma once
#include <vector>


class NQueen
{
public:
	NQueen();
	NQueen(size_t newSize);
	NQueen(const NQueen &obj);

	bool setQueen(size_t row, size_t column);
	void removeQueen(size_t row, size_t column);
	bool isSolved() const;
	void displayBoard() const;

private:
	std::vector<std::vector<bool>> m_Board;
	size_t m_BoardSize;
};


#pragma once
#include <vector>


class NQueen
{
public:

	/*
	* PreCondition: N/A
	* PostCondition: Initialize private members to default values
	*/
	NQueen();

	/*
	* PreCondition: newSize must be a positive integer
	* PostCondition: Initialize size to newSize
	*/
	NQueen(size_t newSize);

	/*
	* PreCondition: NQueen object is passed
	* PostCondition: copy the private members of the passed argument to the current object
	*/
	NQueen(const NQueen &obj);

	/*
	* PreCondition: row and column must be valid indices within the 2D vector
	* PostCondition: places the queen at the given row and column of the vector
	*/
	bool setQueen(size_t row, size_t column);

	/*
	* PreCondition: row and column must be valid indices within the 2D vector
	* PostCondition: removes the queen at the given row and column of the vector
	*/
	void removeQueen(size_t row, size_t column);

	/*
	* PreCondition: N/A
	* PostCondition: returns a boolean statement regarding the status of the board
	* Returns true if the board is solved, otherwise return false
	*/
	bool isSolved() const;

	/*
	* PreCondition: N/A
	* PostCondition: displays the board
	*/
	void displayBoard() const;

	/*
	* PreCondition: N/A
	* PostCondition: returns the size of the board
	*/
	size_t getSize() const;

private:
	std::vector<std::vector<bool>> m_Board;
	size_t m_BoardSize;
};


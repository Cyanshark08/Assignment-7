#pragma once
#include "SubApp.h"
#include "NQueen.h";
#include "Input.h"
#include <iostream>


class NQueenApp : public SubApp
{
public:
	NQueenApp();
	void Clean() override;
	void Restart() override;
	void Run() override;
	bool canSolve();

private:
	void HandleInput(char m_Input) override;
private:
	NQueen m_Board;
};


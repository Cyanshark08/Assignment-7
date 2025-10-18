#pragma once
#include "SubApp.h"
#include "CalculationManager.h"

class SimpleCalculatorApp : public SubApp
{
public:
	SimpleCalculatorApp();

	void Run() override;

	void Restart() override;

	void Clean() override;

private:
	void HandleInput(char p_Input) override;

private:
	CalculationManager m_CalcManager;

};


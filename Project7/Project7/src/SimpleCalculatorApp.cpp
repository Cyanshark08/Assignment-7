#include "SimpleCalculatorApp.h"
#include "Input.h"

SimpleCalculatorApp::SimpleCalculatorApp()
	: SubApp(EAppID::SimpleCalculatorApp),
	m_CalcManager()
{}

void SimpleCalculatorApp::Run()
{
	std::system("cls");

	puts("\n\t1 > Simple Calculator");
	printf("\n%s", std::string(110, 205).c_str());

	std::string expression = Input::inputString("\n\tType a fully parenthesized arithmetic expression : ", true);

	try
	{
		float result = m_CalcManager.Evaluate(expression);
		printf("\n\t%s = %.3f", expression.c_str(), result);
	}
	catch(const ExceptionInterface& e)
	{
		puts(e.Message().c_str());
	}

	puts("");

	std::system("pause");
}

void SimpleCalculatorApp::Restart()
{}

void SimpleCalculatorApp::Clean()
{
	m_CalcManager.Clean();
}

void SimpleCalculatorApp::HandleInput(char p_Input)
{}

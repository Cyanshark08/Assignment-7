#include "Translator.h"
#include "Input.h"

Translator::Translator()
	: SubApp(EAppID::ArithmeticApp),
	m_CalcManager()
{}

void Translator::Run()
{
	std::system("cls");

	puts("\n\t2 > Translator");
	printf("\n%s", std::string(110, 205).c_str());

	std::string expression = Input::inputString("\n\tType an infix expression : ", true);

	try
	{
		m_CalcManager.TranslateToPostfix(expression);
	}
	catch (const ExceptionInterface& e)
	{
		puts(e.Message().c_str());
	}

	puts("");

	std::system("pause");
}

void Translator::Restart()
{
}

void Translator::Clean()
{
}

void Translator::HandleInput(char p_Input)
{
}

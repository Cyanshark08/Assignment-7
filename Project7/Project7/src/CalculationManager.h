#pragma once
#include <string>
#include <memory>
#include <stack>

enum class CharacterType
{
	Digit,
	Operator,
	Decimal,
	LParenthesis,
	RParenthesis
};

class CalculationManager
{
	CalculationManager() = default;

	float Evaluate(std::shared_ptr<std::string> p_Expression);

private:
	float StackEvaluate();
	CharacterType IsValid(char p_Character) const;

private:
	std::shared_ptr<std::string> m_CurrentExpression;
	std::stack<float> m_FloatStack;
	std::stack<char> m_OperationStack;

};


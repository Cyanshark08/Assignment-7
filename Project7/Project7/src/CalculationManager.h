#pragma once
#include <string>
#include <memory>
#include <stack>

#include "ExceptionInterface.h"

enum class ECharacterType
{
	Invalid = -1,
	Digit,
	Operator,
	LParenthesis,
	RParenthesis
};

class CalculationManager
{
public:
	CalculationManager() = default;

	float Evaluate(const std::string& p_Expression);

	void TranslateToPostfix(const std::string& p_Expression);

	void Clean();

public:
	class E_ImbalancedParentheses : public ExceptionInterface
	{
	public:
		E_ImbalancedParentheses();

	private:
		std::string GetExceptionName() const override;
		std::string GetExceptionMessage() const override;
	};

	class E_InvalidExpression : public ExceptionInterface
	{
	public:
		E_InvalidExpression();

	private:
		std::string GetExceptionName() const override;
		std::string GetExceptionMessage() const override;
	};

private:
	float StackEvaluate();
	bool IsValid();
	bool IsBalanced();
	bool IsOperator(char p_Character) const;
	void evalTop(std::stack<float>& p_Numbers, std::stack<char>& p_Operators) const;
	bool HasLowerPrecedence(char p_First, char p_Other);

private:
	std::string m_CurrentExpression;

};


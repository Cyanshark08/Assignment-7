#include "CalculationManager.h"
#include <sstream>
#include <algorithm>

float CalculationManager::Evaluate(const std::string& p_Expression)
{
    m_CurrentExpression = p_Expression;

    if (!IsValid())
        throw E_InvalidExpression();
        
    if (!IsBalanced())
        throw E_ImbalancedParentheses();

    return StackEvaluate();
}

void CalculationManager::Clean()
{
    m_CurrentExpression.clear();
}

float CalculationManager::StackEvaluate()
{
    std::istringstream ins(m_CurrentExpression);

    std::stack<float> numbers;
    std::stack<char> operations;
    float number;
    char symbol;
        
    while (ins && ins.peek() != '\n')
    {
        if (isdigit(ins.peek()) || (ins.peek() == '.'))
        {
            ins >> number;
            numbers.push(number);
        }
        else if (strchr("+-*/^", ins.peek()) != NULL)
        {
            ins >> symbol;
            operations.push(symbol);
        }
        else if (ins.peek() == ')')
        {
            ins.ignore();
            evalTop(numbers, operations);
        }
        else
            ins.ignore();
    }
    return numbers.top();
}

bool CalculationManager::IsValid()
{
    if (m_CurrentExpression.empty())
        return false;
    for (size_t i = 0; i < m_CurrentExpression.length(); i++)
    {
        char character = m_CurrentExpression[i];
        if (!std::isdigit(character) && !IsOperator(character) &&
            character != '.' && character != '(' && character != ')')
            return false;
    }

    return true;
}

bool CalculationManager::IsBalanced()
{
    std::stack<signed char> parenthesesStack;
    for (auto character : m_CurrentExpression)
    {
        if (character == '(')
            parenthesesStack.push(0);

        if (character == ')')
        {
            if (parenthesesStack.empty())
                return false;
            parenthesesStack.pop();
        }
    }

    if (!parenthesesStack.empty())
        return false;

    if (m_CurrentExpression[m_CurrentExpression.length() - 1] != ')' || m_CurrentExpression[0] != '(')
        return false;

    return true;
}

bool CalculationManager::IsOperator(char p_Character)
{
    return p_Character == '*' || p_Character == '+' || p_Character == '/' || p_Character == '-';
}

void CalculationManager::evalTop(std::stack<float>& p_Numbers, std::stack<char>& p_Operators)
{
    double operand1, operand2;

    if (p_Numbers.empty())
        throw E_InvalidExpression();
    operand2 = p_Numbers.top();
    p_Numbers.pop();

    if (p_Numbers.empty())
        throw E_InvalidExpression();
    operand1 = p_Numbers.top();
    p_Numbers.pop();

    if (p_Operators.empty())
        throw E_InvalidExpression();
    switch (p_Operators.top())
    {
    case '+': 
        p_Numbers.push(operand1 + operand2);
        break;
    case '-': 
        p_Numbers.push(operand1 - operand2);
        break;
    case '*': 
        p_Numbers.push(operand1 * operand2);
        break;
    case '/': 
        p_Numbers.push(operand1 / operand2);
        break;
    case '^':
        p_Numbers.push((float)std::pow(operand1, operand2));
        break;
    }
    p_Operators.pop();
}

CalculationManager::E_ImbalancedParentheses::E_ImbalancedParentheses()
{}

std::string CalculationManager::E_ImbalancedParentheses::GetExceptionName() const
{
    return "Imbalanced Parentheses";
}

std::string CalculationManager::E_ImbalancedParentheses::GetExceptionMessage() const
{
    return "Paarentheses are Imbalanced";
}

CalculationManager::E_InvalidExpression::E_InvalidExpression()
{}

std::string CalculationManager::E_InvalidExpression::GetExceptionName() const
{
    return "Invalid Expression";
}

std::string CalculationManager::E_InvalidExpression::GetExceptionMessage() const
{
    return "This is an Invalid Arithmetic Expression";
}

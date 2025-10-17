#include "CalculationManager.h"
#include <algorithm>

float CalculationManager::Evaluate(std::shared_ptr<std::string> p_Expression)
{
    m_CurrentExpression = p_Expression;
    return StackEvaluate();
}

float CalculationManager::StackEvaluate()
{
    std::remove_if(m_CurrentExpression->begin(), m_CurrentExpression->end(),
        [](char p_Character) -> bool
        {
            return std::isspace(p_Character);
        });

    std::string currentString = "";
    for (size_t i = 0; i < m_CurrentExpression->length(); i++)
    {
        (*m_CurrentExpression)[i];
    }
}

CharacterType CalculationManager::IsValid(char p_Character) const
{
    return std::isdigit(p_Character) || ;
}

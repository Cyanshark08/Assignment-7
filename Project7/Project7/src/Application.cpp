#include "Application.h"
#include <string>
#include "SimpleCalculatorApp.h"
#include "Translator.h"
#include "NQueenApp.h"
#include "Input.h"

Application::Application()
    : m_State(MainAppState::MainApp),
    m_CurrentSubApp(EAppID::InvalidApp)
{
}

void Application::Run()
{
    while (m_State != MainAppState::Exited)
    {
        switch (m_State)
        {
        case MainAppState::MainApp:
            DisplayMainMenu();
            QueryState();
            break;
        case MainAppState::SubApp:
            switch (m_CurrentSubApp)
            {
            case EAppID::SimpleCalculatorApp:
            {
                SimpleCalculatorApp app;
                app.Run();
            }
                break;
            case EAppID::ArithmeticApp:
            {
                Translator app;
                app.Run();
            }
                break;
            case EAppID::NQueensApp:
            {
                NQueenApp app;
                app.Run();
            }
                break;
            case EAppID::InvalidApp:
            default:
                std::cout << "\n\tERROR: Invalid application selected";
                std::cout << "\n";
                std::system("pause");
                break;
            }

            m_State = MainAppState::MainApp;
            m_CurrentSubApp = EAppID::InvalidApp;
            break;
        }
    }
}

void Application::Clean()
{
    // Cleanup if needed
    std::cout << "\n\tApplication cleanup completed.";
}

void Application::DisplayMainMenu()
{
    std::system("cls");
    puts("\n\tCMPR131 Chapter 7: Applications using Stacks by Landon, Andrew, & Jaime (10 / 17 / 25)");
    puts(std::string(110, 205).c_str());
    puts("\t1 > Simple Calculator(problem 9, pg 391)");
    puts("\t2 > Translation of arithmetic expression(problem 10, pg 391)");
    puts("\t3 > n - Queens Problem(problem 11, pg 391 - 292)");
    puts(std::string(110, 196).c_str());
    puts("\t0. Exit");
    puts(std::string(110, 205).c_str());
}

void Application::QueryState()
{
    char choice = Input::inputChar("\n\tOption: ", "123450");
    switch (choice)
    {
    case '1':
        m_State = MainAppState::SubApp;
        m_CurrentSubApp = EAppID::SimpleCalculatorApp;
        break;
    case '2':
        m_State = MainAppState::SubApp;
        m_CurrentSubApp = EAppID::ArithmeticApp;
        break;
    case '3':
        m_State = MainAppState::SubApp;
        m_CurrentSubApp = EAppID::NQueensApp;
        break;
    case '0':
        m_State = MainAppState::Exited;
        break;
    }
}
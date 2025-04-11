/**
 * @file menu.hpp
 * @author Pedro Daguer
 * @brief A C++ console menu.
 * @version 1.0.0
 * @date 2025-04-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
#include "utils.hpp"
#include <vector>
#include <memory>
#include <windows.h>
#include <functional>

typedef std::function<void()> MenuCallBack;

class Option
{
public:
    std::string title;
    MenuCallBack executor;
    Option(std::string t, MenuCallBack c) : title(t), executor(c) {}
};

class Menu
{
private:
    std::vector<std::shared_ptr<Option>> options;
    bool run;

    void readI(std::string message, int *iptr)
    {
        int r = 0;
        do
        {
            printf_s(message.c_str());
            r = scanf_s("%i", iptr);
            fflush(stdin);
        } while (r <= 0);
    }

    std::string title;

    
    public:

    /// @brief Create a Menu with a title to print.
    /// @param title 
    /// @param exitMessage Title for the exit option.
    Menu(std::string title, std::string exitMessage = "Exit") : title(title) {
        addOption(exitMessage, [this](){
            exit();
        });
    }
    
    /// @brief Add a option to the menu, all registered options will be listed to the user
    /// @param title Option's title
    /// @param callback Function to execute when user select this option.
    void addOption(const std::string &title, MenuCallBack callback)
    {
        options.push_back(std::make_shared<Option>(title, callback));
    }
    
    /// @brief Show the menu, will "freeze" the thread until user selects "exit".
    /// @brief Changes the console page to UTF8
    void show()
    {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
        
        run = true;
        do
        {
            system("cls");
            
            printf(" [ %s ]\n\n", title.c_str());
            
            int k = 0;
            for (auto &o : options)
            {
                printf(" %01i) %s\n", k, o->title.c_str());
                k++;
            }
            printf("\n");
            
            int escolha = 0;
            do
            {
                readI("> ", &escolha);
            } while(escolha < 0 || escolha > k - 1);
            
            if(options[escolha]->executor != nullptr)
                options[escolha]->executor();

            if(run)
                system("pause");
                
        } while (run);
    }

    /// @brief Close the menu
    void exit()
    {
        run = false;
    }
};

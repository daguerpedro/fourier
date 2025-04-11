#pragma once
#define _USE_MATH_DEFINES
#include "ifourier.h"
#include <tgmath.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <format>

class Utils
{
public:
    /// @brief Prints a 'message' to the user, returning the user input as a float
    /// @param message 
    /// @return User input float
    float readF(std::string message)
    {
        int r = 0;
        float fr;
        do
        {
            printf_s(message.c_str());
            r = scanf_s("%f", &fr);
            fflush(stdin);
        } while (r <= 0);
        return fr;
    }
};
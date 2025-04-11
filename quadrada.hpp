#pragma once
#include "utils.hpp"
#include <format>
#include <cmath>

class Quadrada : public IFourier
{
public:
    Quadrada(float vp, float T, float w0, float offset) : IFourier(vp, T, w0, offset) {}

    void calc() override
    {
        std::string equacao = std::format("v(t) = {:.5f}", offset);
       
        float A = 4 * vp / M_PI;

        float primeiraHarmonica = 0;
        float diferenca = 0;
        int i = 1;

        do
        {
            float n = (2 * i - 1); // só ímpares
            float coeficiente = A / n;
            float seno = n * w0;

            if (i == 1)
            {
                primeiraHarmonica = coeficiente;
            }

            equacao += std::format(" + {:.5f}*sin({:.5f}*t)", coeficiente, seno);

            diferenca = std::abs((primeiraHarmonica - coeficiente) / primeiraHarmonica * 100);

            i++;
        } while (100 - diferenca > 5); 

        printf("%s\n", equacao.c_str());
    }
};

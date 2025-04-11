#pragma once
#include "utils.hpp"

class Triangular : public IFourier
{
public:
    Triangular(float vp, float T, float w0, float offset) : IFourier(vp, T, w0, offset) {}
    void calc() override 
    {
        float CC = vp/2;
        std::string equacao = std::format("v(t) = {:.5f}", CC + offset);
       
        float A = 4 * vp / pow(M_PI, 2);

        float primeiraHarmonica = 0;
        float diferenca = 0;
        int i = 1;

        do
        {
            float n = (2 * i - 1); // só ímpares
            float coeficiente = A / pow(n, 2);
            float seno = n * w0;

            if (i == 1)
            {
                primeiraHarmonica = coeficiente;
            }

            equacao += std::format(" - {:.5f}*cos({:.5f}*t)", coeficiente, seno);

            diferenca = std::abs((primeiraHarmonica - coeficiente) / primeiraHarmonica * 100);

            i++;
        } while (100 - diferenca > 1); 

        printf("%s\n", equacao.c_str());
    }
};

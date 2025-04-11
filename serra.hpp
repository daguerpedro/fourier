#pragma once
#include "utils.hpp"
#include <format>
#include <cmath>

class Serra : public IFourier
{
public:
    Serra(float vp, float T, float w0, float offset) : IFourier(vp, T, w0, offset) {}

    void calc() override
    {
        float CC = (vp/2);
        std::string equacao = std::format("v(t) = {:.5f}", CC + offset);

        float primeiraHarmonica = 0;
        float diferenca = 0;
        int i = 1;

        do
        {
            float n = i;
            float coeficiente = (vp/M_PI)/n;
            float seno = i * w0;

            if (i == 1)
            {
                primeiraHarmonica = std::abs(coeficiente);
            }

            equacao += std::format(" - {:.5f}*sin({:.5f}*t)", coeficiente, seno);

            diferenca = std::abs((primeiraHarmonica - coeficiente) / primeiraHarmonica * 100);

            i++;
        } while (100 - diferenca > 5); // para até que a harmônica atual contribua <5%

        printf("%s\n", equacao.c_str());
    }
};

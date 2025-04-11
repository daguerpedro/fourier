#include "utils.hpp"
#include "quadrada.hpp"
#include "serra.hpp"
#include "triangular.hpp"
#include "menu.hpp"

int main()
{
    Menu menu = Menu("Gerador de funções | Séries de Fourier\n  https://files.passeidireto.com/1f11267d-944c-41f2-9c11-715b3380a424/1f11267d-944c-41f2-9c11-715b3380a424.jpeg");
    Utils utils;

    menu.addOption("Quadrada", [&utils](){
        float vp = utils.readF("Vp: ");
        float T = utils.readF("T: ");
        float w0 = 2*M_PI/T;
        float offset = utils.readF("V offset: ");
        
        Quadrada q = Quadrada(vp, T, w0, offset);
        q.calc();
    });

    menu.addOption("Serra", [&utils](){
        float vp = utils.readF("Vp: ");
        float T = utils.readF("T: ");
        float w0 = 2*M_PI/T;
        float offset = utils.readF("V offset: ");

        Serra q = Serra(vp, T, w0, offset);
        q.calc();
    });

    menu.addOption("Triangular", [&utils](){
        float vp = utils.readF("Vp: ");
        float T = utils.readF("T: ");
        float w0 = 2*M_PI/T;
        float offset = utils.readF("V offset: ");

        Triangular q = Triangular(vp, T, w0, offset);
        q.calc();
    });
    
    menu.show();
    return 0;
}

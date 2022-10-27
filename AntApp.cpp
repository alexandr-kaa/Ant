#include <iostream>
#include "AntManager.h"

int main()
{
    AntJourney::AntManager manager({1000,1000});
    manager.Run();
    std::cout << "Total size = "<<manager.GetSize()<<std::endl;
}

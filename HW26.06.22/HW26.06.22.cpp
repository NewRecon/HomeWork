#include <iostream>
#include "Engineer.cpp"
#include "EngineerInfo.cpp"
#include "Programmer.cpp"
#include "ProgrammerInfo.cpp"
#include "Builder.cpp"
#include "BuilderProgrammer.cpp"
#include "BuilderEngineer.cpp"
#include "BuilderProgrammerInfo.cpp"
#include "BuilderEngineerInfo.cpp"
#include "Director.cpp"

int main()
{
    BuilderProgrammer* bp = new BuilderProgrammer;
    BuilderProgrammerInfo* bpi = new BuilderProgrammerInfo;
    BuilderEngineer* be = new BuilderEngineer;
    BuilderEngineerInfo* bei = new BuilderEngineerInfo;
    Director* dir = new Director;
    dir->create(bp, "Karl", "123456789", "23b");
    dir->create(bpi, "Karl", "123456789", "23b");
    dir->create(be, "Oliver", "987654321", "12a");
    dir->create(bei, "Oliver", "987654321", "12a");
    Programmer* prog1 = bp->get();
    ProgrammerInfo* progInfo1 = bpi->get();
    Engineer* eng1 = be->get();
    EngineerInfo* engInfo1 = bei->get();

    prog1->print();
    progInfo1->print();
    eng1->print();
    engInfo1->print();
}
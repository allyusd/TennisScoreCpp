#include "hardwarerepository.h"
#include "src\tennisgame.h"


int main(int argc, char* argv)
{
    HardWareRepository repo;
    TennisGame game(static_cast<IRepository*>(&repo));
    game.score_result(0);
}
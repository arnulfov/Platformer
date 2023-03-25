//Arnulfo Villicana
//Cop 3003 Second Deployment
//In-progress platformer game

#include "Game.h"

int main() {
   Game Game;

   while(Game.GetWindow().isOpen()){
    Game.Update();
    Game.Render();
   }

    return 0;
}

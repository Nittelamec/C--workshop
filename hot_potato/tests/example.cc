#include "../game.hh"

int main()
{
    auto game = Game();

    game.add_player("Vinh", 2);
    game.add_player("Harrys", 1);
    game.add_player("Alim", 0); // Cheater
    game.add_player("Jules", 1);
    game.add_player("Anais", 2);
    game.add_player("Baptiste", 1);
    game.add_player("Ghislain", 5); // Likes risks
    game.add_player("Maxime", 1);
    game.add_player("Dorian", 3);
    game.add_player("Martin", 3);
    game.add_player("Dylan", 2);

    game.play(9);
}

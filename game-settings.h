#include "game.h"
//-----------------------------each mosnter's moves
// Move(std::string name, std::string type, int cost, int damage);

//--------Flamo--------------//
Move ember("Ember", "Fire", 2, 15);
 Move flameBurst("Flame Burst", "Fire", 3, 20);
 Move fireSpin("Fire Spin", "Fire", 4, 25);
 Move blazeKick("Blaze Kick", "Fire", 5, 30);

//----------Aquaril---------//
Move waterGun("Water Gun", "Water", 2, 15);
 Move aquaJet("Aqua Jet", "Water", 3, 20);
 Move bubbleBeam("Bubble Beam", "Water", 4, 25);
 Move hydroPump("Hydro Pump", "Water", 5, 30);

//----------Terraplant--------//
 Move vineWhip("Vine Whip", "Grass", 2, 15);
 Move leafBlade("Leaf Blade", "Grass", 3, 20);
 Move razorLeaf("Razor Leaf", "Grass", 4, 25);
 Move solarBeam("Solar Beam", "Grass", 5, 30);

//-------------Zappy------------//
 Move thunderShock("Thunder Shock", "Electric", 2, 15);
 Move spark("Spark", "Electric", 3, 20);
 Move electroBall("Electro Ball", "Electric", 4, 25);
 Move thunder("Thunder", "Electric", 5, 30);

//------------Rocky-----------------//
 Move rockThrow("Rock Throw", "Rock", 2, 15);
 Move rockSlide("Rock Slide", "Rock", 3, 20);
 Move stoneEdge("Stone Edge", "Rock", 4, 25);
 Move earthquake("Earthquake", "Rock", 5, 30);

//----------Mysty-----------------//
 Move magicMissile("Magic Missile", "Psychic", 2, 15);
 Move psychic("Psychic", "Psychic", 3, 20);
 Move futureSight("Future Sight", "Psychic", 4, 25);
 Move mysticForce("Mystic Force", "Psychic", 5, 30);





std::vector<std::string> FlamoArt = {
    "    \\ ^ ^ /",
    "   (  >w<  )",
    "    \\_^^_/"
};


std::vector<std::string> AquarilArt = {
    "    .-'''-.",
    "   ( o_o )",
    "   /  ~  \\",
    "  (______)"
};


std::vector<std::string> TerraplantArt = {
    "    ( ^w^ )",
    "   (  ___  )",
    "    \\ |_| /",
    "     / | \\"
};


std::vector<std::string> ZappyArt = {
    "    .--.",
    "   ( >_< )",
    "    /VV\\",
    "   /____\\"
};


std::vector<std::string> RockyArt = {
    "   _______",
    "  /  o o  \\",
    " |   ___   |",
    "  \\_______/"
};

std::vector<std::string> MystyArt = {
    "    ( ~.~ )",
    "   --(~~~~)--",
    "     /   \\"
};


 

 //------------- Create monster and assign moves & arts
 Monster Flamo("Flamo", "Fire", 100, { flameBurst, fireSpin, ember, blazeKick } , FlamoArt);
 Monster Aquaril("Aquaril", "Water", 100, { aquaJet, waterGun, bubbleBeam, hydroPump }, AquarilArt );
 Monster Terraplant("Terraplant", "Grass", 100, { vineWhip, leafBlade, razorLeaf, solarBeam },  TerraplantArt);
 Monster Zappy("Zappy", "Electric", 100, { thunderShock, spark, electroBall, thunder }, ZappyArt);
 Monster Rocky("Rocky", "Rock", 100, { rockThrow, rockSlide, stoneEdge, earthquake }, RockyArt);
 Monster Mysty("Mysty", "Psychic", 100, { magicMissile, psychic, futureSight, mysticForce }, MystyArt);

 std::vector<Monster> allMonsters = { Flamo, Aquaril, Terraplant, Zappy, Rocky, Mysty };





 
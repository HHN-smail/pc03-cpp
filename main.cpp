#include <./0_headers/organisms_headers/organism.h>
#include "./universe_headers/universe.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

int main()
{
    universe::Universe *my_world = new universe::Universe(5000, 1000);
    Insect *my_organism = new Insect(my_world, 0, 0);
    my_organism->hunt();
}
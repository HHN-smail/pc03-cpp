#pragma once
// #if !defined(alpha)
#include "../universe_headers/universe.h"

// #endif // alpha

class Organism
{
private:
    static universe::Universe *Universe;
    // pointer to the Universe class instance

    int x;
    int y;
    int energy;

public:
    Organism(universe::Universe *Universe, int x, int y);
    int get_x();
    int get_y();
    void move(int final_x, int final_y);
    void route(int final_x, int final_y);
    void hunt(int iterations = 1);
    ~Organism();
};

class Plant : public Organism
{
private:
public:
    Plant(universe::Universe *uni, int x, int y) : Organism(uni, x, y){};

    ~Plant();
};

class Insect : public Organism
{
private:
public:
    Insect(universe::Universe *Universe, int x, int y);

    ~Insect();
};

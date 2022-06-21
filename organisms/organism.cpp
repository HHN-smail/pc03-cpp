#include <iostream>
#include <stdexcept>
#include "../0_headers/universe_headers/universe.h"
#pragma once
// #include "../universe/universe.h"
class Organism
{
private:
    static universe::Universe *Universe;
    // pointer to the Universe class instance
    char name;
    int x;
    int y;
    int energy;

public:
    Organism(universe::Universe *Universe, int x, int y);
    int get_x();
    int get_y();
    char get_name() { return name; }
    void hunt(int iterations = 1);
    void move(int final_x, int final_y);
    void route(int final_x, int final_y);

    ~Organism(){};
};

Organism::Organism(universe::Universe *Universe, int x, int y)
{
    this->Universe = Universe;
    this->x = x;
    this->y = y;
    this->energy = 1000;
    Universe->update_universe(x, y, this);
}

Organism::~Organism()
{
    std::cout << "Organism destructor" << std::endl;
}

void Organism::move(int final_x, int final_y)
{
    if (energy <= 0)
    {
        std::cout << "Organism is dead" << std::endl;
        Organism::~Organism();
        return;
    }
    if (abs(final_x - x) + abs(final_y - y) == 1)
    {
        Universe->update_universe(x, y, NULL);
        Universe->update_universe(final_x, final_y, this);
        x = final_x;
        y = final_y;
        energy--;
    }
    else
    {
        throw std::invalid_argument("Organism::move function is only to move to the adjacent cell. Use Organism::route function to chain the moves to a non-adjacent cell");
        // push this into error handling function later on
    }
}

void Organism::route(int final_x, int final_y)
{
    while (final_x > x)
    {
        move(x + 1, y);
    }
    while (final_x < x)
    {
        move(x - 1, y);
    }
    while (final_y > y)
    {
        move(x, y + 1);
    }
    while (final_y < y)
    {
        move(x, y - 1);
    }
}

void Organism::hunt(int iterations = 1)
{
    int i = this->Universe->get_addition_value(this->x, this->y);
    int del = 1;
    while (1)
    {
        // helps create the manhatten square (imagine a square rotated by 45 degrees)
        for (int j = 0; j <= del; j++)
        {
            if (Universe->get_cell_pointer(x + del - j, y + j) != NULL)
            {
                Organism *organism = (Organism *)Universe->get_cell_pointer(x + del - j, y + j);
                if (organism->get_name() == 'P')
                {
                    route(x + del - j, y + j);
                }
            }
        }
        del++;
    }
};
class Plant : public Organism
{
private:
    char name;

public:
    Plant(universe::Universe *uni, int x, int y) : Organism(uni, x, y) { this->name = 'P'; }
    ~Plant();
};
class Insect : public Organism
{
private:
public:
    Insect(universe::Universe *Universe, int x, int y);

    ~Insect();
};

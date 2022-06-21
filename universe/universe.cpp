#include <iostream>
#include <cstdlib>
#include <time.h>
#define alpha 0.5
// #pragma once
#include "../0_headers/organisms_headers/organism.h"
// #include "../organisms/organism.cpp"
namespace universe
{
    class Universe
    {
    private:
        int n;
        int k;
        void **universe;

        void create_2D_universe();
        void populate_universe_randomly();
        void populate_universe_manually(void *matrix);

    public:
        Universe(int n, int k);
        int get_n();
        int get_k();

        int get_addition_value(int x, int y);
        void *get_cell_pointer(int x, int y);

        void update_universe(int x, int y, void *final_state);

        ~Universe();
    };

    Universe::Universe(int n, int k)
    {
        this->n = n;
        this->k = k;
        populate_universe_randomly();
    }

    Universe::~Universe()
    {
        std::cout << "Universe destructor" << std::endl;
    }

    void Universe::create_2D_universe()
    {
        this->universe = (void **)calloc(sizeof(int *) * this->n * this->n, sizeof(int *));
    }

    void Universe::populate_universe_randomly()
    {
        srand(time(0));
        int count = k;
        while (count > 0)
        {
            int i = rand();
            if (*(universe + i) == NULL)
            {
                *(universe + i) = &Plant((universe::Universe *)this, (int)(i % n), (int)(i / n));
                count--;
            }
        }
    }

    void Universe::update_universe(int x, int y, void *final_state)
    {
        *(universe + get_addition_value(x, y)) = final_state;
    }

    int Universe::get_addition_value(int x, int y)
    {
        // given a (x,y) => return the value to add to the universe pointer
        // image at
        return x + y * n;
    }

    void *Universe::get_cell_pointer(int x, int y)
    {
        int i = get_addition_value(x, y);
        if (i >= 0 && i < n * n)
        {
            return *(universe + i);
        }
        else
        {
            return NULL;
        }
    }

}
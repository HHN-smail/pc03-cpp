#pragma once
#include <iostream>
// #if !defined(beta)
#include "../organisms_headers/organism.h"

// #endif // alpha
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

        void update_universe(int x, int y, void *final_state);
        void *get_cell_pointer(int x, int y);

        ~Universe();
    };

}
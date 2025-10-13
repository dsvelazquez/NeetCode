#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <string_view>
#include <cassert>

namespace Player
{
    enum Items
    {
        potions,
        torches,
        arrows,
        max_elements
    };
}
int main()
{
    std::vector<int> numItems{1,5,10,5};

    assert(Player::max_elements == numItems.size());


    
    
    return 0;
}
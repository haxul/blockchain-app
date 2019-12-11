#include <dappgame.hpp>
#include "gameplay.cpp"



ACTION dappgame::hi(name user) {
    require_auth(user);
    print("hello ", name{user});
}

EOSIO_DISPATCH(dappgame, (hi))

#include <dappgame.hpp>
#include "gameplay.cpp"



ACTION dappgame::login(name user) {
  require_auth(user);
  auto user_iterator = _users.find(user.value);
  if (user_iterator == _users.end()) {
    _users.emplace(user, [&](auto& new_user) {
         new_user.username = user;
      });
  }
}

EOSIO_DISPATCH(dappgame, (login))

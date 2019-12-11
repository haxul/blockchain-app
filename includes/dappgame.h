#include <eosio/eosio.hpp>

using namespace std;
using namespace eosio;

CONTRACT dappgame : public contract {
public:
using contract::contract;
dappgame(name receiver, name code , datastream<const char*> ds) :
contract(receiver, code, ds), _users(receiver, receiver.value) {}

ACTION hi(name user);


private:
TABLE user_info {
        name username;
        uint64_t wins_count = 0;
        uint64_t lost_xount = 0;
        auto primary_key() const {
            return username.value;
        }
};
typedef multi_index<name("users"), user_info> users_table;
users_table _users;
};

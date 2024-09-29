#ifndef USER_HPP
#define USER_HPP

#include "utils.hpp"
#include <string>

namespace customers {
    
    class Customer {
    public:
        // get attributes
        Customer(__str name, __str cpf, __str password);
        __str get_name();
        __str get_cpf();
        __str get_password();
        __longD get_balance();

        // set attributes
        void set_name(__str name);
        void set_cpf(__str cpf);
        void set_password(__str password);
        void set_balance(__longD value);

        // bank's handles
        account_handle_response transfer(__longD value, Customer* dest);
        account_handle_response deposit(__longD value);
        account_handle_response withdraw(__longD value);
        
    private:
        __str name;
        __str cpf;
        __str password;
        __longD balance;
    };

}

#endif
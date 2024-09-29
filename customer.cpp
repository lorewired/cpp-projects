#include "customer.hpp"

customers::Customer::Customer(__str name, __str cpf, __str password)
: name(name)
, cpf(cpf)
, password(password)
{}

__str customers::Customer::get_name() { return this->name; }
__str customers::Customer::get_cpf() { return this->cpf; }
__str customers::Customer::get_password() { return this->password; }
__longD customers::Customer::get_balance() { return this->balance; }

void customers::Customer::set_name(__str name) { this->name = name; }
void customers::Customer::set_cpf(__str cpf) { this->cpf = cpf; }
void customers::Customer::set_password(__str password) { this->password = password; }
void customers::Customer::set_balance(__longD balance) { this->balance = balance; }

account_handle_response customers::Customer::transfer(__longD value, customers::Customer* dest) {
    if (value <= 0) return account_handle_response{ 400, "invalid value" };
    if (this->balance >= value) {
        dest->balance += value;
        this->balance -= value;
        return account_handle_response{ 201, "successful transfer" };
    }
    return account_handle_response{ 500, "not enough balance" };
}

account_handle_response customers::Customer::deposit(__longD value) {
    this->balance += value;
    return account_handle_response{ 500, "not enough balance" };
}

account_handle_response customers::Customer::withdraw(__longD value) {
    if (value <= 0) return account_handle_response{ 400, "invalid value" };
    if (this->balance < value) return account_handle_response{ 500, "not enough balance" };
    this->balance -= value;
    return account_handle_response{ 201, "successful withdraw" };
}
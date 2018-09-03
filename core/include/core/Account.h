/*
 * Copyright (c) 2018 GSENetwork
 *
 * This file is part of GSENetwork.
 *
 * GSENetwork is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or any later version.
 *
 */

#pragma once

#include <core/Object.h>
#include <core/RLP.h>
#include <core/Common.h>
#include <core/Address.h>

namespace core {

#define ACCOUNT_COMMON_FIELDS (4)

class Account: public Object {
public:
    Account() {}

    Account(int64_t timestamp);

    Account(bytesConstRef data);

    ~Account();

    bool operator==(Account const& account) const;

    bool equal(Account const& account) const;

    void streamRLP(RLPStream& rlpStream) const;

    void setAddress(Address const& address);

    void setAlive(bool status);

    void setBalance(uint64_t balance);

    void addContractAddress(Address const& address);

    Address const& getAddress() const;

    bool isAlive() const;

    uint64_t getBalance() const;

    int64_t getTimestamp() const;

    Addresses const& getContractAddresses() const;

    // @override
    std::string getKey();

    // @override
    std::string getRLPData();

private:
    Address m_address;
    bool m_alive = false;
    uint64_t m_balance;
    int64_t m_timestamp;
    Addresses m_contractAddresses;

    h256 m_hash;
};

} /* namespace */
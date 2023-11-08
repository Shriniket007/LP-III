// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

contract Bank {
    int256 balance;

    constructor() {
        balance = 0;
    }

    function getBalance() view public returns(int256) {
        return balance;
    }

    function withdraw(int256 amt) public {
        require(amt>=0);
        require(balance>=amt);
        balance-=amt;
    }

    function deposit(int256 amt) public {
        require(amt>=0);
        balance+=amt;
    }
}
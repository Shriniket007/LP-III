pragma solidity ^0.8.0

contract bank{
    int256 balance;

    constructor(){
        balance = 0;
    }

    function getBalance() public view returns(int256){
        return balance;
    }

    function withdraw(int256 amt) public{
        require(amt >= 0);
        require(balance >= amt);
        balance -= amt;
    }

    function deposit(int256 amt) public {
        require(amt>=0);
        balance += amt;
    }
}
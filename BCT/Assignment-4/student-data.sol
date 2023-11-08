//SPDX-License-Identifier: UNLICENSED

pragma solidity ^0.8.0;

contract MarksManagementSystem
{
    //Create a structure for student details
    struct Student
    {
        int256 ID;
        string Name;
        int256 Marks;
    }

    address owner;

    int256 public stdCount = 0;

    //Create array to store student data
    Student[] studentArr;

    constructor()
    {
        owner = msg.sender;
    }

    function addNewRecords(int256 _ID, string memory _Name, int256 _Marks) public payable 
    {
        stdCount += 1;
        studentArr.push(Student(_ID,_Name,_Marks));
    }

    function getAllRecords() view public returns(Student[] memory)
    {
        return studentArr;
    }

}
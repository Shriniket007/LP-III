pragma solidity ^0.8.0

contract studentData {
    struct student {
        int256 ID;
        string Name;
        int256 Marks;
    }

    address owner;

    student[] studentArr;

    constructor(){
        owner = msg.sender;
    }

    function addNewRecord(int256 _ID, string memory _Name, int256 _marks) public payable
    {
        studentArr.push(student(_ID, _Name, _Marks));
    }

    function getAllRecords() public view returns(studentArr[] memory){
        return studentArr;
    }
}
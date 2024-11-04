//SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

contract Bank
{
    struct User
    {
        int accno;
        string name;
        uint bal;
    }

    User[] users;

    function addUser(int accno, string memory name, uint bal)
    public 
    {
        User memory newUser = User(accno,name,bal);
        users.push(newUser);
    }

    function getUser(int accno) public view returns (string memory, uint)
    {
        for (uint i=0; i<users.length; i++)
        {
            if (users[i].accno == accno)
            {
                return (users[i].name, users[i].bal);
            }
        }
        return ("not found",0);
    }

    function getBal(int accno) public view returns (uint)
    {
        for (uint i=0; i<users.length; i++)
        {
            if (users[i].accno == accno)
            {
                return (users[i].bal);
            }
        }
        return (0);
    }

    function deposit(int accno, uint amount) public 
    {
        for (uint i=0; i<users.length; i++)
        {
            if (users[i].accno == accno)
            {
                users[i].bal += amount;
                break;
            }
        }
    }

    function withdraw(int accno, uint amount) public 
    {
        for (uint i=0; i<users.length; i++)
        {
            if (users[i].accno == accno && users[i].bal >= amount)
            {
                users[i].bal -= amount;
                break;
            }
        }
    }
}

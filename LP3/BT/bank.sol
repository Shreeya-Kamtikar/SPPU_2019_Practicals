//SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

construct Bank
{
  struct User
  {
    int accno;
    string name;
    string phone;
    uint balance;
  }

    User[] users;

    function addUser(int accno, string memory name, string memory phone, uint balance) public
    {
      User memory newUser =  User(accno,name,phone,balance);
      users.push(newUser);
    }

    function getUser(int accno) public view returns (string memory, string memory, uint)
    {
      for(uint i=0; i<users.length; i++)
      {
        if(users[i].accno == accno)
        {
          return (users[i].name, users[i].phone, users[i].balance)
        }
      }
      return ("Not found", "Not found", 0)
    }
    
    function getBalance(int accno) public view returns (uint)
    {
      for(uint i=0; i<users.length; i++)
      {
        if(users[i].accno == accno)
        {
          return (users[i].balance)
        }
      }
      return ( 0)
    }

    function withdrawMoney(int accno, uint amount) public 
    {
      for (uint i=0; i<users.length; i++)
      {
        if (users[i].accno == accno && users[i].balance >= amount)
        {
          users[i].balance -= amount;
          break;
        }
      }
    }

      function depositMonet(int accno, uint amount) public 
    {
      for (uint i=0; i<users.length; i++)
      {
        if (users[i].accno == accno)
        {
          users[i].balance += amount;
          break;
        }
      }
    }
      
}
      

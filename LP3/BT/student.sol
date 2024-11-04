// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

contract StudentData 
{
    // Structure to store student details
    struct Student {
        uint id;
        string name;
        uint grade;
    }

    // Array to store list of students
    Student[] public students;

    event FallbackTriggered(string message);

    // Function to add a new student
    function addStudent(uint id, string memory name, uint grade) public {
        Student memory newStudent = Student(id, name, grade);
        students.push(newStudent);
    }

    // Function to get student details by ID
    function getStudent(uint id) public view returns (string memory name, uint grade) {
        for (uint i = 0; i < students.length; i++) {
            if (students[i].id == id) {
                return (students[i].name, students[i].grade);
            }
        }
        return ("Student not found", 0);
    }

    // Function to update student's grade
    function updateGrade(uint id, uint newGrade) public {
        for (uint i = 0; i < students.length; i++) {
            if (students[i].id == id) {
                students[i].grade = newGrade;
                break;
            }
        }
    }

    // Fallback function to handle unexpected calls or payments
    fallback() external {
        // This function is called when no other function matches the call
        // or when Ether is sent directly to the contract.
        emit FallbackTriggered("You have entered the fallback function");
    }

}

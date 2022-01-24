# Animal-Guessing-Game developed in C++
Cian Kelly

CSC16 Final Project Description

Our project is using a binary tree data structure. We used implemented a binary tree because the user is only inputting binary inputs (yes/no). The user first must think of an animal, and they enter yes when they’ve thought of it. The user is then asked a question (“Is it a reptile?”), and the user enters either yes/no based on their animal. The program asks another yes/no question, and continues to ask them until they reach a specific-animal-question, such as “Is it a Cat?”.
If the user enters yes to this, the tree will stop being traversed, and will ask the user to play again. But if they answer no, the program will ask for the name of the animal the user had in mind. It will then ask for a yes/no question that leads to that animal. The node asking “Is it a Cat?” changes to this yes/no question, the “Is it a Cat” node and the new animal node are then added as leaves to this question. The user will then be asked to play again or not, and if they say no, these new nodes are written in the file.

This program has a complexity of O(logn). This is because eash node except the leaves has 2 children each, so counting the nodes at each level would go as follows: 1 + 2 + 4 + 8 + … + 2^h-1 +2^h, with h being the height of the tree.

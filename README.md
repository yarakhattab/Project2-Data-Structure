## 🎮 Rope-Pulling Game Simulation 🏆
Welcome to the Rope-Pulling Game Simulation! This project simulates a tournament where teams compete in a rope-pulling game. The simulation handles multiple rounds, determines the winner, and identifies the runner-up through an interesting tournament process.

## 📝 Features:
Team Formation: Enter the number of teams and their IDs to start the game.
Tournament Process: Teams are paired and compete in multiple rounds. The winner of each round advances, and the loser is eliminated.
Champion & Runner-Up: The last remaining team becomes the Champion. A separate process identifies the true Runner-Up from teams that lost to the champion.


## ⚙️ How It Works:
Team Input: Users input the number of teams and their IDs. The program validates the input.
Match Simulation: Teams are paired and face off in a series of rounds.
Winner Determination: The winner of each match is determined based on the round number (odd/even).
Champion Declaration: The last team standing in the queue becomes the Champion 🏆.
Runner-Up: A separate process checks teams that lost to the champion to determine the real runner-up 🥈.


## 💻 Code Structure:
main.c: Main logic for team input, match processing, and determining the champion and runner-up.
Helper Functions:
findthechampion: Handles the matches and determines the champion.
findtherealrunnerup: Determines the real runner-up from teams that lost to the champion.
Data Structures:
Stack: Used for managing the teams.
Queue: Used for organizing teams through the rounds of the tournament.


## 🎮 Example Input & Output:
Input:
Copy to BlackBox
Please Enter The input line of teams in format n id1 id2 id3 ... (or enter -9999 to stop):
5 101 102 103 104 105
4 106 107 108 109
-9999
Output:
Copy to BlackBox
Process line with 5 teams: 5 101 102 103 104 105
Team 101 automatically goes to the next round
Queue before round 1: 101 102 103 104 105
The match: Team 102 vs Team 101, the winner is: Team 101
...
The Champion is Team 103
The Real Runner-Up is Team 102


## 📚 Notes:
The round number determines the winner based on team IDs (odd = small team ID wins, even = large team ID wins).
The Champion is the final team in the queue after all rounds.
The Real Runner-Up is determined by re-evaluating the teams that lost to the champion.



## ✍️ Author:
Name: Yara Khattab
GitHub: yarakhattab
Email: yarakhattab16@gmail.com


Feel free to update it further based on your preferences. Let me know if you'd like any other changes! 😊

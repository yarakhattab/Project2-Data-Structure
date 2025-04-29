// yara khattab 1210520
// sec 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 10000

//queue implemantation
// struct node for queue
typedef struct node* Node;
struct node {
    int data;
    Node next;
};

// Queue typedef
typedef struct node* myQueue;

// stack implemantation
// struct node for Stack
typedef struct mynode* Nodestack;
struct mynode {
    char* line;
    Nodestack next;
};

// Stack typedef
typedef struct  mynode* myStack;


// functions for queue
myQueue createqueue();  // function to create a new queue
int isEmptyqueue(myQueue queue); // function to check if the queue is empty
void printqueue(myQueue queue);  // function to print the elements in the queue
void enqueue(myQueue* queue, int data); // function to add element to the queue
int dequeue(myQueue* queue); // function to dequeue and element form the queue
void deletequeue(myQueue* queue); // function to delete the elements in the queue
Node createqueueNode(int data); // to create a node for the queue
int getqueueSize(myQueue queue); // to get the size of the queue


// functions for Stack
myStack createstack();  //function to create a stack
void push(myStack* top, char* line); //function to push a line to a stack
void pop(myStack* top, char* line);  //function to pop a line from the stack
int isemptyStack(myStack top); //function to check if the stack is empty
void printStack(myStack top);  //function to print the elements in the stack
void deleteStack(myStack* top); // function to delete a stack
int getStackSize(myStack top); // function to get the size of the stack
void pushInt(myStack* top, int data); // function to push an int to a stack
int popInt(myStack* top); // function to pop an int from the stack and get it

//functions to check the validation of the inputs
int validationthenumofTeams(int teamsnumber);
int isvalidnum(char *str);
int validateteamID(int teamID);
int validateLine(char *line);


//the process functions
void findthechampion(char* line);
void findtherealrunnerup(myStack lossStack, int champion);


// implemantation of the queue functions
//create a new queue
myQueue createqueue() {
    myQueue Q = (myQueue)malloc(sizeof(struct node));
    Q->next = NULL;
    return Q;
}

//check if the queue is empty
int isEmptyqueue(myQueue queue) {
    return (queue->next == NULL);
}

// print the queue
void printqueue(myQueue queue) {
    if (queue == NULL || isEmptyqueue(queue)) {
        printf("queue is empty or not found.\n");
        return;
    }

    Node tempqueue = queue->next;
    printf(" the elements in the queue-> ");
    while (tempqueue != NULL) {
        printf("%d ", tempqueue->data);
        tempqueue = tempqueue->next;
    }
    printf("\n");
}

// add elemente to the queue
void enqueue(myQueue* queue, int data) {
    Node newNode = createqueueNode(data);
    if ((*queue)->next == NULL) {
        (*queue)->next = newNode;
    } else {
        Node temp = (*queue)->next;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// dequeue an elemente from the queue
int dequeue(myQueue* queue) {
    if (*queue == NULL || (*queue)->next == NULL) {
        printf("queue is empty.\n");
        return -1;
    }

    Node temp = (*queue)->next;
    int data = temp->data;
    (*queue)->next = (*queue)->next->next;
    free(temp);

    return data;
}

// delete the queue
void deletequeue(myQueue* queue) {
    if (*queue == NULL || isEmptyqueue(*queue)) {
        return;
    }

    Node ptr = (*queue)->next;
    (*queue)->next = NULL;
    Node temp;

    while (ptr != NULL) {
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
}

//create a new node for the queue
Node createqueueNode(int data) {
    Node newNode = (Node)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("out of space\n");
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// to get the queue size
int getqueueSize(myQueue queue) {
    int sizecount = 0;
    Node temp = queue->next;
    while (temp != NULL) {
        sizecount++;
        temp = temp->next;
    }
    return sizecount;
}


// stack functions implementations

//create a new stack
myStack createstack() {
    return NULL;
}

// push a line to the stack of lines
void push(myStack* Top, char* line) {
    Nodestack newNode = (Nodestack)malloc(sizeof(struct mynode));
    if (!newNode) {
        printf("memory allocation failed.\n");
        return;
    }
    newNode->line = strdup(line);
    newNode->next = *Top;
    *Top = newNode;
}

// push an int to the stack
void pushInt(myStack* Top, int data) {
    char integer[100];
    snprintf(integer, sizeof(integer),"%d", data);
    push(Top, integer);
}

// pop an int from a stack
int popInt(myStack* Top) {
    char line[100];
    pop(Top, line);
    return atoi(line);
}

//pop a line from the stack
void pop(myStack* Top, char* line) {
    if (isemptyStack(*Top)) {
        return;
    }
    Nodestack tempstack = *Top;
    if (line != NULL) {
        strcpy(line, tempstack->line); // Copy the line
    }
    *Top = (*Top)->next;
    free(tempstack->line);
    free(tempstack);
}

// check if the stack is empty
int isemptyStack(myStack Top) {
    return Top == NULL;
}

// delete the stack
void deleteStack(myStack* Top) {
    while (!isemptyStack(*Top)) {
        char line[10000];
        pop(Top, line);
    }
}

// get the size of the stack
int getStackSize(myStack Top) {
    int size = 0;
    while (Top != NULL) {
        size++;
        Top = Top->next;
    }
    return size;
}

//print the stack
void printStack(myStack stack){

    if(stack==NULL){
        printf("Stack Not Found\n");
        return;
    }else if(isemptyStack(stack)){
        printf("Stack is empty, nothing to print\n");
        return;
    }

    Node tempstack=stack->next;

    while(tempstack != NULL){
        printf("%d\t", tempstack->data);
        tempstack=tempstack->next;
    }
    printf("\n");
}


// check the validation functions
// function to check if the input (number of teams ) is valid (in range 1 to 10000)
int validationthenumofTeams(int teamsnumber) {
    return (teamsnumber > 1 && teamsnumber < 10000);
}

// function to check if the inputs is a valid numbers
int isvalidnum(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            if (i == 0 && str[i] == '-') {
                continue; // allow negtive numbers
            }
            return 0;  // if there any input (char) invalid(it is not a digit)
        }
    }
    return 1;  // if all the input is a valid digits
}

//function to check if the input ( teams id ) is valid (in range -10000 to 10000)
int validateteamID(int teamID) {
    return (teamID >= -10000 && teamID <= 10000);
}

// function to validate the input line
int validateLine(char *line) {
    char templine[MAX_INPUT_LENGTH];
    strcpy(templine, line);  // copy the line

    // extract the number of teams and team id's
    char *taken = strtok(templine, " "); // the extraction based on space between them

    // check that the taken is a number not a char or somthing else
    if (!isvalidnum(taken)) {
        printf("The Number Of Teams is invalid \n");
        return 0;
    }

    int numberofteams = atoi(taken);  // the first number in the line is the number of teams (change it to int using atoi)

    // check if the number of teams is in the range
    if (!validationthenumofTeams(numberofteams)) {
        printf("Invalid number of teams, it should be in the range 1 to 10000 \n");
        return 0;
    }

    // count the number of team id in the line
    int teamIDcount = 0;
    while ((taken = strtok(NULL, " ")) != NULL) { // extract between them based on sapce
        // Check if the team id is a number
        if (!isvalidnum(taken)) {
            printf("invalid team ID: %s. it must be numbers only.\n", taken);
            return 0;
        }

        int Teamid = atoi(taken); // get the team id number after change it to int using atoi
        // check if the team id is in the range
        if (!validateteamID(Teamid)) {
            printf("Team ID %d is invalid, it should be in range (-10000 to 10000).\n", Teamid);
            return 0;
        }

        teamIDcount++;
    }

    // check if the number of team id and the number of teams are the same
    if (teamIDcount != numberofteams) {
        printf("The number of teams does not match the number of teams ID \n");
        return 0;
    }

    return 1;  // everything in the line is valid
}



int main() {
    myStack linestack = createstack();  // Create an empty stack to hold the lines
    char inputline[MAX_INPUT_LENGTH];

    while (1) {
        printf("Please Enter The input line of teams in format n id1 id2 id3 ... (or enter -9999 to stop): \n");
        fgets(inputline, sizeof(inputline), stdin);
        inputline[strcspn(inputline, "\n")] = 0; // remove newline char

        // if user enter -9999 so stop
        if (strstr(inputline, "-9999") != NULL) {
            break;
        }

        // check the validation of the line before push it to the stack
        if (validateLine(inputline)) {
            push(&linestack, inputline);  // push the valid line to the stack
        }
    }

    // start the proccess for the lines in the stack
    while (!isemptyStack(linestack)) {
        char poplines[MAX_INPUT_LENGTH]; // variable to hold the poped  line from the stack
        pop(&linestack, poplines);  // pop a line from the stack to procces it
        findthechampion(poplines);  // process the line
    }

    deleteStack(&linestack);  // delete the stack after finishing
    return 0;
}

// function to find the champion
void findthechampion(char* line) {
    myStack stack = createstack();
    myStack tempStack = createstack();
    myQueue queue = createqueue();
    myQueue nextQueue = createqueue();
    myQueue nextqueue = createqueue();

    // stack to store the loss teams and win teams to use later to determine the real runner-up
    myStack lossStack = createstack(); // will store the losers first, then winners

    printf("\n************* Find The Champion *************\n");

    char templine[10000];
    strcpy(templine, line); // Copy the line

    char* takeninput = strtok(templine, " ");
    int numberofTeams = atoi(takeninput);//get the number of teams

    printf("Process line with %d teams: %s\n", numberofTeams, line);

    // Push teams into the stack
    while ((takeninput = strtok(NULL, " ")) != NULL) {
        int teamsid = atoi(takeninput);
        pushInt(&stack, teamsid); // push the team to the stack
    }

    // process the stack before enqueuing
    int stackSize = getStackSize(stack); // get the size of the stack
    if (stackSize % 2 == 1) { // check if the stack size is odd, pop the last team and enqueue it into nextQueue(queue for the next round)
        int thelastteam = popInt(&stack);
        enqueue(&nextQueue, thelastteam);
        printf("team %d automatically go to next round\n", thelastteam);
    }

    // this stack to reverse the order after enqueue it

    while (!isemptyStack(stack)) {
        int team = popInt(&stack);
        pushInt(&tempStack, team);
    }

    // pop from the new stack and enqueue into the queue
    while (!isemptyStack(tempStack)) {
        int team = popInt(&tempStack);
        enqueue(&queue, team);
    }



    // start the match (rounds)
    int roundnum = 1;
    while (getqueueSize(queue) > 1) {

        printf("Queue before round %d: ", roundnum);
        printqueue(queue);

        while (getqueueSize(queue) > 1) {
            int firstteam = dequeue(&queue);
            int secondteam = dequeue(&queue);

            int thewinner;
             // if the round number is odd so the small team id will win
            if (roundnum % 2 == 1) {
                if (firstteam < secondteam) {
                    thewinner = firstteam;
                } else {
                    thewinner = secondteam;
                }

            }
            // if the round number is even then the large team id will win
            else {
                if (firstteam > secondteam) {
                    thewinner = firstteam;
                } else {
                    thewinner = secondteam;
                }
            }

            // push the loser first, then the winner to the lossStack to use it in real runner-up
            if (firstteam != thewinner) {
                pushInt(&lossStack, firstteam);  // push the loser first
                pushInt(&lossStack, thewinner); // push the winner next
            } else {
                pushInt(&lossStack, secondteam);  // push the loser first
                pushInt(&lossStack, thewinner); // push the winner next
            }

            enqueue(&nextqueue, thewinner); // add the winner to the queue for next round
            printf(" the match: Team %d aganist Team %d, the winner is : Team %d\n", firstteam, secondteam, thewinner);
        }

        // the last team automatically advances to next round if the number of teams is odd
        if (getqueueSize(queue) == 1) {
            int thelastTeam = dequeue(&queue);
            enqueue(&nextQueue, thelastTeam);
            printf("Team %d automatically go to next round\n", thelastTeam);
        }

        while(getqueueSize(nextqueue) > 0){
            int x = dequeue(&nextqueue);
            enqueue(&nextQueue, x);
        }

        // go to the next round
        queue = nextQueue;
        nextQueue = createqueue(); // Reset nextQueue for the next round
        roundnum++;
    }

    // print the champion of the match
    int champion = dequeue(&queue);
    printf("\nThe Champion is Team %d\n", champion ); // The last remaining team in the queue is the champion
    findtherealrunnerup(lossStack,champion); // determine the real runner-up

    deletequeue(&queue); // delete the queue
}

// function to determine the real runner-up
//it take the lossstack and the champion as a prameter
void findtherealrunnerup(myStack lossStack, int champion) {

    printf("\n************* Find The Real Runner-UP *************\n");

    // queue to hold the teams
    myQueue realrunnerupqueue = createqueue();

    //start the process to get the real runner-up
    while (!isemptyStack(lossStack)) {
        int winnerteam = popInt(&lossStack);  // Get the win team
        int loserteam = popInt(&lossStack);   // Get the lose team

        if (winnerteam == champion) {
            // if the winner match the champion, this means the loser loss aganist to the champion
            enqueue(&realrunnerupqueue, loserteam);  // add the loser to the queue
        }
    }



    // Process rounds
    int round = 1;
    while (getqueueSize(realrunnerupqueue) > 1) {


        printf("Queue before round %d: ", round);
        printqueue(realrunnerupqueue);

        while (getqueueSize(realrunnerupqueue) > 1) {
            int firstteam = dequeue(&realrunnerupqueue);
            int secondteam = dequeue(&realrunnerupqueue);

            int winner;

            // if the round is odd so the small team  win
            if (round % 2 == 1) {
                if (firstteam < secondteam) {
                    winner = firstteam;
                } else {
                    winner = secondteam;
                }
            }

            // if even round so large team win
             else {
                if (firstteam > secondteam) {
                    winner = firstteam;
                } else {
                    winner = secondteam;
                }
            }

            // Print the match result
            printf("the match for runner-up: Team %d vs Team %d, Winner: Team %d\n", firstteam, secondteam, winner);

            // enqueue the winner for the next round
            enqueue(&realrunnerupqueue, winner);
            round++; // move to the next round

        }

    }

    // The last remaining team in the queue is the real runner-up
    int runnerUp = dequeue(&realrunnerupqueue);
    printf("\nThe Real Runner-Up is Team %d\n", runnerUp);

    // delete the queue
    deletequeue(&realrunnerupqueue);
}

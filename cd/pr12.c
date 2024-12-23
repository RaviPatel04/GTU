#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_INPUT_SIZE 100

typedef struct {
    int state[MAX_STACK_SIZE];
    char symbol[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int state, char symbol) {
    s->top++;
    s->state[s->top] = state;
    s->symbol[s->top] = symbol;
}

void pop(Stack *s, int count) {
    s->top -= count;
}

int topState(Stack *s) {
    return s->state[s->top];
}

void printStack(Stack *s) {
    printf("Stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d%c ", s->state[i], s->symbol[i]);
    }
    printf("\n");
}

typedef struct {
    char action[10];
    int nextState;
} TableEntry;

TableEntry actionTable[6][3] = {
    {{"s3", 3}, {"s4", 4}, {"", 0}}, // State 0
    {{"", 0}, {"", 0}, {"acc", 0}},    // State 1
    {{"s3", 3}, {"s4", 4}, {"", 0}},   // State 2
    {{"r2", 0}, {"r2", 0}, {"r2", 0}}, // State 3
    {{"r3", 0}, {"r3", 0}, {"r3", 0}}, // State 4
    {{"r1", 0}, {"r1", 0}, {"r1", 0}}, // State 5
};

int gotoTable[6][2] = {
    {1, 2}, // State 0
    {0, 0}, // State 1
    {0, 5}, // State 2
    {0, 0}, // State 3
    {0, 0}, // State 4
    {0, 0}, // State 5
};

void parseInput(char *input) {
    Stack stack;
    initStack(&stack);
    
    // Initialize stack with state 0
    push(&stack, 0, 'S');

    int ipIndex = 0;
    char symbol;
    printf("Parsing input: %s\n", input);

    while (1) {
        int state = topState(&stack);
        symbol = input[ipIndex];
        // Mapping input symbols to columns in the parsing table
        int actionCol;
        if (symbol == 'b') {
            actionCol = 0;
        } else if (symbol == 'd') {
            actionCol = 1;
        } else if (symbol == '$') {
            actionCol = 2;
        } else {
            printf("Error: Invalid symbol '%c'\n", symbol);
            return;
        }
        TableEntry action = actionTable[state][actionCol];
        if (action.action[0] == 's') {
            // Shift
            printf("Action: Shift, Push state %d\n", action.nextState);
            push(&stack, action.nextState, symbol);
            ipIndex++; // Move to the next input symbol
        } else if (action.action[0] == 'r') {
            // Reduce
            int ruleNum = action.action[1] - '0';
            printf("Action: Reduce by rule %d\n", ruleNum);
            int popCount;

            switch (ruleNum) {
                case 1: // Reduce S -> CC
                    popCount = 2;
                    break;
                case 2: // Reduce C -> cC
                    popCount = 2;
                    break;
                case 3: // Reduce C -> d
                    popCount = 1;
                    break;
                default:
                    printf("Error: Unknown reduction rule\n");
                    return;
            }
            pop(&stack, popCount);
            // Get the top state and find the GOTO entry
            state = topState(&stack);
            int gotoCol = (ruleNum == 1) ? 0 : 1; // Goto for S or C
            int nextState = gotoTable[state][gotoCol];
            printf("Goto state: %d\n", nextState);
            push(&stack, nextState, (ruleNum == 1) ? 'S' : 'C');
        } else if (strcmp(action.action, "acc") == 0) {
            // Accept
            printf("Input is successfully parsed.\n");
            return;
        } else {
            printf("Error: Invalid action\n");
            return;
        }
        printStack(&stack);
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter input string (terminated with $): ");
    scanf("%s", input);

    parseInput(input);
    return 0;
}

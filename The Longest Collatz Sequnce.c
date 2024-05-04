#include<stdio.h> 

int collatz_sequence_function(int limit) { // function for calculating the lenght og a given number (in parameter)
    int count = 1; // decrale count to keep the track of lenght .
    while (limit != 1) {
        if (limit % 2 == 0) {
            limit = limit / 2;
            count++;  // whenever this condition becomes true count gets incremented..
        } else {  
            limit = (limit * 3) + 1;   //similary when the number is odd , count incremented
            count++;
        }
        
    }
    return count;
}

int longest_collatz_sequence(int limit) { // function for finding the the number which has longest lenght 
    int max_length = 0;
    int starting_number = 0;
    for (int i = 1; i <= limit; i++) { // loop will run from 1 to given limit
        int length = collatz_sequence_function(i);
        if (length > max_length) {
            max_length = length;
            starting_number = i; // whenever the lenght of given number is bigger than previous one strating number updated 
        }
    }
    return starting_number;
}

int main() {
    int limit;
    printf("Enter a limit: ");
    scanf("%d", &limit);

    int longest_starting_number = longest_collatz_sequence(limit);
    int longest_length = collatz_sequence_function(longest_starting_number);  

    printf("The starting number under %d that produces the longest Collatz sequence is %d.\n", limit, longest_starting_number);
    printf("The length of the Collatz sequence is %d.\n", longest_length);

    return 0;
}


//Brief Explaination:
/*In the first function I just implemented a logic according to the given rules of collatz conjecture sequence function. 
In the second function I took a limit(N) in a parameter and then I used FOR loop for the purpose to find the number which contain longest collatz sequence, 
I was passing numbers from this function to first function from which I was getting the length of that given number(From First Function) and then 
I was returning it into second function in which I was finding the number which has max length(continuously updating).*/

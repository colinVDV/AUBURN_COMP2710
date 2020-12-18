/******************************************************************************************
Name: Colin Vande Vijvere
Auburn ID: ccv0004
Email: ccv0004@auburn.edu
FileName: project4_VandeVijvere_ccv0004.cpp
compiling: g++ project4_VandeVijvere_ccv0004.cpp -std=c++11
Help received: none
******************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

//variable to keep track of amount of questions in the linked list
int question_amount = 0;


//structure that resembles the node of 1 question
struct TriviaNode {
	string question, answer;
	int points;
	TriviaNode *next;
};
typedef TriviaNode* pointer_node;



// function declaration
void init_question_list(pointer_node& tL);
void add_question(pointer_node& tL);
int ask_question(pointer_node tL, int num_ask);
void Unit_Test();



#define TRIVIA_QUIZ

int main() {
#ifdef TRIVIA_QUIZ
	pointer_node node_list = new TriviaNode;
	init_question_list(node_list);


	cout << "*** Welcome to Colin's trivia quiz game ***\n";
	string input;
	bool keep_going = true;
	while(keep_going) {
		add_question(node_list);
		cout << "Continue adding questions? (Yes/No): ";
		getline(cin, input);
		if (input.compare("YES") == 0 || input.compare("Yes") == 0 || input.compare("yes") == 0) {
			keep_going = true;
		} else {
			keep_going = false;
		}
	} 
	cout << "\n";

	//Start of the trivia quiz game
	ask_question(node_list, question_amount);
	cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***\n";
	return 0;
}
#endif


#ifdef UNIT_TESTING
	Unit_Test();
	return 0;
}
#endif


//function to add three pre-made questions to our linkedlist
void init_question_list(pointer_node& tL) {
	pointer_node pointer = new TriviaNode;

	//adding first question
	pointer->question = "How long was the shortest war on record? (Hint: how many minutes)";
	pointer->answer = "38";
	pointer->points = 100;
	pointer->next = new TriviaNode;

	// Initialize tL to be first question
	tL = pointer;
	pointer = tL->next;

	//adding second question
	pointer->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
	pointer->answer = "Bank of Italy";
	pointer->points = 50;
	pointer->next = new TriviaNode;
	pointer = pointer->next;

	//adding third question
	pointer->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
	pointer->answer = "Wii Sports";
	pointer->points = 20;
	pointer->next = NULL;

	//adding the question amount
	question_amount += 3;
}






//function called to ask N questions
int ask_question(pointer_node tL, int num_ask) {
	pointer_node pointer = tL;
	string user_answer;
	int total_points = 0;

	// Check if tL is null
	if (tL == NULL) {
		return 0;
	}

	// check if num_ask > 0
	if (num_ask <= 0) {
		cout << "Warning - the number of trivia to be asked must equal to or be larger than 1." << endl;
		return 1;
	} else if (question_amount < num_ask) {
		cout << "Warning - there is only " << question_amount << " trivia in the list." << endl;
		return 1;

	// Ask the amount of questions
	// Adds the question points to total_points if correct
	} else {
		for (int i = 0; i < num_ask; i++) {
			cout << "Question: " << pointer->question << endl;
			cout << "Answer: ";
			getline(cin, user_answer);
			if (user_answer.compare(pointer->answer) == 0) {
				cout << "Your answer is correct. You receive " << pointer->points << " points." << endl;
				total_points += pointer->points;
			} else {
				cout << "Your answer is wrong. The correct answer is: " << pointer->answer << endl;
			}
			cout << "Your total points: " << total_points << endl << endl;

			pointer = pointer->next;
		}
	}
	return 0;
}








//function made to add questions to tL
void add_question(pointer_node& tL) {
	// Initialize new pointer
	pointer_node new_ptr = new TriviaNode;

	// Get input
	cout << "Enter a question: ";
	getline(cin, new_ptr->question);
	cout << "Enter an answer: ";
	getline(cin, new_ptr->answer);
	cout << "Enter award points: ";
	cin >> new_ptr->points;
	cin.ignore(); 
	new_ptr->next = NULL; 

	// Find the tail of the linkedlist and add the node to the linkedlist
	TriviaNode* tail = tL;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = new_ptr;

	
	question_amount += 1;
}






//Testing function
void Unit_Test() {
	cout << "*** This is a debugging version ***\n";

	pointer_node node_list = new TriviaNode;
	init_question_list(node_list);

	cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
	ask_question(node_list, 0);
	cout << "Case 1 passed\n\n";

	cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
	ask_question(node_list,1);
	cout << "Case 2.1 passed\n\n";

	cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
	ask_question(node_list,1);
	cout << "Case 2.2 passed\n\n";

	cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list." << endl;
	ask_question(node_list,3);
	cout << "Case 3 passed\n\n";

	cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
	ask_question(node_list,5);
	cout << "Case 4 passed\n\n";

	cout << "*** End of the Debugging Version ***";
}





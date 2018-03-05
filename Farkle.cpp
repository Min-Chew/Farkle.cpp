/**********************************************************************
 ** Program Filename: Farkle
 ** Author: Min Chew
 ** Date: 25 February 2018
 ** Description: This is a program of the dice game Farkle
 ** Input: Number of players, dice to keep, continuation of turn 
 ** Output: The game commences
 **********************************************************************/


#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;


/**********************************************************************
 ** Function: number_Players
 ** Description: Gets number of players from user
 ** Parameters: N/A
 ** Pre-conditions: N/A
 ** Post-conditions: Returns number of players as an int
 **********************************************************************/
int number_Players() {                                                                            
	int incorrect = 0, length = 0;
	string res = " ";
	cout << "How many players are there?" << endl;
	getline(cin,res);
	for (int i=0; i<res.length(); i++) {
		if (res[i] < 50 || res[i] > 57) {
			incorrect++;
		}	
	}
	for (int i=0; i<res.length(); i++) {
		length++;	
	}
	while (incorrect > 0 || length == 0 ) {
		cout << "Bad input, try again." << endl;
		getline(cin,res);
		incorrect = 0;
		length = 0;
		for (int i=0; i<res.length(); i++) {
			if (res[i] < 50 || res[i] > 57) {
				incorrect++;
			}
		}
		for (int i=0; i<res.length(); i++) {
			length++;	
		}	
	}
	return strtof((res).c_str(),0);
}


/**********************************************************************
 ** Function: pop_array
 ** Description: Populates the array with '0's
 ** Parameters: total_scoreboard, num_Players
 ** Pre-conditions: Must have a scoreboard and knows number of players
 ** Post-conditions: N/A
 **********************************************************************/
void pop_array(int* total_scoreboard, int num_Players) {
	for (int i=0; i<num_Players; i++) {
		total_scoreboard[i] = 0;                                       
	}	
}


/**********************************************************************
 ** Function: check_singles
 ** Description: Checks for combinations of '1's or '5's
 ** Parameters: dice_combination
 ** Pre-conditions: Must have a string with the values of dice rolled
 ** Post-conditions: Returns 1 if finds combo
 **********************************************************************/
int check_singles(string dice_combination) {
	int res = 0;
	for (int i=0; i<dice_combination.length(); i++) {
		if (dice_combination[i] == '1') {
			res++;	
		}
		else if (dice_combination[i] == '5') {
			res++;	
		}	
	}
	if (res > 0) {
		return res;	
	}
	return 0;
}


/**********************************************************************
 ** Function: check_triples
 ** Description: Checks for combinations of triples
 ** Parameters: dice_combination
 ** Pre-conditions: Must have a string with the values of dice rolled
 ** Post-conditions: Returns 1 if finds combo
 **********************************************************************/
int check_triples(string dice_combination) {
	int seen_one = 0, seen_two = 0, seen_three = 0, seen_four = 0, seen_five = 0, seen_six = 0;
	for (int i=0; i<dice_combination.length(); i++) {
		if (dice_combination[i] == '1') {
			seen_one++;	
		}	
		else if (dice_combination[i] == '2') {
			seen_two++;	
		}
		else if (dice_combination[i] == '3') {
			seen_three++;	
		}
		else if (dice_combination[i] == '4') {
			seen_four++;	
		}
		else if (dice_combination[i] == '5') {
			seen_five++;	
		}
		else if (dice_combination[i] == '6') {
			seen_six++;	
		}
	}
	if (seen_one==3 || seen_two==3 || seen_three==3 || seen_four==3 || seen_five==3 || seen_six==3) {
		return 1;		
	}
	else if (seen_one==6 || seen_two==6 || seen_three==6 || seen_four==6 || seen_five==6 || seen_six==6)
		return 2;
	return 0;
}


/**********************************************************************
 ** Function: check_fours 
 ** Description: Checks for four of any number
 ** Parameters: dice_combination
 ** Pre-conditions: Must have a string with the values of dice rolled
 ** Post-conditions: Returns 1 if finds combo 
 **********************************************************************/
int check_fours(string dice_combination) {
	int seen_one = 0, seen_two = 0, seen_three = 0, seen_four = 0, seen_five = 0, seen_six = 0;
	for (int i=0; i<dice_combination.length(); i++) {
		if (dice_combination[i] == '1') {
			seen_one++;	
		}	
		else if (dice_combination[i] == '2') {
			seen_two++;	
		}
		else if (dice_combination[i] == '3') {
			seen_three++;	
		}
		else if (dice_combination[i] == '4') {
			seen_four++;	
		}
		else if (dice_combination[i] == '5') {
			seen_five++;	
		}
		else if (dice_combination[i] == '6') {
			seen_six++;	
		}
	}
	if (seen_one>3 || seen_two>3 || seen_three>3 || seen_four>3 || seen_five>3 || seen_six>3) {
		return 1;		
	}
	return 0;
}


/**********************************************************************
 ** Function: check_fives 
 ** Description: Checks for five of any number
 ** Parameters: dice_combination
 ** Pre-conditions: Must have a string with the values of dice rolled
 ** Post-conditions: Returns 1 if finds combo 
 **********************************************************************/
int check_fives(string dice_combination) {
	int seen_one = 0, seen_two = 0, seen_three = 0, seen_four = 0, seen_five = 0, seen_six = 0;
	for (int i=0; i<dice_combination.length(); i++) {
		if (dice_combination[i] == '1') {
			seen_one++;	
		}	
		else if (dice_combination[i] == '2') {
			seen_two++;	
		}
		else if (dice_combination[i] == '3') {
			seen_three++;	
		}
		else if (dice_combination[i] == '4') {
			seen_four++;	
		}
		else if (dice_combination[i] == '5') {
			seen_five++;	
		}
		else if (dice_combination[i] == '6') {
			seen_six++;	
		}
	}
	if (seen_one>4 || seen_two>4 || seen_three>4 || seen_four>4 || seen_five>4 || seen_six>4) {
		return 1;		
	}
	return 0;
}


/**********************************************************************
 ** Function: check_sixs
 ** Description: Checks for six of any number
 ** Parameters: dice_combination
 ** Pre-conditions: Must have a string with the values of dice rolled
 ** Post-conditions: Returns 1 if finds combo
 **********************************************************************/
int check_sixs(string dice_combination) {
	int seen_one = 0, seen_two = 0, seen_three = 0, seen_four = 0, seen_five = 0, seen_six = 0;
	for (int i=0; i<dice_combination.length(); i++) {
		if (dice_combination[i] == '1') {
			seen_one++;	
		}	
		else if (dice_combination[i] == '2') {
			seen_two++;	
		}
		else if (dice_combination[i] == '3') {
			seen_three++;	
		}
		else if (dice_combination[i] == '4') {
			seen_four++;	
		}
		else if (dice_combination[i] == '5') {
			seen_five++;	
		}
		else if (dice_combination[i] == '6') {
			seen_six++;	
		}
	}
	if (seen_one>5 || seen_two>5 || seen_three>5 || seen_four>5 || seen_five>5 || seen_six>5) {
		return 1;		
	}
	return 0;
}


/**********************************************************************
 ** Function: check_straight
 ** Description: Checks for one of each number
 ** Parameters: dice_combination
 ** Pre-conditions: Must have a string with the values of dice rolled
 ** Post-conditions: Returns 1 if finds combo
 **********************************************************************/
int check_straight(string dice_combination) {
	int seen_one = 0, seen_two = 0, seen_three = 0, seen_four = 0, seen_five = 0, seen_six = 0;
	for (int i=0; i<dice_combination.length(); i++) {
		if (dice_combination[i] == '1') {
			seen_one++;	
		}	
		else if (dice_combination[i] == '2') {
			seen_two++;	
		}
		else if (dice_combination[i] == '3') {
			seen_three++;	
		}
		else if (dice_combination[i] == '4') {
			seen_four++;	
		}
		else if (dice_combination[i] == '5') {
			seen_five++;	
		}
		else if (dice_combination[i] == '6') {
			seen_six++;	
		}
	}
	if (seen_one>0 && seen_two>0 && seen_three>0 && seen_four>0 && seen_five>0 && seen_six>0) {
		return 1;		
	}
	return 0;	
}


/**********************************************************************
 ** Function: check_three_pairs
 ** Description: Checks for 3 pairs of numbers
 ** Parameters: dice_combination
 ** Pre-conditions: Must have a string with the values of dice rolled
 ** Post-conditions: Returns 1 if finds combo
 **********************************************************************/
int check_three_pairs(string dice_combination) {                                                       
	int index_of_seen_int = 0;
	string seen_int = "000", seen_pair = "000";
	for (int i=0; i<dice_combination.length(); i++) {
		if (dice_combination[i] != seen_int[0] && dice_combination[i] != seen_int[1] && dice_combination[i] != seen_int[2]) {
			seen_int[index_of_seen_int] = dice_combination[i];
			index_of_seen_int++;	
		}
	}
	for (int i=0; i<seen_int.length(); i++) {
		for (int j=0; j<dice_combination.length(); j++) {
			if (seen_int[i] == dice_combination[j]) {
				seen_pair[i]++;	
			}	
		}	
	}
	if (seen_pair[0] == '2' && seen_pair[1] == '2' && seen_pair[2] == '2') {
		return 1;	
	}	
	return 0;
}


/**********************************************************************
 ** Function: check_four_with_pair
 ** Description: Checks for 4 of a kind plus a pair
 ** Parameters: dice_combination
 ** Pre-conditions: Must have a string with the values of dice rolled
 ** Post-conditions: Returns 1 if finds combo
 **********************************************************************/
int check_four_with_pair(string dice_combination) {
	int index_of_seen_int = 0;
	string seen_int = "00", seen_pair = "00";
	for (int i=0; i<dice_combination.length(); i++) {
		if (dice_combination[i] != seen_int[0] && dice_combination[i] != seen_int[1]) {
			seen_int[index_of_seen_int] = dice_combination[i];
			index_of_seen_int++;	
		}
	}
	for (int i=0; i<seen_int.length(); i++) {
		for (int j=0; j<dice_combination.length(); j++) {
			if (seen_int[i] == dice_combination[j]) {
				seen_pair[i]++;	
			}	
		}	
	}
	if ((seen_pair[0] == '4' && seen_pair[1] == '2') || (seen_pair[0] == '2' && seen_pair[1] == '4')) {
		return 1;	
	}	
	return 0;
}


/**********************************************************************
 ** Function: check_triplets
 ** Description: Checks for 3 different pairs of number
 ** Parameters: dice_combination
 ** Pre-conditions: Must have a string with the values of dice rolled
 ** Post-conditions: Returns 1 if finds combo
 **********************************************************************/
int check_triplets(string dice_combination) {
	int index_of_seen_int = 0;
	string seen_int = "00", seen_pair = "00";
	for (int i=0; i<dice_combination.length(); i++) {
		if (dice_combination[i] != seen_int[0] && dice_combination[i] != seen_int[1]) {
			seen_int[index_of_seen_int] = dice_combination[i];
			index_of_seen_int++;	
		}
	}
	for (int i=0; i<seen_int.length(); i++) {
		for (int j=0; j<dice_combination.length(); j++) {
			if (seen_int[i] == dice_combination[j]) {
				seen_pair[i]++;	
			}	
		}	
	}
	if (seen_pair[0] == '3' && seen_pair[1] == '3') {
		return 1;	
	}	
	return 0;
}


/**********************************************************************
 ** Function: valid_moves
 ** Description: Checks for combos to see if there is a valid move
 ** Parameters: dice_combination
 ** Pre-conditions: Must have a string with the values of dice rolled
 ** Post-conditions: Returns true if finds at least one combo
 **********************************************************************/
bool valid_moves(string dice_combination) {
	int res = 0;
	res += check_singles(dice_combination);
	res += check_triples(dice_combination);
	res += check_fours(dice_combination);
	res += check_fives(dice_combination);	
	res += check_sixs(dice_combination);
	res += check_straight(dice_combination);
	res += check_three_pairs(dice_combination); 
	res += check_four_with_pair(dice_combination);
	res += check_triplets(dice_combination);
	if (res > 0)
		return true;
	return false;
}


/**********************************************************************
 ** Function: valid_combination
 ** Description: Checks to see which combos were struck
 ** Parameters: dice_combination
 ** Pre-conditions: Must have a string with the values of dice rolled
 ** Post-conditions: Returns string with valid combos
 **********************************************************************/
string valid_combination(string dice_combination) {                                        
	string res = "000000000";
	int res1 = check_singles(dice_combination);
	int res2 = check_triples(dice_combination);
	int res3 = check_fours(dice_combination);
	int res4 = check_fives(dice_combination);
	int res5 = check_sixs(dice_combination);
	int res6 = check_straight(dice_combination);
	int res7 = check_three_pairs(dice_combination);
	int res8 = check_four_with_pair(dice_combination);
	int res9 = check_triplets(dice_combination);
	if (res1 > 0)
		res[0] = res1+48;
	if (res2 == 1)
		res[1] = res2+48;
	if (res3 == 1)
		res[2] = res3+48;
	if (res4 == 1)
		res[3] = res4+48;
	if (res5 == 1)
		res[4] = res5+48;
	if (res6 == 1)
		res[5] = res6+48;
	if (res7 == 1)
		res[6] = res7+48;
	if (res8 == 1)
		res[7] = res8+48;
	if (res9 == 1)
		res[8] = res9+48;
	return res;
}


/**********************************************************************
 ** Function: print_which_combo
 ** Description: Prints combos that were struck
 ** Parameters: combo_at_index, i
 ** Pre-conditions: Must have a string with the valid combos
 ** Post-conditions: Prints valid combos
 **********************************************************************/
void print_which_combo(string combo_at_index, int i) {
	if (combo_at_index[i] == '1')
		cout << "[1] single 1s or single 5s?" << endl;
	else if (combo_at_index[i] == '2')
		cout << "[2] triples?" << endl;
	else if (combo_at_index[i] == '3')
		cout << "[3] four of a number?" << endl;
	else if (combo_at_index[i] == '4')
		cout << "[4] five of a number?" << endl;
	else if (combo_at_index[i] == '5')
		cout << "[5] six of a number?" << endl;
	else if (combo_at_index[i] == '6')
		cout << "[6] 1-6 straight?" << endl;
	else if (combo_at_index[i] == '7') 
		cout << "[7] three pairs?" << endl;
	else if (combo_at_index[i] == '8')
		cout << "[8] four of any number with a pair?" << endl;
	else if (combo_at_index[i] == '9')
		cout << "[9] two triplets?" << endl;
}


/**********************************************************************
 ** Function: get_combo
 ** Description: Gets user input on which combo will they pick
 ** Parameters: combination
 ** Pre-conditions: Must have a string with the valid combos
 ** Post-conditions: Gets correct user input
 **********************************************************************/
int get_combo(string combination) {  
	int repeat = 1;                                                                             
	string my_str = "", final_str = "";
	getline(cin,my_str);
	while (!(my_str == "1" || my_str == "2" || my_str == "3" || my_str == "4" || my_str == "5" || my_str == "6" || my_str == "7" || my_str == "8" || my_str == "9" || my_str == "10")) {
		cout << "Bad input, try again." << endl;
		getline(cin,my_str);
	}
	for (int i=0; i<combination.length(); i++) {
		if (combination[i] != 48) {
			final_str += i+49;	
		}
	}
	do {
		for (int i=0; i<final_str.length(); i++) {
			if ((final_str[i] == 48+(strtof((my_str).c_str(),0))) || (my_str == "10")) {
				return strtof((my_str).c_str(),0);
			}
		}
		cout << "Bad input, try again." << endl;
		getline(cin,my_str);	
	}while (repeat == 1);		
}


/**********************************************************************
 ** Function: refer_singles
 ** Description: Sums up points for if user picks combo of singles
 ** Parameters: dice_combination
 ** Pre-conditions: Must have a string with values of dice rolled
 ** Post-conditions: Sums up points appropriately 
 **********************************************************************/
int refer_singles(string dice_combination) {
	int if_one = 0, if_five = 0, total_sum = 0;
	for (int i=0; i<dice_combination.length(); i++) {
		if (dice_combination[i] == '1') {
			if_one++;	
		}
		else if (dice_combination[i] == '5') {
			if_five++;	
		}	
	}
	if_one = 100*if_one;
	if_five = 50*if_five;
	total_sum = (if_one + if_five);
	return total_sum;
}


/**********************************************************************
 ** Function: refer_triples
 ** Description: Sums up points for if user picks combo of triples
 ** Parameters: dice_combination
 ** Pre-conditions: Must have a string with values of dice rolled
 ** Post-conditions: Sums up points appropriately 
 **********************************************************************/
int refer_triples(string dice_combination) {
	int res = 0, seen_one = 0, seen_two = 0, seen_three = 0, seen_four = 0, seen_five = 0, seen_six = 0;
	for (int i=0; i<dice_combination.length(); i++) {
		if (dice_combination[i] == '1') {
			seen_one++;	
		}	
		else if (dice_combination[i] == '2') {
			seen_two++;	
		}
		else if (dice_combination[i] == '3') {
			seen_three++;	
		}
		else if (dice_combination[i] == '4') {
			seen_four++;	
		}
		else if (dice_combination[i] == '5') {
			seen_five++;	
		}
		else if (dice_combination[i] == '6') {
			seen_six++;	
		}
	}
	if (seen_one == 3 || seen_one == 6) {
		res += (300*(seen_one/3));	
	}
	if (seen_two == 3 || seen_two == 6) {
		res += (200*(seen_two/3));	
	}
	if (seen_three == 3 || seen_three == 6) {
		res += (300*(seen_three/3));	
	}
	if (seen_four == 3 || seen_four == 6) {
		res += (400*(seen_four/3));	
	}
	if (seen_five == 3 || seen_five == 6) {
		res += (500*(seen_five/3));	
	}
	if (seen_six == 3 || seen_six == 6) {
		res += (600*(seen_six/3));	
	}
	return res;
}


/************************************************************************************
 ** Function: combo_to_score
 ** Description: Turns combo user picks into points
 ** Parameters: chosen_combo, dice_combination
 ** Pre-conditions: Must know chosen combo and string with values of dice rolled 
 ** Post-conditions: Returns points appropriately 
 ************************************************************************************/
int combo_to_score(int chosen_combo, string dice_combination) {
	if (chosen_combo == 1) {	
		int res = refer_singles(dice_combination);
		return res;
	}
	else if (chosen_combo == 2) {
		int res = refer_triples(dice_combination);
		return res;
	}	
	else if (chosen_combo == 3) {
		return 1000;	
	}	
	else if (chosen_combo == 4) {
		return 2000;
	}	
	else if (chosen_combo == 5) {
		return 3000;
	}	
	else if (chosen_combo == 6) {
		return 1500;
	}	
	else if (chosen_combo == 7) {
		return 1500;
	}	
	else if (chosen_combo == 8) {
		return 1500;
	}	
	else if (chosen_combo == 9) {
		return 2500;
	}
	else if (chosen_combo == 10) {
		return 0;
	}	
}


/************************************************************************************
 ** Function: if_chosen_two
 ** Description: Evaluates how many dice can be rerolled if combo chosen was triples
 ** Parameters: copy_total_dice, dice_combination
 ** Pre-conditions: Must know string with values of dice rolled 
 ** Post-conditions: Returns correct amount of dice unused 
 ************************************************************************************/
int if_chosen_two(int copy_total_dice, string dice_combination) {
	int seen_one = 0, seen_two = 0, seen_three = 0, seen_four = 0, seen_five = 0, seen_six = 0;
	for (int i=0; i<dice_combination.length(); i++) {
		if (dice_combination[i] == '1') {
			seen_one++;	
		}	
		else if (dice_combination[i] == '2') {
			seen_two++;	
		}
		else if (dice_combination[i] == '3') {
			seen_three++;	
		}
		else if (dice_combination[i] == '4') {
			seen_four++;	
		}
		else if (dice_combination[i] == '5') {
			seen_five++;	
		}
		else if (dice_combination[i] == '6') {
			seen_six++;	
		}
	}
	if (seen_one==3 || seen_two==3 || seen_three==3 || seen_four==3 || seen_five==3 || seen_six==3) {
		return (copy_total_dice-3);		
	}
	else if (seen_one==6 || seen_two==6 || seen_three==6 || seen_four==6 || seen_five==6 || seen_six==6)
		return 0;
	
}


/************************************************************************************
 ** Function: if_chosen_one
 ** Description: Evaluates how many dice can be rerolled if combo chosen was singles
 ** Parameters: copy_total_dice, dice_combination
 ** Pre-conditions: Must know string with values of dice rolled 
 ** Post-conditions: Returns correct amount of dice unused 
 ************************************************************************************/
int if_chosen_one(int copy_total_dice, string dice_combination) {
	int res = 0, seen_one = 0, seen_five = 0;
	for (int i=0; i<dice_combination.length(); i++) {
		if (dice_combination[i] == '1') {
			seen_one++;	
		}
		else if (dice_combination[i] == '5') {
			seen_five++;	
		}	
	}
	res = (copy_total_dice - seen_one - seen_five);
	return res;
}


/************************************************************************************
 ** Function: total_dice_left
 ** Description: Evaluates how many dice can be rerolled
 ** Parameters: copy_total_dice, chosen_combo, dice_combination
 ** Pre-conditions: Must know string with values of dice rolled and chosen combo
 ** Post-conditions: Returns correct amount of dice unused 
 ************************************************************************************/
int total_dice_left(int copy_total_dice, int chosen_combo, string dice_combination) {
	if (chosen_combo == 5 || chosen_combo == 6 || chosen_combo == 7 || chosen_combo == 8 || chosen_combo == 9) {
		return 0;	
	}
	else if (chosen_combo == 10) {
		return copy_total_dice;	
	}
	else if (chosen_combo == 4) {
		return (copy_total_dice - 5);	
	}
	else if (chosen_combo == 3) {
		return (copy_total_dice - 4);	
	}
	else if (chosen_combo == 2) {
		return if_chosen_two(copy_total_dice, dice_combination);	
	}
	else if (chosen_combo == 1) {
		return if_chosen_one(copy_total_dice, dice_combination);
	}
}


/************************************************************************************
 ** Function: if_valid_move
 ** Description: Evaluates if there are any combos struck or its a Farkle
 ** Parameters: dice_combination, total_dice_roll
 ** Pre-conditions: Must know string with values of dice rolled 
 ** Post-conditions: Checks if there are valid moves or its a Farkle
 ************************************************************************************/
int if_valid_move(string dice_combination, int* total_dice_roll) {
	string combo_at_index = "";
	string combination = valid_combination(dice_combination);
	for (int i=0; i<combination.length(); i++) {
		if(combination[i] != '0') {
			combo_at_index += i+49;
		}	
	}
	cout << endl<< "Do you want to choose the combination of" << endl;
	for (int i=0; i<combo_at_index.length(); i++) {
		print_which_combo(combo_at_index, i);
	}
	cout << "[10] Reroll all dice" << endl;
	int chosen_combo = get_combo(combination);
	int points = combo_to_score(chosen_combo, dice_combination);
	int copy_total_dice = *total_dice_roll;
	*total_dice_roll = total_dice_left(copy_total_dice, chosen_combo, dice_combination);
	return points;
}


/************************************************************************************
 ** Function: print_stas
 ** Description: Prints scoreboards and whose turn
 ** Parameters: total_scoreboard, current_Players, current_scoreboard
 ** Pre-conditions: Must know scoreboards and whose turn it is  
 ** Post-conditions: Prints scoreboards and whose turn
 ************************************************************************************/
void print_stats(int* total_scoreboard, int current_Player, int current_scoreboard) {
	cout << endl << "----- Player " << current_Player+1 << " -----" << endl;
	cout << "Running total score: " << total_scoreboard[current_Player] << endl;
	cout << "Current total: " << current_scoreboard << endl << endl;
}


/************************************************************************************
 ** Function: roll_dice
 ** Description: Rolls dice randomly
 ** Parameters: total_dice_roll
 ** Pre-conditions: Must know how many dice can be rolled
 ** Post-conditions: Returns values of rolled dice in a string 
 ************************************************************************************/
string roll_dice(int total_dice_roll) {
	int res = 0;
	srand(time(NULL));
	string dice_combination = "";
	for (int j=0; j<total_dice_roll; j++) {
		res = rand()%6+1;
		cout << "Dice " << j+1 << ": " << res << endl;
		dice_combination += char(res+48);
	}
	return dice_combination;
}


/************************************************************************************
 ** Function: end_continue
 ** Description: Asks user if they want to add points to scoreboard or continue turn
 ** Parameters: total_dice_roll
 ** Pre-conditions: Must know how many dice can be rolled
 ** Post-conditions: Returns 1 if wants to sum points up already, 0 for continue
 ************************************************************************************/
int end_continue(int total_dice_roll) {
	string res = "";
	cout << "Do you want to end and sum up your score or continue your round?" << endl << "[1] end and sum up" << endl << "[2] continue round" << endl;
	getline(cin,res);	
	if (total_dice_roll == 0) {
		while (res == "2") {
			cout << "No dice left to roll, invalid move. Try again." << endl;
			getline(cin,res);	
		}	
	}
	while (res != "1" && res != "2") {
		cout << "Bad input, try again." << endl;
		getline(cin,res);	
	}
	if (res == "1") {
		return 1;
	}
	else if (res == "2") {
		return 0;
	}
}


/*******************************************************************************************************************
 ** Function: if_continue_move
 ** Description: If first round, checks that current scoreboard is a min of 500 before adding to total scoreboard
 ** Parameters: total_scoreboard, i, current_scoreboard
 ** Pre-conditions: Must know current and total scoreboard
 ** Post-conditions: Only adds current scoreboard to total if current scoreboard is greater than 500 points
 ********************************************************************************************************************/
void if_continue_move(int* total_scoreboard, int i, int current_scoreboard) {	
	if (total_scoreboard[i] == 0) {	
		if (current_scoreboard >= 500) {
			total_scoreboard[i] += current_scoreboard;	
		}
		else {
			cout << "You did not accumulate the minimum of 500 points so you can't add your points to the total scoreboard. Illegal move, turn forfeited." << endl;
		}
	}
	else if (total_scoreboard[i] >= 500) {
		total_scoreboard[i] += current_scoreboard;
	}
}


/************************************************************************************
 ** Function: last_round
 ** Description: Plays out last round to see if anybody can top potential champion
 ** Parameters: num_Players, total_scoreboard, winning_Player
 ** Pre-conditions: Must know how num of players and who is the winning player
 ** Post-conditions: Returns 0 if someone triumphs the potential champion
 ************************************************************************************/
int last_round(int num_Players, int* total_scoreboard, int winning_Player) {
	for (int i=0; i<num_Players; i++) {
		if (i != winning_Player) {
			int total_dice_roll = 6,current_scoreboard = 0, turn_end = 0, if_win = 0;
			while (turn_end == 0) {
				print_stats(total_scoreboard, i, current_scoreboard);	
				string dice_combination = roll_dice(total_dice_roll);
				if (valid_moves(dice_combination) == false) {
					cout << "A Farkle has happened. Turn forfeited." << endl;
					break;
				}
				else {
					current_scoreboard += if_valid_move(dice_combination, &total_dice_roll);
					turn_end = end_continue(total_dice_roll);	
				}
				if (turn_end == 1) {	
					if_continue_move(&*total_scoreboard, i, current_scoreboard);
					}
					print_stats(total_scoreboard, i, current_scoreboard);
				}
			if (total_scoreboard[i] >= total_scoreboard[winning_Player])
				return 0;
		}
	}
	return 1;
}


/************************************************************************************
 ** Function: check_win
 ** Description: Checks to see if anyone has over 10000 points in total
 ** Parameters: num_Players, total_scoreboard, i
 ** Pre-conditions: Must know total scoreboard
 ** Post-conditions: Returns player's "name" is player is undefeated 
 ************************************************************************************/
int check_win(int num_Players, int* total_scoreboard, int i) {
	int went_into_if = 0;
	if(total_scoreboard[i] >= 10000) {
		cout << "Player " << i+1 << " has a running total of " << total_scoreboard[i] << "! Player " << i+1 << " is about to win! Everybody, try to beat that score!" << endl;
		int current_chap = i+1; 
		went_into_if = 1;
		if (last_round(num_Players, &*total_scoreboard, i) == 1) {
			return current_chap;
		}
	}
	if (went_into_if == 1) {
		cout << "Unfortunately, Player " << i+1 << "'s score was topped. Try again next time Player " << i+1 << "!" << endl;
	}
	return 0;
}


/************************************************************************************
 ** Function: taking_turns
 ** Description: Alternates game play between players
 ** Parameters: total_scoreboard, num_Players
 ** Pre-conditions: Must know total scorebd and num of players
 ** Post-conditions: Alternates rounds appropriately 
 ************************************************************************************/
bool taking_turns(int* total_scoreboard, int num_Players) {
	for (int i=0; i<num_Players; i++) {
		int total_dice_roll = 6,current_scoreboard = 0, turn_end = 0, if_win = 0;
		while (turn_end == 0) {
			print_stats(total_scoreboard, i, current_scoreboard);	
			string dice_combination = roll_dice(total_dice_roll);
			if (valid_moves(dice_combination) == false) {
				cout << "A Farkle has happened. Turn forfeited." << endl;
				break;
			}
			else {
				current_scoreboard += if_valid_move(dice_combination, &total_dice_roll);
				turn_end = end_continue(total_dice_roll);	
			}
			if (turn_end == 1) {	
				if_continue_move(&*total_scoreboard, i, current_scoreboard);
				if_win = check_win(num_Players, total_scoreboard, i);
				if (if_win != 0) {
					cout << "Nobody managed to beat Player " << if_win << ", Player " << if_win << " wins the game!!" << endl;
					return 1;
				}
				print_stats(total_scoreboard, i, current_scoreboard);
			}
		}
	}
	return 0;
}


int main() {                                                                       // when to use single/double pointer 
	cout << endl << "Welcome to the game Farkle!" << endl;	
	int num_Players = number_Players();
	int total_scoreboard[num_Players];
	pop_array(total_scoreboard, num_Players);
	int win = taking_turns(total_scoreboard, num_Players);                                          
	while (win == 0) {
		win = taking_turns(total_scoreboard, num_Players);
	}
	return 0;
}

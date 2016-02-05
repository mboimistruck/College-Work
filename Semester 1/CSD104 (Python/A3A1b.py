# Program Name: A3P1.py
#Programmer Name: Michael Boimistruck
#Date Last Compiled: 18/10/2015
#Program Description: The purpose of this program is to see if the user can guess a random integer between 1 and 10 with three tries.


import random
import sys
guesses = 0
rand_int = random.randint(1,10)

def compareValues():
	guesses_ternary = 'tries.' if guesses > 1 else 'try.' #creates a ternary operator to use "try" and "tries" properly
	if user_int == rand_int:
		print ('\n\t\tCongratulations, you got it!\n\t\tYou guessed the number in', guesses, guesses_ternary)
		exit()
	else:
		if rand_int > user_int:
			print ('\n\t\tSorry, too low.\n\t\tTry again | Guesses used:', guesses,'.\n')
		else:
			print ('\n\t\tSorry, too high.\n\t\tTry again | Guesses used:', guesses,'.\n')

def gatherInput():
	global user_int
	global guesses
	while guesses < 3: #validation loop
		try:
			user_int = int(input('\t\tEnter an integer value between 1-10, you get up to three guesses: '))
			if user_int > 10 or user_int < 1:
				print ('\n\t\tPlease enter an integer value between 1-10.')
				continue
		except ValueError:
			print ('\n\t\tPlease enter an integer value between 1-10.')
			continue
		else: 
			break	
	if guesses < 3:
		if guesses == 0:
			guesses =+ 1
			compareValues()
		elif guesses == 1:
			guesses += 1
			compareValues()
		elif guesses == 2:
			guesses += 1
			compareValues()
	else:
		print('\n\t\tSorry, you have no more guesses.\n\t\tThe number is', rand_int,'.')
#method is called four times, on the fourth call it will always reference to the else statement above, to stop the program 
#																(preventing the user from using more than 3 possible rolls)
gatherInput()
gatherInput()
gatherInput()
gatherInput()
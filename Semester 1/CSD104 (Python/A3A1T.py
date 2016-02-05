# Program Name: A3P1.py
#Programmer Name: Michael Boimistruck
#Date Last Compiled: 01/15/2015
#Program Description: The purpose of this program is to see if the user can guess a random integer between 1 and 10 with three tries.

import random 

rand_int = random.randint(1,10)
print(rand_int)
guesses = 0

#loop until three guesses are used
while guesses < 3:
	#loop forever to check for inputs that are invalid (has to be an integer, and between 1-10). 
	#if the value is met, break from the loop and continue
	while True:
		try:
			user_int = int(input('\t\tEnter an integer value between 1-10, you get up to three guesses: '))
		except ValueError:
			print ('Please enter an integer value between 1-10.')
			continue
		if user_int < 1 or user_int > 10:
			print ('Please enter an integer value between 1-10.')
			continue
		else: 
			break
	guesses = guesses + 1
	guesses_ternary = 'tries' if guesses > 1 else 'try'
	#calculate your guess vs the value stored (randInt)
	if rand_int > user_int and guesses != 3:
		print ('\n\t\tSorry, too low.\n\t\t Try again | Guesses used:', guesses,'.\n')
	elif user_int > rand_int and guesses != 3:
		print ('\n\t\tSorry, too high.\n\t\t Try again | Guesses used:', guesses,'.\n')
	elif rand_int == user_int and guesses > 1:
		print ('\n\t\tCongratulations, you got it!\n\t\t You guessed the number in', guesses,'', guesses_ternary)
		break
	elif rand_int == user_int and guesses == 1:
		print ('\n\t\tCongratulations, you got it!\n\t\t You guessed the number in ', guesses,'', guesses_ternary)
		break
else:
	print('\n\t\tSorry, you have no more guesses.\n The number is', rand_int)

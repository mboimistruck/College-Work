# Program Name: A3P2.py
#Programmer Name: Michael Boimistruck
#Date Last Compiled: 18/10/2015
#Program Description: The purpose of this program is to KM > miles, or vice versa; depending on the user's input.

#loop forever until break
while True:
	print('\t\t\tDistance Conversion System\n\n\t\t1. Convert Kilometers to Miles\n\t\t2. Convert Miles to Kilometers\n\t\t3. Exit Program')
	try:
		user_input = int(input("\n\t\t\t Option: "))
	except ValueError:
			print ('Incorrect choice, please run program again...')
			break
	if user_input < 1 or user_input > 3:
			print ('Incorrect choice, please run program again...')
			break
	elif user_input == 1:
		try:
			km = float(input('\n\t\tDistance in Kilometers: '))
			print ('\t\t', km,'kilometers is equivalent to', format(km * 0.6213711, '.1f'), 'miles.\n')
		except ValueError:
			print ('Incorrect choice, please run program again...')
			break
	elif user_input == 2:
		try:
			miles = float(input('\n\t\tDistance in Miles: '))
			print ('\t\t', miles,'miles is equivalent to', format(miles * 1.609344, '.1f'), 'kilometers.\n')
		except ValueError:
			print ('Incorrect choice, please run program again...')
			break
	else:
		break
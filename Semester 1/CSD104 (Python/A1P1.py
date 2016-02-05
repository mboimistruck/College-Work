#Program Name: A1P1.py
#Programmer Name: Michael Boimistruck
#Date Last Compiled: 01/10/2015
#Program Description: The program takes a float value (the celcius) from the user's input
#                     and converts it to a fahrenheit value, rounded to the nearest tenth.

#Gather a float value from the user and then calculate the farhenheit value with the inputted float
celcius = float(input('\n\n\t\tEnter the celcius: '))
fahrenheit = (9 / 5 * celcius + 32)

#Output the results
print('\n\t\t\t', celcius, 'celcius is:', format(fahrenheit, '.1f'), 'in fahrenheit.')
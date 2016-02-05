# Program Name: A4P2.py
# Programmer Name: Michael Boimistruck
# Date Last Compiled: 29/10/2015
# Program Description: Calculates the salary of a worker who's pay doubles every day worked. Also outputs the total.
import os


total = 0
numOfDays = 0
while True:  # validation loop for inputs
    try:
        numOfDays = int(input("Enter the number of days: \n"))
        if numOfDays > 0:
            break
        else:
            print("\nPlease enter a valid integer.")
    except ValueError:
        print("\nPlease enter a valid integer.")
for days in range(0, numOfDays):
    salary = (2 ** days) / 100
    print('\n\t\tDay:', days + 1, "| Salary: $", salary)
    total += salary
print('\n\t\tTotal pay: $', format(total, '.2f'))

os.system("pause")

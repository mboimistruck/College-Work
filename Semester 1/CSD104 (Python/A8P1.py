# Program Name: A8P1.py
# Programmer Name: Michael Boimistruck
# Date Last Compiled: 12/07/2015
# Program Description: Gathers the sales for the week and calculates the total


import os

def input_data(inputs, days):
    for i in range(0, 7):
        while True:
            try:
                inputValue = float(input("\n\tEnter the sales for "+days[i]+": $"))

            except ValueError:
                print('\n\t\tPlease enter a valid number.')
                continue

            else:
                inputs.append(inputValue)
                break


def calculate(inputs): #determines total
    total = 0
    for i in range(0, len(inputs)):
        total += inputs[i]
    return total


def output_results(total):
    print("\n\n\t\tThe total sales for the week is: $", round(total, 2))



def main():
    days = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
    checkVar = "y"

    while checkVar == "y" or checkVar == "Y":
        inputs = []
        input_data(inputs, days)
        total = calculate(inputs)
        output_results(total)
        while True:
            try:
                checkVar = str(input("\n\n\t\tWould you like to run the program again? y/n: "))
            except ValueError:
                print('\n\t\tPlease enter a valid input: "y" or "n".')
                continue
            if checkVar == "y" or checkVar == "Y":
                break
            elif checkVar == "n" or checkVar == "N":
                break
            else:
                print('\n\t\tPlease enter a valid input: "y" or "n".')
                continue

main()

os.system("pause")
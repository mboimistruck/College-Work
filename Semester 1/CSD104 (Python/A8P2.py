# Program Name: A8P2.py
# Programmer Name: Michael Boimistruck
# Date Last Compiled: 12/07/2015
# Program Description: Generates a random seven digit lottery number

import random
import os


def generate_numbers(numbers):
    for i in range(0, 7):
        randomNum = random.randint(0, 9)
        numbers.append(randomNum)


def create_lottery(numbers):
    lottery_number = "".join((str(e) for e in numbers))
    return lottery_number


def output_number(lottery_number):
    print("\n\t\tYour seven digit lottery number is:", lottery_number)
# Not sure how it wants the output looped to display the list ?         <Note for Dennis
# Did it imply to loop a save for each element in the list to a string ?<---------------


def main():
    checkVar = "y"
    while checkVar == "y" or checkVar == "Y":

        numbers = []
        generate_numbers(numbers)
        lottery_number = create_lottery(numbers)
        output_number(lottery_number)

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
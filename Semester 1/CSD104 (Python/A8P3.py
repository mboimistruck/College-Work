# Program Name: A8P3.py
# Programmer Name: Michael Boimistruck
# Date Last Compiled: 12/07/2015
# Program Description: Gathers the min/max rainfall for each month and calculates the total/average/min/max

import os


def input_data(inputs, months_list):
    for i in range(0, 12):
        while True:
            try:
                inputValue = float(input("\n\tEnter the amount of rainfall(in millimeters) for "+months_list[i]+":"))

            except ValueError:
                print('\n\t\tPlease enter a number for the rainfall.')
                continue

            else:
                inputs.append(inputValue)
                break

    temp_list = list(inputs)
    return temp_list


def determine_lowest(lowest_value, inputs):
    inputs.sort()

    for item in inputs:
        if len(lowest_value) == 0:
            lowest_value.append(item)

        elif item == lowest_value[0]:
            lowest_value.append(item)
        else:
            break


def determine_highest(highest_value, inputs):
    inputs.sort(reverse=True)

    for item in inputs:
        if len(highest_value) == 0:
            highest_value.append(item)

        elif item == highest_value[0]:
            highest_value.append(item)

        else:
            break


def determine_month(highest_value, lowest_value, sorted_highest_months, sorted_lowest_months, months_list, temp_list):  #checks for the highest/lowest numbers in the temporary list
    for index, value in enumerate(temp_list):                                                                           #and compares the position of both with the months list array
        if value == highest_value[0]:                                                                                   #determines which months match which min/max values
            sorted_highest_months.append(months_list[index])

        if value == lowest_value[0]:
            sorted_lowest_months.append(months_list[index])


def calculate(inputs): #determines total rainfall and average
    total = 0
    for i in range(0, len(inputs)):
        total += inputs[i]

    average = total/len(inputs)
    return total, average


def output_results(lowest_value, highest_value, sorted_lowest_months, sorted_highest_months, average, total):
    print("\n\n\t\tThe total rainfall for the year is: ", total, "mm")
    print("\n\t\tThe average monthly rainfall for the year is: ", round(average, 1), "mm/mo")

    if len(sorted_highest_months) != 12:
        print("\n\t\tThe following month(s) had the highest rainfall at", highest_value[0], "mm:", ", " .join(sorted_highest_months))
        print("\n\t\tThe following month(s) had the lowest rainfall at", lowest_value[0], "mm:", ", " .join(sorted_lowest_months))

    else:
        print("\n\t\tAll the months of the year have the same amount of rainfall at:", highest_value[0], "mm")


def main():
    months_list = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
    checkVar = "y"

    while checkVar == "y" or checkVar == "Y":
        sorted_highest_months = []
        sorted_lowest_months = []
        highest_value = []
        lowest_value = []
        inputs = []

        temp_list = input_data(inputs, months_list)
        determine_highest(highest_value, inputs)
        determine_lowest(lowest_value, inputs)
        determine_month(highest_value, lowest_value, sorted_highest_months, sorted_lowest_months, months_list, temp_list)
        total, average = calculate(inputs)
        output_results(lowest_value, highest_value, sorted_lowest_months, sorted_highest_months, average, total)
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
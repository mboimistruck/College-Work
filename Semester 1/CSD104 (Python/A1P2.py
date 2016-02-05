# Program Name: A1P2.py
#Programmer Name: Michael Boimistruck
#Date Last Compiled: 01/10/2015
#Program Description: The purpose of this program is to take predefined values provided by the fictional person "Joe"
#                     and calculate his profits made off the stock he purchased and then sold, including his commission fees.

#declare variables
firstStockPayment = 2000 * 40
firstCommissionPaid = (2000 * 40) * 0.03
firstStockPayout = 2000 * 42.75
secondCommissionPaid = (2000 * 42.75) * 0.03
totalValueAfterPayout = firstStockPayout - (secondCommissionPaid + firstCommissionPaid)

#outputs
print('\n\n\t\tThe value Joe paid for the stock: $', format(firstStockPayment, '.2f'))
print('\n\n\t\tCommission paid on purchase: $', format(firstCommissionPaid, '.2f'))
print('\n\n\t\tThe value Joe sold his stock for: $', format(firstStockPayout, '.2f'))
print('\n\n\t\tCommission paid on the sale of his stock: $', format(secondCommissionPaid, '.2f'))
print('\n\n\t\tTotal Money left: $', format(totalValueAfterPayout, '.2f'))
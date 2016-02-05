# Program Name: A4P1.py
# Programmer Name: Michael Boimistruck
# Date Last Compiled: 29/10/2015
# Program Description: Outputs the first 20 conversions of Celsius to Fahrenheit.
import os


for i in range(0, 20):
    f = (9/5) * i + 32
    print('\n\t\tCelsius:', i + 1, '| Fahrenheit:', format(f, '.1f'))

os.system("pause")
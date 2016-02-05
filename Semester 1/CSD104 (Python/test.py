import random

x = int(input('Type 1 to roll, 0 to close the program: \n'))
class Roll():
    def rollDice(self):
    #userNum = 0
    #compNum = 0
    #x = 0
        x = int(input('Type 1 to roll, 0 to close the program: \n'))
        userNum = random.randint(1, 100)
        compNum = random.randint(1, 100)
        print('Your roll:', userNum)
        print('Computer\'s roll:', compNum)
        if userNum > compNum:
            print('You Won!\n')
        elif compNum > userNum:
            print('You Lost!\n')
        elif compNum == userNum:
            print('Draw!\n')
        print('', x)
while (x == 1):

    test = Roll()
    test.rollDice()

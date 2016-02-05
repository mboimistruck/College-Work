import random
x = 1

class Roll():
    userNum = 0
    compNum = 0
    wins = 0
    plays = 0
    def rollDice(self):
        Roll.userNum = random.randint(1, 100)
        Roll.compNum = random.randint(1, 100)
        print('Your roll:', Roll.userNum)
        print('Computer\'s roll:', Roll.compNum)
        Roll.plays = Roll.plays + 1
        if Roll.userNum > Roll.compNum:
            print('You Won!\n')
            Roll.wins = Roll.wins + 1
        elif Roll.compNum > Roll.userNum:
            print('You Lost!\n')
        elif Roll.compNum == Roll.userNum:
            print('Draw!\n')
        print('', x)

while x == 1:
    x = int(input('Type 1 to roll, 0 to close the program: \n'))
    if x == 1:
        test = Roll()
        test.rollDice()
else:
    percentage = "{0:.2f}%".format(test.wins / test.plays * 100)
    print('You have a win percentage of:', percentage, 'after playing', Roll.plays, 'games.')

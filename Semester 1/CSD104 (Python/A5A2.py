while True:
    numOfFloors = int(input('\t\tNumber of floors: '))

    if numOfFloors < 1 or numOfFloors > 20:
        print("\n\t\tIncorrect input, please enter a number between 1 and 20.")
        continue
    else:
        break

for i in range(0, numOfFloors):

    while True:
        numOfRoomsOnFlr = int(input('\n\t\tNumber of rooms on floor'))
        if numOfRoomsOnFlr < 1 or numOfRoomsOnFlr > 10:
            print("\n\t\tIncorrect input, please enter a number between 1 and 10.")
            continue
        else:
            pass
        numOfOccupiedRooms = int(input('\n\t\tNumber of occupied rooms: '))
        if numOfOccupiedRooms > numOfRoomsOnFlr:
            print("\n\t\tThe number of occupied rooms exceeds the number of rooms on the floor, please verify.")
            continue
        else:
            break
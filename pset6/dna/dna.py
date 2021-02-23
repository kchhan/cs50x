import csv
import sys

strs = dict()
people = list()
sequence = str()


def main():
    # Ensure correct usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py database/<#>.csv sequence/<#>.txt")

    # read database and extract sts and people
    open_database(sys.argv[1])

    # read sequence and copy
    sequence = open_sequence(sys.argv[2])

    # count how many repeats in sequence
    count(sequence, strs)

    # check strs counts against the people
    match = check(strs, people)

    print(match)


def open_database(database):
    with open(database, "r") as file:
        reader = csv.DictReader(file)

        for person in reader:
            # converts keys to list to iterate over
            keys = list(person.keys())

            for i in range(1, len(keys)):
                # converts value from string to int
                person[keys[i]] = int(person[keys[i]])

                # add str to strs dict and will not be repeated
                if (keys[i] not in strs):
                    strs[keys[i]] = 0

            # append person to people list
            people.append(person)


def open_sequence(sequence):
    fs = open(sequence, 'r')
    return fs.read()


def count(sequence, strs):
    for repeat in strs:
        arr = []
        index = 0
        counter = 0
        maximum = 0
        repeating = False
        sequence_length = len(sequence)
        repeat_length = len(repeat)
        
        while index < sequence_length - 1:
            # if beginning of sequence
            if (sequence[index: index + repeat_length] == repeat) and (repeating == False):
                repeating = True
                counter += 1
                index += repeat_length
            # if continuing repeating sequence
            elif (sequence[index: index + repeat_length] == repeat) and (repeating == True):
                counter += 1
                index += repeat_length
            # if sequence has stopped repeating
            elif (sequence[index: index + repeat_length] != repeat) and (repeating == True):
                arr.append(counter)
                repeating = False
                counter = 0
                index += 1
            else:
                index += 1
        
        # update strs to have the max repeats
        if len(arr) > 0:
            maximum = max(arr)
        strs[repeat] = maximum
    

def check(strs, people):
    for person in people:
        keys = list(person.keys())
        matches = 0
        for repeat in strs:
            if person[repeat] == strs[repeat]:
                matches += 1
            if matches == len(strs):
                # return culprit name
                return person[keys[0]]
                
    return "No match."


# run main
if __name__ == "__main__":
    main()

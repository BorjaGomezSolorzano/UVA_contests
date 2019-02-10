import sys


if __name__ == '__main__':
    #file = open("example_input_1", "r")
    file = sys.stdin
    for line in file:
        start_end = line.split()
        #Perform calculations

        #Print results
        print('To get from ' + start_end[0] + ' to ' + start_end[1] + ' takes 0 knight moves.')
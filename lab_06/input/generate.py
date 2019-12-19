import sys
import argparse
import random

def create_parser():
    parser = argparse.ArgumentParser()
    parser.add_argument('-f', '--file', required = True)
    parser.add_argument('-c', '--count', required = True, type = int)
    return parser


def main():
    parser = create_parser()
    args = parser.parse_args(sys.argv[1:])
    file = open(args.file, 'w')
    file.write(str(args.count) + "\n")
    matrix = [[0] * args.count for i in range(args.count)]
    for i in range(args.count):
        for j in range(i + 1, args.count):
            el = matrix[j][i] = random.randint(0, 20) - 1;
            matrix[i][j] = 1 if el == 0 else el
    for line in matrix:
        for el in line:
            file.write(str(el) + ' ')
        file.write('\n')
    file.close()


if __name__ == '__main__':
    main()

import msvcrt

arr = [0] * 300
head = 0
s = input()
com = 0
while com < len(s):
    if s[com] == '>':
        head += 1
    elif s[com] == '<':
        head -= 1
    elif s[com] == '+':
        arr[head] += 1
    elif s[com] == '-':
        arr[head] -= 1
    elif s[com] == '[':
        if arr[head] == 0:
            com = s.find(']', com) + 1
            continue
    elif s[com] == ']':
        if arr[head] != 0:
            com = s.rfind('[', 0, com)
            continue
    elif s[com] == '.':
        print(chr(arr[head]), end='')
    elif s[com] == ',':
        arr[head] = ord(msvcrt.getch())
    com += 1

#++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.
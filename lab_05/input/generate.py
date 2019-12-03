for i in range(100, 1001, 100):
    file = open(str(i) + ".txt", "a")
    for j in range(i):
        file.write("@\n")
        file.write("100 100\n")
        for k in range(100):
            file.write("1 " * 100 + "\n")
        file.write("100 100\n")
        for k in range(100):
            file.write("1 " * 100 + "\n")
    file.close()

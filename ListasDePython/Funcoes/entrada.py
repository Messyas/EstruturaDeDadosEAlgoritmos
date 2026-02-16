def valida (msg, min, max):
    while True:
        v = int(input(msg))
        if v >= min and v <= max:
            return v
        else:
            print("Valor entre %d e %d" % (min, max))

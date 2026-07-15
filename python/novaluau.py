import novaluau


def start():
    novaluau.create()


def execute(code):
    return novaluau.execute(code)


if __name__ == "__main__":

    start()

    while True:

        try:

            line = input("> ")

            if line == "exit":
                break


            execute(line)


        except KeyboardInterrupt:

            break

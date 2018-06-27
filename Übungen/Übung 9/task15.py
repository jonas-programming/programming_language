from re import fullmatch

# Define regEx
reg = r"\(([\+\-\*\/][0-9]{2,}|[0-9]+)\)"

# Test again and again
while True:
    # Get phrase to check
    phrase = input("Your phrase to check:\n").replace(" ", "")
    # Check input agains regEx if satisfy grammar
    result = fullmatch(reg, phrase)
    print("Correct:", result is not None)

    if result is not None:
        # If operand is in front calculate with this operand
        if result[1] in ('+', '-', '*', '/'):
            # Catch zero division exception
            try:
                result = eval(result[1].join(result[2:-1]))
            except ZeroDivisionError:
                result = None
        # default result is content of brackets
        else:
            result = int(phrase.strip("()"))
            
        # Print result
        print("Result:", result)

    # New line
    print()

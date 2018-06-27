from re import fullmatch

# Define regEx
reg = r"\(([\+\-\*\/][0-9]{2,}|[0-9]+)\)"

# Test again and again
while True:
    # Get phrase to check
    phrase = input("Your phrase to check:\n")
    # Check input agains regEx if satisfy grammar
    result = fullmatch(reg, phrase)
    print("Correct:", reg is not None)

    if result is not None:
        # Default result - content of brackets
        result = phrase.strip("()")
        # If operand is in front calculate with this operand
        if result[0] in ('+', '-', '*', '/'):
            try:
                result = eval(result[0].join(result[1:]))
            except ZeroDivisionError:
                result = None
            
        # Print result
        print("Result:", int(result))

    # New line
    print()

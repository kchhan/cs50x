from cs50 import get_string

def main():
    text = get_string("Text: ")

    l = count_letters(text)
    w = count_words(text)
    s = count_sentenses(text)

    grade = calculate_grade(l, w, s)

    if grade > 15:
        print("Grade 16+")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {grade}")

# counts letters and return number of alphabet characters in text
def count_letters(text):
    count = 0

    for i in range(len(text)):
        if ord(text[i]) >= 65 and ord(text[i]) <= 95 or ord(text[i]) >= 97 and ord(text[i]) <= 122:
            count += 1

    return count

# counts spaces between words and returns number of words
def count_words(text):
    count = 0

    for i in range(len(text)):
        if ord(text[i]) == 32:
            count += 1

    return count + 1

# counts . ? and ! and return number of sentenses
def count_sentenses(text):
    count = 0

    for i in range(len(text)):
        if ord(text[i]) == 46 or ord(text[i]) == 33 or ord(text[i]) == 63:
            count += 1

    return count

# uses the formula to return int grade number
def calculate_grade(letters, words, sentenses):
    L = (float(letters) / float(words)) * 100
    S = (float(sentenses) / float(words)) * 100

    return int(round(0.0588 * L - 0.296 * S - 15.8))


# run main
if __name__ == "__main__":
    main()

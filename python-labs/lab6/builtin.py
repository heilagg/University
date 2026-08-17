import math
import time


def multiply_list(lst: list):
    return math.prod(lst)
# print(multiply_list([1, 2, 3, 4, 5]))




def count_case(s: str):
    upper = sum(1 for char in s if char.isupper())
    lower = sum(1 for char in s if char.islower())
    return upper, lower
# print(count_case("Hello World"))





def is_palindrome(s: str):
    return s == s[::-1]
# print(is_palindrome("kek"))





def delayed_sqrt(number: int, milliseconds: int):
    time.sleep(milliseconds / 1000)
    return math.sqrt(number)
number = 25100
milliseconds = 2123
# print(f"Square root of {number} after {milliseconds} milliseconds is {delayed_sqrt(number, milliseconds)}")





def all_true(t):
    return all(t)
# print(all_true((True, True, True)))
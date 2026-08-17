import math


def degree_to_radian(degree: int):
    return degree * (math.pi / 180)
# print(degree_to_radian(15))




def area_trapezoid(height: int, base1: int, base2: int):
    return ((base1 + base2) / 2) * height
# print(area_trapezoid(5, 5, 6))




def area_regular_polygon(sides: int, length: int):
    return sides * (length ** 2) / (4 * math.tan(math.pi / sides))
# print(area_regular_polygon(4, 25))




def area_parallelogram(base: int, height: int):
    return base * height
# print(area_parallelogram(5, 6))
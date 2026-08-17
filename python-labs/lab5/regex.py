import re


def match_a_any_b(s: str):
    pattern = '^a(b*)$'
    if re.match(pattern, s):
        return True
    else:
        return False
# print(match_a_b("ab"))






def match_a_two_or_three_b(s: str):
    pattern = '^a(b{2,3})$'
    if re.match(pattern, s):
        return True
    else:
        return False
# print(match_a_bb("ab"))






def find_lowercase_seq(s: str):
    pattern = '[a-z]+_[a-z]+'
    return re.findall(pattern, s)
# print(find_lowercase_seq("example_text"))







def find_uppercase_seq(s: str):
    pattern = '[A-Z][a-z]+'
    return re.findall(pattern, s)
# print(find_uppercase_seq("ExampleText"))






def match_a_anything_b(s: str):
    pattern = '^a.*b$'
    if re.match(pattern, s):
        return True
    else:
        return False
# print(match_a_anything_b("aab"))







def replace_with_colon(s: str):
    return re.sub(r'[ ,.]', ':', s)
# print(replace_with_colon("This is a test, . :"))






def snake_to_camel(s: str):
    return ''.join(word.title() for word in s.split('_'))
# print(snake_to_camel("this_is_snake_case"))






def split_at_uppercase(s: str):
    return re.findall('[A-Z][^A-Z]*', s)
# print(split_at_uppercase("SplitLetters"))






def insert_spaces(s: str):
    return re.sub(r'([A-Z])', r' \1', s).strip()
# print(insert_spaces("InsertWords"))









def camel_to_snake(s: str):
    return re.sub(r'(?<!^)(?=[A-Z])', '_', s).lower()
# print(camel_to_snake("CamelCase"))
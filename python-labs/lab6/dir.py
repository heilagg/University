import os


def list_dir_files(path: str):
    print("Dir:")
    for i in os.listdir(path):
        if os.path.isdir(os.path.join(path, i)):
            print(i)
    print("\nFiles:")
    for item in os.listdir(path):
        if os.path.isfile(os.path.join(path, item)):
            print(item)
# list_dir_files(".")




def check_access(path: str):
    print("Exists:", os.path.exists(path))
    print("Readable:", os.access(path, os.R_OK))
    print("Writable:", os.access(path, os.W_OK))
    print("Executable:", os.access(path, os.X_OK))
# check_access(".")





def test_path(path: str):
    if os.path.exists(path):
        print("Path exists.")
        print("Filename:", os.path.basename(path))
        print("Directory:", os.path.dirname(path))
    else:
        print("Path does not exist.")
# test_path("sample-data.json")





def count_lines(filename: str):
    try:
        with open(filename, 'r') as file:
            return sum(1 for line in file)
    except:
        return 0
# print(count_lines("sample-data1.json"))





def write_list_to_file(filename: str, lst: list):
    try:
        with open(filename, 'w') as file:
            for item in lst:
                file.write(item + "\n")
    except:
        print("error")
# write_list_to_file("list.txt", ["apple"])






def generate_files():
    for letter in range(65, 91):
        with open(chr(letter) + ".txt", 'w') as file:
            file.write("This is file " + chr(letter) + ".txt")
# generate_files()






def copy_file(src: str, dst: str):
    try:
        with open(src, 'r') as source, open(dst, 'w') as destination:
            destination.write(source.read())
    except:
        print("error")
# copy_file("source.txt", "destination.txt")







def delete_file(path: str):
    if os.path.exists(path) and os.access(path, os.W_OK):
        os.remove(path)
        print("File deleted")
    else:
        print("File does not exist")
delete_file("delete.txt")
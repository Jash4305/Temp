import hashlib

# function to read the hash file and return a dictionary of hash: plain_text pairs
def read_hash_file():
    with open('hash_file.txt') as f:
        hash_dict = {}
        for line in f:
            hash_val, plain_text = line.strip().split(': ')
            hash_dict[hash_val] = plain_text
        return hash_dict

# function to get user input hash value
def get_user_hash():
    user_hash = input("Enter the hash value: ")
    return user_hash

# function to convert hash to plain text using the hash file dictionary
def hash_to_plain_text(user_hash, hash_dict):
    if user_hash in hash_dict:
        return hash_dict[user_hash]
    else:
        return "Hash value not found in hash file"

# read the hash file and create dictionary
hash_dict = read_hash_file()

# get user input hash value
user_hash = get_user_hash()

# get corresponding plain text for the user input hash value
plain_text = hash_to_plain_text(user_hash, hash_dict)

# print the plain text
print("Plain text for hash value " + user_hash + " is: " + plain_text)
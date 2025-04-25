def encryption(text, shift):
    encrypted_text = []
    for char in text:
        if char.isalpha():  # Check if character is a letter
            start = ord('A') if char.isupper() else ord('a')
            shifted = ord(char) - start
            encrypted_char = chr(((shifted + shift) % 26) + start)
            encrypted_text.append(encrypted_char)
        else:
            encrypted_text.append(char)
    return ''.join(encrypted_text)

def decryption(encrypted_text, shift):
    decrypted_text = []
    for char in encrypted_text:
        if char.isalpha():  # Check if character is a letter
            start = ord('A') if char.isupper() else ord('a')
            shifted = ord(char) - start
            decrypted_char = chr(((shifted - shift) % 26) + start)
            decrypted_text.append(decrypted_char)
        else:
            decrypted_text.append(char)
    return ''.join(decrypted_text)

# Input from the user
plain_text = input("Please enter the text you want to encrypt: ")
while True:
    try:
        shift = int(input("Enter a shift value between 0 and 25: "))
        if 0 <= shift <= 25:
            break
        else:
            print("Error: The shift value must be between 0 and 25. Please try again.")
    except ValueError:
        print("Error: Invalid input. Please enter a valid integer between 0 and 25.")

# Encrypt the input text
encrypted_text = encryption(plain_text, shift)
print(f"Encrypted text: {encrypted_text}")

# Decrypt the encrypted text
decrypted_text = decryption(encrypted_text, shift)
print(f"Decrypted text: {decrypted_text}")

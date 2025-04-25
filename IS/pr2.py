import string

def create_cipher_map(key):
    """Create a cipher map from a given key."""
    if len(key) != 26 or len(set(key)) != 26:
        raise ValueError("Key must be a permutation of 26 unique letters.")

    # Create a mapping of plaintext letters to ciphertext letters
    cipher_map = {}
    for i, letter in enumerate(string.ascii_uppercase):
        cipher_map[letter] = key[i]
    return cipher_map

def encrypt(plaintext, cipher_map):
    """Encrypt the plaintext using the cipher map."""
    plaintext = plaintext.upper()
    ciphertext = ''
    for char in plaintext:
        if char in cipher_map:
            ciphertext += cipher_map[char]
        else:
            ciphertext += char  # Preserve non-alphabetic characters
    return ciphertext

def decrypt(ciphertext, reverse_cipher_map):
    """Decrypt the ciphertext using the reverse cipher map."""
    ciphertext = ciphertext.upper()
    plaintext = ''
    for char in ciphertext:
        if char in reverse_cipher_map:
            plaintext += reverse_cipher_map[char]
        else:
            plaintext += char  # Preserve non-alphabetic characters
    return plaintext

def main():
    print("Welcome to the Monoalphabetic Cipher Tool!")
    print("This tool allows you to encrypt and decrypt messages using a substitution cipher.")
    
    # Take user input for the key
    while True:
        key = input("Please enter a 26-letter key, which should be a permutation of the alphabet: ").upper()
        if len(key) == 26 and len(set(key)) == 26:
            break
        else:
            print("Error: The key must be exactly 26 unique letters. Please try again.")

    # Create cipher map and reverse cipher map
    cipher_map = create_cipher_map(key)
    reverse_cipher_map = {v: k for k, v in cipher_map.items()}

    # Take user input for the plaintext
    plaintext = input("Enter the message you wish to encrypt (case-insensitive): ")

    # Encrypt the plaintext
    ciphertext = encrypt(plaintext, cipher_map)
    print(f"Encrypted message: {ciphertext}")

    # Decrypt the ciphertext
    decrypted_text = decrypt(ciphertext, reverse_cipher_map)
    print(f"Decrypted message: {decrypted_text}")

if __name__ == "__main__":
    main()


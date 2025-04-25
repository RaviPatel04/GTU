def find_position(char, key_square):
    """Find the position of a character in the key square."""
    for row_idx, row in enumerate(key_square):
        if char in row:
            return row_idx, row.index(char)
    return None

def preprocess_text(text):
    """Preprocess text by removing non-alphabetic characters and replacing 'J' with 'I'."""
    text = text.upper().replace('J', 'I')
    return ''.join(filter(str.isalpha, text))

def generate_key_square(key):
    """Generate the 5x5 key square for the Playfair cipher."""
    key = key.upper().replace('J', 'I')
    key_square = []
    seen = set()
    
    # Add unique letters from the key
    for char in key:
        if char not in seen and char.isalpha():
            seen.add(char)
            key_square.append(char)
    
    # Add remaining letters of the alphabet
    for char in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
        if char not in seen:
            key_square.append(char)
    
    # Create 5x5 key square
    return [key_square[i:i + 5] for i in range(0, 25, 5)]

def create_digraphs(text):
    """Create digraphs from the processed text."""
    digraphs = []
    i = 0
    while i < len(text):
        if i + 1 < len(text) and text[i] != text[i + 1]:
            digraphs.append([text[i], text[i + 1]])
            i += 2
        else:
            digraphs.append([text[i], 'X'])
            i += 1
    return digraphs

def encrypt_digraphs(digraphs, key_square):
    """Encrypt the digraphs using the Playfair cipher."""
    encrypted_digraphs = []
    for digraph in digraphs:
        row1, col1 = find_position(digraph[0], key_square)
        row2, col2 = find_position(digraph[1], key_square)
        
        if row1 == row2:
            encrypted_digraphs.append([key_square[row1][(col1 + 1) % 5], key_square[row2][(col2 + 1) % 5]])
        elif col1 == col2:
            encrypted_digraphs.append([key_square[(row1 + 1) % 5][col1], key_square[(row2 + 1) % 5][col2]])
        else:
            encrypted_digraphs.append([key_square[row1][col2], key_square[row2][col1]])
    
    return ''.join(''.join(digraph) for digraph in encrypted_digraphs)

# Input from the user
key = input("Please provide a key for encryption: ").strip()
plain_text = input("Enter the message you would like to encrypt: ").strip()

# Preprocess the key and plaintext
key_square = generate_key_square(key)
text = preprocess_text(plain_text)
digraphs = create_digraphs(text)

# Encrypt the digraphs
encrypted_text = encrypt_digraphs(digraphs, key_square)
print(f"Encrypted message: {encrypted_text}")

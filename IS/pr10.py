class SHA1:
    def __init__(self):
        self.h = [0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0]
        self.k = [0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6]
        self.data = b''
        self.length = 0

    def update(self, data):
        self.data += data
        self.length += len(data) * 8
        self._process()

    def digest(self):
        self._pad()
        self._process()
        return b''.join(x.to_bytes(4, 'big') for x in self.h)

    def _process(self):
        for i in range(0, len(self.data), 64):
            chunk = self.data[i:i+64]
            w = [int.from_bytes(chunk[j:j+4], 'big') for j in range(0, 64, 4)]
            w += [0] * (80 - len(w))
           
            for i in range(16, 80):
                w[i] = self._left_rotate(w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16], 1)

            a, b, c, d, e = self.h

            for i in range(80):
                if i < 20:
                    f = (b & c) | (~b & d)
                    k = self.k[0]
                elif i < 40:
                    f = b ^ c ^ d
                    k = self.k[1]
                elif i < 60:
                    f = (b & c) | (b & d) | (c & d)
                    k = self.k[2]
                else:
                    f = b ^ c ^ d
                    k = self.k[3]

                temp = (self._left_rotate(a, 5) + f + e + k + w[i]) & 0xFFFFFFFF
                e = d
                d = c
                c = self._left_rotate(b, 30)
                b = a
                a = temp

            self.h = [(x + y) & 0xFFFFFFFF for x, y in zip(self.h, [a, b, c, d, e])]

    def _pad(self):
        self.data += b'\x80'
        while (len(self.data) * 8) % 512 != 448:
            self.data += b'\x00'
        self.data += (self.length).to_bytes(8, 'big')

    def _left_rotate(self, n, b):
        return ((n << b) | (n >> (32 - b))) & 0xFFFFFFFF

def generate_sha1_hash(input_string):
    sha1 = SHA1()
    sha1.update(input_string.encode('utf-8'))
    return sha1.digest().hex()

if __name__ == "__main__":
    # Take user input for the message with a clear prompt
    input_string = input("Please enter the string you would like to hash with SHA-1: ")
    
    # Generate the SHA-1 hash of the input string
    sha1_hash = generate_sha1_hash(input_string)
    
    # Display the output neatly
    print("\nGenerated SHA-1 Hash:")
    print(f"Input String: {input_string}")
    print(f"SHA-1 Hash: {sha1_hash}")

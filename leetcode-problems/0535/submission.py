class Codec:

    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        """
        num = 0
        r_str=""
        for c in longUrl:
            num = num*128 + ord(c)
        return str(hex(num).rstrip("L"))
        

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        
        num = int(shortUrl, 16)
        ret_s = ""
        print(shortUrl)
        while num != 0:
            c = num %128
            ret_s = str(chr(c)) + ret_s
            num /= 128
        
        return ret_s
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))

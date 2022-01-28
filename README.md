#computer forensic

from Cypto.Cipher import DES3
from Cypto import Random
import base64
def Encrypt(msg):
    black_size = DES3.black_size
    key = Random.new().read(black_size)
    iv = Random.new().read(black_size)
    c = DES3.new(key,DES3.MODE_OFB,iv)
    Encrypted_massage = iv + c.encrypt(msg.encode('ascii'))
    return [key , base64.b64encode(Encrypted_massage)]
def Decrypt(key,Encrypted_massage):
    Encrypted_massage = base64.b64encode(Encrypted_massage)[8:]
    iv = base64.b64encode(Encrypted_massage)[:8]
    d = DES3.new(key,DES3.MODE_OFB,iv)
    return d.decrypt(Encrypted_massage).decode('ascii')

c = Encrypt("hello world")
print(c[0])
print(c[1])
print(Decrypt(c[0],c[1]))

import hashlib
import binascii
from pyDes import des, CBC, PAD_PKCS5 

def des_decrypt(secret_key, s):#DES解碼
    iv = secret_key #DES金鑰
    k = des(secret_key, CBC, iv, pad=None, padmode=PAD_PKCS5)#建立DES跟選擇mode
    de = k.decrypt(binascii.a2b_hex(s), padmode=PAD_PKCS5)#DES解碼
    return de#回傳DES解碼
filename = "1000.txt"

m = hashlib.sha1()#建立sha1模型

# 讀取檔案內容，計算 SHA1 雜湊值
with open(filename, "rb") as f:
  buf = f.read()
  m.update(buf)
  print("訊息: ",buf)

h = m.hexdigest()#計算訊息摘要

#讀取加密訊息摘要檔案
filename2 = "password.txt"
with open(filename2, "rb") as f2:
    password=f2.read()
    

key=input('輸入8位數解密金鑰')#輸入金鑰
de=des_decrypt(key, password)#進行解密
print("訊息摘要: "+h)
print("解密後訊息摘要: "+de.decode('utf-8'))
if h==de.decode('utf-8'):#判斷訊息摘要是否一樣，是否被竄改
    print('訊息沒有遭竄改')
else:
    print('訊息可能遭竄改')


from Crypto.Cipher import PKCS1_OAEP
from Crypto.PublicKey import RSA

def encrypt_data(data: str, public_key: str):
  key = RSA.import_key(public_key)
  cipher = PKCS1_OAEP.new(key)
  encrypted_data = cipher.encrypt(f'{data}'.encode('utf-8'))
  return encrypted_data

def decrypt_data(data: str, private_key: str, passphrase: str = None):
  key = RSA.import_key(private_key, passphrase)
  cipher = PKCS1_OAEP.new(key)
  decrypted_data = cipher.decrypt(data)
  return decrypted_data.decode('utf-8')

def encrypt_object(object, public_key: str):
  public_key = RSA.import_key(public_key).public_key().export_key(format='PEM').decode('utf-8')
  for i in object:
    k = 0
    if i != 'userpublickey':
      if type(object[i]) is list:
        while k < len(object[i]):
          object[i][k] = encrypt_data(object[i][k], public_key)
          k += 1
      elif type(object[i]) is set:
        encrypt_object(object[i], public_key)
      else:
        object[i] = encrypt_data(object[i], public_key)

def decrypt_object(object, private_key: str, passphrase: str = None):
  private_key = RSA.import_key(private_key, passphrase).export_key(format='PEM').decode('utf-8')
  for i in object:
    k = 0
    if i != 'userpublickey':
      if type(object[i]) is list:
        while k < len(object[i]):
          object[i][k] = decrypt_data(object[i][k], private_key)
          k += 1
      elif type(object[i]) is set:
        decrypt_object(object[i], private_key)
      else:
        object[i] = decrypt_data(object[i], private_key)
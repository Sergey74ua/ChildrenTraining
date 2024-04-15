from Crypto.PublicKey import RSA

class App:

  #initial
  def __init__(self):
    self.generate_keys()

  def generate_keys(self):
    key = RSA.generate(1024)
    self.__private_key = key.export_key(format='PEM',
                                        passphrase=None,
                                        pkcs=8,
                                        protection='PBKDF2WithHMAC-SHA512AndAES256-CBC',
                                        prot_params={'iteration_count': 21000})
    self.__public_key = key.public_key().export_key(format='PEM')
    
  @property
  def private_key(self):
    return self.__private_key.decode('utf-8')
  
  @property
  def public_key(self):
    return self.__public_key.decode('utf-8')
import socket
from Crypto.PublicKey import RSA

class User:

  # initial  
  def __init__(self, name: str, passphrase: str):
    self.name = name
    self.ip = self.get_local_ip()
    self.id = self.generate_user_id()
    self.__generate_keys(passphrase)

  # methods
  def __generate_keys(self, passphrase: str):
    key = RSA.generate(1024)
    self.__private_key = key.export_key(format='PEM',
                                      passphrase=passphrase,
                                      pkcs=8,
                                      protection='PBKDF2WithHMAC-SHA512AndAES256-CBC',
                                      prot_params={'iteration_count': 21000})

    self.__public_key = key.public_key().export_key(format='PEM')                                  

  def generate_user_id():
    id = 101 # in progress
    return id
  
  def get_local_ip():
    hostname = socket.gethostname()
    user_ip = socket.gethostbyname(hostname)
    return user_ip
  
  # getters
  @property
  def id(self):
    return self.id

  @property
  def local_ip(self):
    return self.ip

  @property
  def public_key(self):
    return self.__public_key.decode('utf-8')

  @property
  def private_key(self):
    return self.__private_key.decode('utf-8')
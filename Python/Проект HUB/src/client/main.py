import socket
# from modules.app import App
import json
# from modules.objects import encrypt_data

# app = App()
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(('192.168.3.121', 9090))

while True:
  message = input().encode('utf-8')
  sock.send(message)
  if message == b'close conn':
    sock.close()
    break
  rcv = sock.recv(1024)
  print(rcv.decode('utf-8'))

# def main():
#   pass

# if __name__ == '__main__':
#   main()
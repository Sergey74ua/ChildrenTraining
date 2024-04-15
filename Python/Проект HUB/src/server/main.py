import socket
# from modules.objects import decrypt_data
import json
# from modules.app import App

def main():
  # app = App()
  sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  sock.bind(('', 9090))
  sock.listen(1)

  # sock.close()

  # print('connect:', addr)

  conn, addr = sock.accept()
  while True:
    data = conn.recv(1024)
    print(data)
    if not data:
      break
    if data == b'close conn':
      conn.close()
      print('Connection closed')
      break
    conn.send(b"my Answer")

if __name__ == '__main__':
  main()
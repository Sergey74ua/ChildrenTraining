def int32_to_ip(int32):
    ip = ""
    bin32 = bin(int32)[2:].rjust(34, "0")
    for i in range(4):
        ip += str(int(bin32[i*8+2:i*8+10], 2)) + "."
    return ip[:-1]

# тест для локального запуска
num = 675710712
print(num, "- число")
print(int32_to_ip(num), "- IP-адрес")
input()

# более корректный вариант
# def int32_to_ip(int32):
#     return '{}.{}.{}.{}'.format(*int32.to_bytes(4, 'big'))

# или без формата
# def int32_to_ip(int32):
#   return '.'.join([str(int(bin(int32)[2:].zfill(32)[i:i+8], 2)) for i in range(0, 32, 8)])

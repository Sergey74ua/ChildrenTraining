def ip_to_int32(ip):
    int32 = ""
    arr = ip.split(".")
    for i in arr:
        octet = bin(int(i))[2:].rjust(8, "0")
        int32 += octet
    return int("0b" + int32, 2)

# тест для локального запуска
ip = "128.32.10.1" # 2149583361
print(ip, "- IP-адрес")
print(ip_to_int32(ip), "- число")
input()

# более корректный вариант
# addr = ip.split(".")
#     res = int(addr[0]) << 24
#     res += int(addr[1]) << 16
#     res += int(addr[2]) << 8
#     res += int(addr[3])
#     return res

# еще более корректный вариант
# def ip_to_int32(ip):
#     r =""
#     for i in ip.split('.'):
#         r += "{0:08b}".format(int(i))
#     return int(r, 2)

# и еще более корректный вариант
# def ip_to_int32(ip):
#   return int(''.join([(bin(int(x))[2:]).zfill(8) for x in ip.split('.')]),2)

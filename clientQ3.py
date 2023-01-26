import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(("192.168.220.129", 8888))

client.send(b"SEND_WORD")
word = client.recv(1024).decode()
if word != "INVALID_PROMPT":
    print(f"Received word: {word}")
else:
    print("Invalid prompt")
client.close()

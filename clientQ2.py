import socket

def main():
    #create a TCP socket
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    host = '192.168.220.129'
    port = 8889

    #connect to the server
    client_socket.connect((host, port))

    #get temperature in Fahrenheit from the user
    fahrenheit = input("Enter temperature in Fahrenheit: ")

    #send temperature to the server
    client_socket.send(fahrenheit.encode())

    #receive converted temperature from the server
    celsius = client_socket.recv(1024).decode()
    print('Temperature in Celsius:', celsius)

    #close socket
    client_socket.close()

if __name__ == '__main__':
   main()

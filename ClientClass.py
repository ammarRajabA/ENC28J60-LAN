from socket import *

class client:
    def __init__(self,ip,port):
        self.mySocket = socket(AF_INET,SOCK_STREAM)
        self.ip=ip
        self.port=port
    def connect(self):
        try:
            self.mySocket.connect((self.ip,self.port))
        except:
            self.ip=raw_input('error... Try another ip:')
    def output_digital(self,port,pin,bit):
        self.mySocket.send('od')
        self.mySocket.send(port)
        self.mySocket.send(pin)
        self.mySocket.send(bit)
    def read_digital(self,port):
        self.mySocket.send('rd')
        self.mySocket.send(port)
        return self.mySocket.recv(1024)
    def read_analogue(self,pin):
        self.mySocket.send('ra')
        self.mySocket.send(pin)
        b=self.mySocket.recv(1024)
        value=(ord(b[0])+(ord(b[1])<<8))*5/59520.0
        return value
    def write_lcd(self,msg):
        length=len(msg)
        self.mySocket.send('wl')
        self.mySocket.send(chr(length))
        self.mySocket.send(msg)
    def disconnect(self):
        self.mySocket.send('di')



c=client(raw_input('Enter an IP: '),80)
c.connect()



########### example ##############
def list_commands(com):
    print "#####commands list####"
    for option in com:
        print str(com.index(option))+'-'+option.__name__
    print "#############"

def motor_on():
    c.output_digital('B','0','1')
    c.write_lcd('\fMotor is ON')

def motor_off():
    c.output_digital('B','0','0')
    c.write_lcd('\fMotor is OFF')

def voltmeter():
    print c.read_analogue('1')
    c.write_lcd('\fVoltemeter is ON')

def disconnect():
    c.disconnect()

functions=[disconnect,voltmeter,motor_on,motor_off]
i='1'
while i<>'0':
    list_commands(functions)
    i=raw_input('Enter command number: ')
    functions[int(i)]()

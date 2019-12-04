# -*- coding: utf-8 -*-
import paho.mqtt.client as mqtt
import time
import hashlib
import hmac
import random
import json

options = {
    'productKey':'a1bwBiO3ohk',
    'deviceName':'W601_RGB',
    'deviceSecret':'9kMYMQyupdbFrNTu0HUANdFjYmF3fgNV',
    'regionId':'cn-shanghai'
}

HOST = options['productKey'] + '.iot-as-mqtt.'+options['regionId']+'.aliyuncs.com'
PORT = 1883 
PUB_TOPIC = "/sys/" + options['productKey'] + "/" + options['deviceName'] + "/thing/event/property/post";
print PUB_TOPIC

# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    # client.subscribe("the/topic")

# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))

def hmacsha1(key, msg):
    return hmac.new(key.encode(), msg.encode(), hashlib.sha1).hexdigest()

def getAliyunIoTClient():
    timestamp = str(int(time.time()))
    CLIENT_ID = "paho.py|securemode=3,signmethod=hmacsha1,timestamp="+timestamp+"|"
    CONTENT_STR_FORMAT = "clientIdpaho.pydeviceName"+options['deviceName']+"productKey"+options['productKey']+"timestamp"+timestamp
    # set username/password.
    USER_NAME = options['deviceName']+"&"+options['productKey']
    PWD = hmacsha1(options['deviceSecret'],CONTENT_STR_FORMAT)
    client = mqtt.Client(client_id=CLIENT_ID, clean_session=False)
    client.username_pw_set(USER_NAME, PWD)
    return client


if __name__ == '__main__':

    client = getAliyunIoTClient()
    client.on_connect = on_connect
    client.on_message = on_message
    
    client.connect(HOST, 1883, 300)
    
    payload_json = {
        'id': int(time.time()),
        'params': {
            'temperature': random.randint(20, 30),
            'humidity': random.randint(40, 50)
        },
        'method': "thing.event.property.post"
    }
    print('send data to iot server: ' + str(payload_json))

    client.publish(PUB_TOPIC,payload=str(payload_json),qos=1)
    print 'publish down.'
    client.loop_forever()
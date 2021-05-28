from platform import python_branch
import paho.mqtt.client as mqtt
import json 
from collections import defaultdict

def on_connect(client, userdata, flags, rc):
    print("Connected with result code"+str(rc))

    client.subscribe("sda/DHT11")

def totxt(input):
    file = open("ExampleSDA.csv", "a")
    file.write(input + "\n")


def on_message(client, userdata, msg):
    message = msg.payload.decode()
    print(message)
    dictionary = json.loads(message)
    sensor_mapping=defaultdict(lambda: "Unknown sensor")
    sensor_mapping["0xa0"] = "DHT11"
    key=list(dictionary.keys())[0]
    key=sensor_mapping[str(key)]
    value=list(dictionary.values())[0]
    output=f"{key}, {value}"
    totxt(output)

client=mqtt.Client()
client.on_connect=on_connect
client.on_message=on_message

client.connect("broker.hivemq.com",1883,60)

client.loop_forever()
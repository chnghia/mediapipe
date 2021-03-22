import paho.mqtt.client as mqtt
import time
from pynput.keyboard import Key, Controller

keyboard = Controller()

def on_message(client, userdata, message):
    msg = str(message.payload.decode("utf-8"))
    print("received message: " , msg)

    if msg == "KEY_VOLUMEUP":
      keyboard.tap(Key.space)
    if msg == "KEY_1":
      keyboard.press('1')
      time.sleep(0.1)
      keyboard.release('1')
    if msg == "KEY_2":
      keyboard.press('2')
      time.sleep(0.1)
      keyboard.release('2')
    if msg == "KEY_3":
      keyboard.press('3')
      time.sleep(0.1)
      keyboard.release('3')

mqttBroker ="192.168.8.218"

client = mqtt.Client("Client")
client.username_pw_set("nghia", "123456")
client.connect(mqttBroker) 

# client.loop_start()

client.subscribe("#")
client.on_message=on_message 

client.loop_forever(timeout=1.0)

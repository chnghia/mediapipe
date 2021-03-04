import paho.mqtt.client as mqtt
import time
from pynput.keyboard import Key, Controller

keyboard = Controller()

def on_message(client, userdata, message):
    # keyboard.press(Key.space)
    msg = str(message.payload.decode("utf-8"))
    print("received message: " , msg)
    if msg == "KEY_VOLUMEUP":
      keyboard.press(Key.space)
      keyboard.release(Key.space)

mqttBroker ="192.168.8.218"

client = mqtt.Client("Client")
client.username_pw_set("nghia", "123456")
client.connect(mqttBroker) 

client.loop_start()

client.subscribe("handCommander/tv/ir_command")
client.on_message=on_message 

time.sleep(30)
client.loop_stop()
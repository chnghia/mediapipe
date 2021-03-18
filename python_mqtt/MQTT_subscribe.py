import paho.mqtt.client as mqtt
import time
from pynput.keyboard import Key, Controller

keyboard = Controller()
start_time = time.time()

def on_message(client, userdata, message):
    global start_time
    # keyboard.press(Key.space)
    diff = time.time() - start_time
    if diff < 4:
        return

    msg = str(message.payload.decode("utf-8"))
    print("received message: " , msg)
    #diff = time.time() - start_time
    #print(diff)
    #if diff < 3:
    #  return
    
    
    

    if msg == "KEY_VOLUMEUP":
      keyboard.press(Key.space)
      time.sleep(0.1)
      keyboard.release(Key.space)
      start_time = time.time()
    if msg == "KEY_1":
      keyboard.press('1')
      time.sleep(0.1)
      keyboard.release('1')
      start_time = time.time()
    if msg == "KEY_2":
      keyboard.press('2')
      time.sleep(0.1)
      keyboard.release('2')
      start_time = time.time()
    if msg == "KEY_3":
      keyboard.press('3')
      time.sleep(0.1)
      keyboard.release('3')
      start_time = time.time()

mqttBroker ="192.168.8.218"

client = mqtt.Client("Client")
client.username_pw_set("nghia", "123456")
client.connect(mqttBroker) 

# client.loop_start()

client.subscribe("#")
client.on_message=on_message 

client.loop_forever(timeout=1.0)

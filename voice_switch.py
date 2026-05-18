import serial
import speech_recognition as sr

ARDUINO_PORT = 'COM8'

arduino = serial.Serial(ARDUINO_PORT, 9600, timeout=1)

r = sr.Recognizer()

print("Voice Switch Ready!")
print("Say: lights on OR lights off")
print("Press Ctrl + C to stop\n")

while True:

    with sr.Microphone() as source:

        print("Listening...", end=" ", flush=True)

        r.adjust_for_ambient_noise(source, duration=0.3)

        try:

            audio = r.listen(source,
                             timeout=3,
                             phrase_time_limit=3)

            text = r.recognize_google(audio).lower()

            print(f"Heard: {text}")

            if any(w in text for w in
                   ["on", "start", "enable","chalu", "chaloo","chalu karo","chalu karoo"]):

                arduino.write(b'ON\n')

                print("-> Sent ON\n")

            elif any(w in text for w in
                     ["off", "stop", "disable","band","bnd"]):

                arduino.write(b'OFF\n')

                print("-> Sent OFF\n")

            else:

                print("-> Not a valid command\n")

        except sr.WaitTimeoutError:

            print("(silence)\n")

        except sr.UnknownValueError:

            print("Could not understand\n")

        except sr.RequestError as e:

            print(f"Internet Error: {e}\n")
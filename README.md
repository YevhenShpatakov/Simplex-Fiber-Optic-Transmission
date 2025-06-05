# USER MANUAL

## Transmitter

### Connector Description

The fiber optic transmitter is shown in the figure below and includes the following connectors:

1. Power and data connector (USB) – for communication with a computer.  
2. Fiber optic connector with an ST-type socket.

![Fiber Optic Transmitter](Obsluga_folder/Nadajnik%201.jpeg)

### Startup and Configuration

To start the transmitter:

- Connect it to a computer via USB.
- Plug the fiber optic cable into connector no. 2.

In the top-left corner of the Arduino IDE, there is a device selection menu – click it and choose **"Arduino NANO"**, as shown below:

![Device Selection](Obsluga_folder/ide1.png)

Then open the **Serial Monitor**, located in the top bar:

![Opening Serial Monitor](Obsluga_folder/IDE2.png)

Once the Serial Monitor is open, set the following:

- **Baud Rate**: `9600 baud`  
- **Line Ending**: `"NEW LINE"` (`\n` – newline character)

![Baud Rate Selection](images/IDE3.png)

![Line Ending Selection](images/ide5.png)

---

## Receiver

### Connector Description

The fiber optic receiver is shown in the figures below. It includes:

1. Power and data connector (USB).
2. Fiber optic connector with an ST-type socket.
3. LCD display.

![Receiver – Front](Obsluga_folder/Odbiornik1.jpeg) ![Receiver – Back](images/Odbiornik2.jpeg)

### Startup

To start the receiver:

- Connect the other end of the fiber optic cable to connector no. 2.
- Connect the receiver to a power source or computer using a mini USB cable via connector no. 1.

If the receiver starts correctly, the LCD will display:

```
Waiting for a msg.
```

![Receiver Waiting](images/LCD-1.jpeg)

---

## Data Transmission

To send data to the transmitter, you can use any serial communication software (e.g., **PuTTY**), but **Arduino IDE** is recommended.

If the transmitter is correctly configured, the following message will appear:

```
Waiting for input...
```

![Waiting for Input](images/ide4.png)

You can enter your message in the `"Messeage"` text field, shown below:

![Message Input Field](images/Messeage.png)

For example, you can type:

```
Hello World!
```

![Example Transmission](images/hello.png)

The transmitted message will be displayed on the receiver’s LCD:

![Message Displayed](images/LCD-2.jpeg)
